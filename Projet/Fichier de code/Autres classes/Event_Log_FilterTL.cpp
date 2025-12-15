#include "Event_Log_FilterTL.hpp"
#include <iostream>


//VERIFIER CE CODE

// Méthode pour appliquer le filtre sur une liste de logs
std::vector<std::string> Event_Log_Filter::applyFilter(const std::vector<std::string>& logs) const {
    std::vector<std::string> filtered_logs;
    if (Filter_Criteria.empty()) {
        return logs; // Si le critère de filtre est vide, retourner tous les logs
    }
    for (const auto& log : logs) {
        if (log.find(Filter_Criteria) != std::string::npos) {
            filtered_logs.push_back(log);
        }
    }
    return filtered_logs;
}

// Méthode pour trier les logs
std::vector<std::string> Event_Log_Filter::sortLogs(std::vector<std::string> logs) const {
    if (Sort_By == SortBy::DATE_HEURE) {
        // Tri par date/heure (simplifié ici, suppose que les logs commencent par une date/heure)
        std::sort(logs.begin(), logs.end());
    }
    return logs;
}





//préciser l'exeption en cas de recherche non fructueuse : mettre un message de non trouvaille
//BIEN ORGANISER LA SAISIE DU FILTRE DANS LE MAIN