#include "Event_Log_Filter.hpp"
#include <vector>

/*std::vector<Logs*> Event_Log_Filter::applyFilter(const std::vector<Logs*>& logs) const {
    std::vector<Logs*> filteredLogs;

    for (const auto& log : logs) {
        if (Filter_Criteria.empty() || log->contains(Filter_Criteria)) {
            filteredLogs.push_back(log);
        }
    }

    return filteredLogs;
}*/

//préciser l'exeption en cas de recherche non fructueuse : mettre un message de non trouvaille
//BIEN ORGANISER LA SAISIE DU FILTRE DANS LE MAIN