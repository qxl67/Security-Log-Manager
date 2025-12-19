//Ajouter les includes qui manque, les #ifndef #define, #endif
#include <iostream>
#include "NewEvent_Log_Filter.hpp"
#include "NewSecurity_EventTL.hpp"


    //CREER UN PROTOTYPE ET SA METHODE POUR DETECTER UNE ATTAQUE = THOMAS S'OCCUPE DE L'ALGO DE DETECTION
        //IL FAUT QUE LES INFOS DES GETTER UTILISÉ DANS L'ALGO DE DETECTION PUISSENT ETRE UTILISÉE POUR REMPLIR LE RAPPORT D'EVENT

void Logs_Analyzer(const Logs& Log, const Windows_Security_Logs& WSecL, const Windows_System_Logs& WSysL, const Linux_Syslog& LSys, const Linux_Secure& LSec ){                //POUR L'ANALYSE ON VA SEULEMENT PRENDRE LE NOMBRE LIMITÉ DATTRIBUT NECESSAIRE A LA DETECTION DE NOS DEUX TYPES DATTTAQUE

    std::string Time_Analyzer = Time_stamp;              
    int Processus_Analyzer = Processus_Id;


    //ALGO DE DETECTION D'ATTAQUE BRUTEFORCE



    //ALGO DE DETECTION DE SCAN





}


void  Security_Event_creation() {}


    //CREER LE PROTOTYPE ET LA METHODE POUR EXPORTER LES EVENT DANS LES ARCHIVES

    //CREER UN PROTOTYPE ET SA METHODE POUR RENPLIR LE VECTEUR associated_log AVEC L'ID DES LOGS DE L'ATTAQUE






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