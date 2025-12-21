//Ajouter les includes qui manque, les #ifndef #define, #endif
#ifndef EVENT_RAPPORT_HPP
#define EVENT_RAPPORT_HPP
#include <vector>
#include <string>
#include <ctime>
#include "Security_Event.hpp"
#include <iostream>

//DANS LE CAS DE NOTRE DEMONSTRATION ON VA CORRELER LES EVENEMENTS DE SÉCURITÉ PAR TYPE, DANS UN DELAIS DONNÉ. 
//CELA CORRESPONDRA AU DEUX TYPE D,ATTAQUE QUE NOUS TRAITONS: PAR BRUTE FORCE ET PAR SCAN

class Event_Rapport {
public:
    enum class EventPriority {
        IMMEDIATE,
        LATER
    };

    // Constructeur de la classe
    Event_Rapport(int id_event_rapport,         
        std::string recommendation,
        EventPriority event_priority,
        std::vector<Security_Event*> associated_event,
        std::vector<int> associated_log_ids,
        std::time_t time_stamp):                               // LE TIME STAMP PEUT ETRE DE TYPE TM (time stamp) OU DE TYPE STRING. PERSO JE RECOMMENDE TIME_STAMP
            Id_Event_Rapport(id_event_rapport),
            Recommendation(recommendation),
            Event_Priority(event_priority),
            Associated_Event(associated_event),
            Associated_Log_Ids(associated_log_ids),
            Time_Stamp(time_stamp) {}

    //Getters de la classe, a commenter selon les besoins
    int getIdEventRapport() const { return Id_Event_Rapport; }
    std::string getRecommendation() const { return Recommendation; }
    EventPriority getEventPriority() const { return Event_Priority; }
    std::vector<Security_Event*> getAssociated_Event() const { return Associated_Event; }
    std::vector<int> getAssociated_Log_Ids() const { return Associated_Log_Ids; }
    std::time_t getTimeStamp() const { return Time_Stamp; }

    //Prototype pour la méthode de delay 
    bool delay(std::time_t First_Time, std::time_t Last_Time, int Max_Time);

    //CREER LE PROTOTYPE ET LA METHODE POUR RECUPERER ET COMPILER LES SECURITY_EVENT DANS UN MEME RAPPORT
    static std::vector<Event_Rapport> createRapport(std::vector<Security_Event*>& events, int time_window_seconds);


    

//CREER LE PROTOTYPE ET LA METHODE POUR EXPORTER LES RAPPORTS DANS LES ARCHIVES
    //L'exportation doit etre possible en tant que telechargement vers un fichier 
    // et l'exportation doit etre possible en direction des archives. Il faudra donc
    // laisser la possibilité de choisir entre les deux lors de l'exportation. 


private:
    int Id_Event_Rapport;
    std::string Recommendation;
    EventPriority Event_Priority;
    std::vector<Security_Event*> Associated_Event;
    std::vector<int> Associated_Log_Ids;
    std::time_t Time_Stamp;

};
#endif