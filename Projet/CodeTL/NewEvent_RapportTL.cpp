//Ajouter les includes qui manque, les #ifndef #define, #endif
#include "NewEvent_RapportTL.hpp"
#include <vector>
#include <set>
#include <ctime>
#include <iostream>

bool Event_Rapport::delay(std::time_t First_Time, std::time_t Last_Time, int Max_Time) {
    return std::difftime(Last_Time, First_Time) <= Max_Time;      // regler pour un écart de 5 sec entre chaque tentative, attemtion Max_Time renvera toujours des valeurs en seconde
}

//CREER LA FONCTION POUR APPELER L'ALGO

//implementer la methode d'ID de Tom pour donner un ID aux rapport

std::vector<Event_Rapport> Event_Rapport::createRapport(std::vector<Security_Event*>& events) {
    std::vector<Event_Rapport> rapports;
    std::set<Security_Event*> already_used;
    //int report_id = 1;

    for (size_t i = 0; i < events.size(); ++i) {            // size_t est choisi pour pouvoir stocker la taille maximale théorique d'un tableau ou d'un objet
        Security_Event* ref = events[i];

        if (already_used.count(ref))
            continue;

        std::vector<Security_Event*> correlated_events;
        correlated_events.push_back(ref);
        std::time_t last_time = ref->getTimeStamp();  // On utilise une fenetre glissante pour que les evenement proches, mais en dehors de la fenetre d,analyse soient quand meme affiliés au meme evenement

        for (size_t j = i + 1; j < events.size(); ++j) {
            Security_Event* candidate = events[j];

            if (already_used.count(candidate)) continue;

            // On ne corrèle que si c'est le même type
            if (candidate->getEventType() != ref->getEventType()) continue;

            // On ne corrèle que si c'est dans la fenêtre de temps
            if (!delay(last_time, candidate->getTimeStamp(), 30)) continue;         // délais fixé a 30 secondes pour associer les evenements de nature similaires
            
            correlated_events.push_back(candidate);
            last_time = candidate->getTimeStamp();
        }

        // Crée un rapport seulement si corrélation significative (>=2 événements)
        if (correlated_events.size() >= 2) {
            // Construire le texte de recommandation
            std::string event_type_str;
            Security_Event::EventType type = ref->getEventType();
            Event_Rapport::EventPriority rapport_priority = Event_Rapport::EventPriority::UNKNOWN;

            if (type == Security_Event::EventType::BRUTEFORCE) {
                event_type_str = "Brute Force";
                rapport_priority= Event_Rapport::EventPriority::IMMEDIATE; // DANS NOTRE CAS, LE BRUTE EST ASSOCIÉ A UNE PRIORITÉ IMMEDIATE
            } else if (type == Security_Event::EventType::SCAN) {
                event_type_str = "Scan";
            } else {
                event_type_str = "Autre";
            }
            
            std::string Recommendation;
            Recommendation += "Corrélation de sécurité détectée \n";
            Recommendation += "Type d'événements detecté: " + event_type_str + "\n";
            Recommendation += "Événements corrélés : " + std::to_string(correlated_events.size()) + "\n";
            Recommendation += "IDs des événements associés : ";

            for (auto* ev : correlated_events) {
                Recommendation += std::to_string(ev->getIdSecurityEvent()) + " ";
                already_used.insert(ev);  // Marquer l'événement comme utilisé
            }

            // Collecter tous les logs associés
            std::vector<int> associated_logs;
            std::time_t Rapport_Time = std::time(nullptr);

            for (auto* ev : correlated_events) {
                const auto& log_ids = ev->getAssociatedLogIds();
                associated_logs.insert(associated_logs.end(), log_ids.begin(), log_ids.end());
            }

            // Créer le rapport
            Event_Rapport rapport(
                //report_id++,              //implementer la methode d'ID de Tom pour donner un ID aux rapport
                Recommendation,
                rapport_priority,
                correlated_events,
                associated_logs,
                Rapport_Time
            );

            rapports.push_back(rapport);
        }
    }

    return rapports;
}

//Proposer d'archiver le document
