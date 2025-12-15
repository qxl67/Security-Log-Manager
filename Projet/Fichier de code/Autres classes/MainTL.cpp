#include "Event_Log_Filter.hpp"
#include <iostream>

//Fonction de tri du Event_Log_Filter
/*int main() {
// Préparation des logs pour le filtrage
    std::vector<Logs*> logsPtr;
    for (const auto& log : logs) {
        logsPtr.push_back(log.get());
    }

    // Saisie du type de document à rechercher
    int assetTypeChoice;
    std::cout << "Choisissez le type de document à rechercher :\n";
    std::cout << "1. Journaux de sécurité \n";
    std::cout << "2. Évenements de sécurité\n";
    std::cout << "Votre choix : ";
    std::cin >> assetTypeChoice;

    Event_Log_Filter::AssetType assetType;
    if (assetTypeChoice == 1) {
        assetType = Event_Log_Filter::AssetType::LOGS;
    } else if (assetTypeChoice == 2) {
        assetType = Event_Log_Filter::AssetType::SECURITY_EVENT;
    } else {
        std::cout << "Choix invalide. Utilisation de LOGS par défaut.\n";
        assetType = Event_Log_Filter::AssetType::LOGS;
    }

    // Saisie du mot-clé de recherche
    std::string filterCriteria;
    std::cout << "Entrez le mot-clé à rechercher (laisser vide pour afficher tous les logs du type sélectionné) : "; 
    // A AJOUTER préciser qu'on veut aue la recherche de mot s'opére seulement sur un attribut spécifique de la classe logs ou event_logs
    std::cin.ignore(); // Ignorer le retour à la ligne précédent
    std::getline(std::cin, filterCriteria);

    // Création du filtre
    Event_Log_Filter filter(1, assetType, filterCriteria);

    // Application du filtre
    std::vector<Logs*> filteredLogs = filter.applyFilter(logsPtr);

    // Affichage des résultats
    std::cout << "\nRésultats de la recherche :\n";
    if (filteredLogs.empty()) {
        std::cout << "Aucun résultat trouvé.\n";
    } else {
        for (const auto& log : filteredLogs) {
            log->display();
        }
    }

    return 0;
}