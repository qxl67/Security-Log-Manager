//Ajouter les includes qui manque, les #ifndef #define, #endif
#include <iostream>
#include <ctime>
#include <map>
#include "NewEvent_Log_Filter.hpp" //intégration pour le filtrage pouvant s'appliquer sur les Security_Event
#include "NewSecurity_EventTL.hpp"

//CODE ECRIT A LA MAIN PUIS CORRIGÉ/OPTIMISÉ PAR IA

//APPEL ET UTILISATION DE LA METHODE DE CREATION D'ID DE TOM POUR DONNER UN ID UNIQUE A CHAQUE SECURITY_EVENT

struct Connection_Attempt{                  
        int Attempt_count;
        std::time_t Last_Attempt_time;
        };

bool Security_Event::delay(std::time_t First_Time, std::time_t Last_Time, int Max_Time) {
    return std::difftime(Last_Time, First_Time) <= Max_Time;      // regler pour un écart de 5 sec entre chaque tentative, attemtion Max_Time renvera toujours des valeurs en seconde
}

void Security_Event::Logs_Analyzer(const Logs& Log, const Windows_Security_Logs& WSecL, const Windows_System_Logs& WSysL, const Linux_Syslog& LSys, const Linux_Secure& LSec, Security_Event& Export_event){                //POUR L'ANALYSE ON VA SEULEMENT PRENDRE LE NOMBRE LIMITÉ DATTRIBUT NECESSAIRE A LA DETECTION DE NOS DEUX TYPES DATTTAQUE
    //Attributs de Logs   
    int Id_Logs_Analyzer = Log.getId();                                //Utile pour creer le vecteur contenant les id des logs liés a l'événement suspect
    int Processus_Analyzer = Log.getProcessusId();
    std::time_t CurrentTime_Analyzer = Log.getTimeStamp();

    //Attributs utilisés de Linux_Secure
    std::string Action_Analyzer = LSec.getAction();
    std::string Source_IP_Analyzer = LSec.getSourceIP();      //On recupére les attributs utiles pour mener l'analyse des attaques bruteforce
    std::string User_Analyzer = LSec.getUser();  
    //std::string Message_Analyzer = LSec.getMessage();   // Utilise pour l'analyse du SCAN

    //Attributs utilisés Linux_Syslog
        //Aucun attributs implémentés pour la demonstration

    //Attributs utilisés de Windows_Security_Logs
        //Aucun attributs implémentés pour la demonstration

    //Attributs utilisés de Windows_System_Logs
        

    //ALGO DE DETECTION D'ATTAQUE BRUTEFORCE SUR LOG LINUX
        //Il faudra ajouter boucle dans le main pour analyser les entrée des logs un a un

        //L'algo compte le nombre de tentative de connexion d'une IP et compare l'espacement entre ces connexion via le time_stamp.
        //Aprés 3 tentatives de connexion espacées de 5 secondes, une alerte d'evenement de sécurité est produite. 

    static std::map<std::string, Connection_Attempt> Attempt;          //map permet de creer un dictionnaire associant une IP au caracteristique d'une tentative de connection. On est en variable static pour eviter de reinitialiser la variable a chaque fois.
    static std::map<std::string, std::vector<int>> Log_ids;
    static std::map<std::string, std::time_t> Save_Attempt_time;
    std::string Event_Description;                                         //Event_Description servira a assembler nos informations d'evenement


    if (LSec.getAction() != "login_failed") {               // On verifie qu'on a d'abord un cas de login_failed pour continuer
        return;
    }     
    
    Log_ids[Source_IP_Analyzer].push_back(Id_Logs_Analyzer);          //On stocke l'ID pour le vecteur

    if (Attempt.find(Source_IP_Analyzer) == Attempt.end()) {        //On enregistre la premiere tentative echoué avec son IP et son time stamp
        Attempt[Source_IP_Analyzer] = {1, CurrentTime_Analyzer};
        Save_Attempt_time[Source_IP_Analyzer] = CurrentTime_Analyzer;
        return;
    }

    Connection_Attempt& Attempt_2 = Attempt[Source_IP_Analyzer];    

    if (delay(Attempt_2.Last_Attempt_time, CurrentTime_Analyzer, 30)) {   // espacement max fixé a 30 seconde entre les tentative de bruteforce
        Attempt_2.Attempt_count++;

        if (Attempt_2.Attempt_count >= 3) {
            Event_Description = "ALERTE: Suspicion d'attaque par brute-force concernant le processus " + std::to_string(Processus_Analyzer) + "\n";
            Event_Description += "IP Source: " + Source_IP_Analyzer + "\n";
            Event_Description += "Nombre de tentatives: " + std::to_string(Attempt_2.Attempt_count) + "\n";
            Event_Description += "Tentatives enregistrées entre: " + std::to_string(Save_Attempt_time[Source_IP_Analyzer]) + "et" + std::to_string(Attempt_2.Last_Attempt_time)  + "\n";
            Event_Description += "Utilisateur: " + User_Analyzer + "\n";
            Event_Description += "Action: " + Action_Amalyzer + "\n";

            std::cout << Event_Description << std::endl;            // Affichage du message d'alerte dans le terminal

            int Id_Security_Event = /*ID GENERÉ PAR L'ALGO DE TOM*/;   //REMPLIR LA CLASSE AVEC L'ID STATIC GENERÉ PAR L'ALGO DE TOM
            Security_Event::EventType Event_Type = Security_Event::EventType::BRUTEFORCE; 
            Security_Event::EventGravity Event_Gravity = Security_Event::EventGravity::HIGH;           //On attribut a l'attaque par bruteforce une priorité elevée compte tenu de nos critéres d,analyse
            std::vector<int> Associated_Logs = Log_ids[Source_IP_Analyzer];
            std::time_t Event_Time = std::time(nullptr);  //On enregistre le time_stamp du moment de l'analyse

            Export_event = Security_Event(               //On rempli notre objet avec les valeurs 
                Id_Security_Event,
                Event_Type,
                Event_Description,
                Event_Gravity,
                Associated_Logs,
                Event_Time
            );

            Log_ids.erase(Source_IP_Analyzer);
            Attempt.erase(Source_IP_Analyzer);          // Reset après alerte
            return;
        }
    }
    else {
        Attempt[Source_IP_Analyzer] = {1, CurrentTime_Analyzer};  //Si le delay est depassé on reset l'enregistrement des tentatives
        Log_ids[Source_IP_Analyzer].clear();
        Log_ids[Source_IP_Analyzer].push_back(Id_Logs_Analyzer);
        Save_Attempt_time[Source_IP_Analyzer] = CurrentTime_Analyzer;
        
        return;
    }

    // Mise à jour du dernier timestamp
    Attempt_2.Last_Attempt_time = CurrentTime_Analyzer;
    return;


    //CREER L'ALGO DES ATTAQUE PAR SCAN

}


//Proposer d'archiver le document


    

