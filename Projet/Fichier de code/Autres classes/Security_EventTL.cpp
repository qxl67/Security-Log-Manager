#include <iostream>
#include "Event_Log_Filter.hpp"
#include "Security_EventTL.hpp"


// Fonction pour convertir EventGravity en string
/*std::string Security_Event::eventGravityToString(EventGravity gravity) const {
    switch (gravity) {
        case EventGravity::HIGH:   return "HIGH";
        case EventGravity::MEDIUM: return "MEDIUM";
        case EventGravity::LOW:    return "LOW";
        default:                   return "";
    }
}

// Méthode pour vérifier si un critère est présent dans les attributs (lors de la recherche du Event_Log_filter)
bool Security_Event::contains(const std::string& criteria) const {

    char timeBuffer[20];        // converti simestamp en string
    strftime(timeBuffer, sizeof(timeBuffer), "%d/%m/%Y %H:%M:%S", &Time_stamp);
    std::string timeStr(timeBuffer);

    for (const auto& log : Associated_Logs) { // permet de recherche dans le vecteur des logs associés.
    if (log && log->contains(criteria)) {
        return true;
        }
    }
    // Recherche dans les attributs de la classe Security_EventTL
    return (Description.find(criteria) != std::string::npos) ||
           (eventGravityToString(Event_Gravity).find(criteria) != std::string::npos) ||
           (timeStr.find(criteria) != std::string::npos);   
        }