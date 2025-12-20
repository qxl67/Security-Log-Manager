//Ajouter les includes qui manque, les #ifndef #define, #endif
#include <iostream>
#include "NewEvent_Log_Filter.hpp" //intégration pour le filtrage pouvant s'appliquer sur les Security_Event
#include "NewSecurity_EventTL.hpp"

//CODE ECRIT A LA MAIN PUIS CORRIGÉ/OPTIMISÉ PAR IA

struct Connection_Attempt{                  
        int Attempt_count;
        std::time_t Last_Attempt_time;
        };

bool delay(std::time_t First_Time, std::time_t Last_Time, int Max_Time) {
    return std::difftime(Last_Time, First_Time) <= Max_Time;      // regler pour un écart de 5 sec entre chaque tentative, attemtion Max_Time renvera toujours des valeurs en seconde
}

void Logs_Analyzer(const Logs& Log, const Windows_Security_Logs& WSecL, const Windows_System_Logs& WSysL, const Linux_Syslog& LSys, const Linux_Secure& LSec ){                //POUR L'ANALYSE ON VA SEULEMENT PRENDRE LE NOMBRE LIMITÉ DATTRIBUT NECESSAIRE A LA DETECTION DE NOS DEUX TYPES DATTTAQUE
    //Attributs de Logs   
    int Id_Logs_Analyzer = Log.getId();                                //Utile pour creer le vecteur contenant les id des logs liés a l'événement suspect
    int Processus_Analyzer = Log.getProcessusId();

    //Attributs utilisés de Linux_Secure
    std::string Acion_Amalyzer = LSec.getAction();
    std::string Severity_Analyzer = LSec.getSeverity();          //Utilise pour attribuer l`event_gravity
    std::string Message_Analyzer = LSec.getMessage(); 
    std::string User_Analyzer = Lsec.getUser()  

    //Attributs utilisés Linux_Syslog
        //Aucun attributs implémentés pour la demonstration

    //Attributs utilisés de Windows_Security_Logs
        //Aucun attributs implémentés pour la demonstration

    //Attributs utilisés de Windows_System_Logs
        

    //ALGO DE DETECTION D'ATTAQUE BRUTEFORCE SUR LOG LINUX
        //faudra t.il ajouter boucle dans le main pour analyser les entrée des logs un a un

    static std::map<std::string, Connection_Attempt> Attempt;          //map permet de creer un dictionnaire associant une IP au caracteristique d'une tentative de connection. On est en variable static pour eviter de reinitialiser la variable a chaque fois.
    static std::map<std::string, std::time_t> Save_Attempt_time;
    std::string Event_Description;                                         //Event_Description servira a assembler nos informations d'evenement


    if (LSec.getAction() != "login_failed") {               // On verifie qu'on a d'abord un cas de login_failed pour continuer
        return;
    }
    
    std::string Source_IP_Analyzer = LSec.getSourceIP();      //On recupére les attributs utiles pour mener l'analyse des attaques bruteforce
    std::time_t CurrentTime_Analyzer = Log.getTimeStamp();                    

    if (Attempt.find(Source_IP_Analyzer) == Attempt.end()) {        //On enregistre la premiere tentative echoué avec son IP et son time stamp
        Attempt[Source_IP_Analyzer] = {1, CurrentTime_Analyzer};
        Save_Attempt_time[Source_IP_Analyzer] = CurrentTime_Analyzer;
        return;
    }

    Connection_Attempt& Attempt_2 = Attempt[Source_IP_Analyzer];    

    if (delay(Attempt_2.Last_Attempt_time, CurrentTime_Analyzer, 5)) {
        Attempt_2.Attempt_count++;
        if (Attempt_2.Attempt_count >= 3) {
            Event_Description = "ALERTE: Suspicion d'attaque par brute-force \n";
            Event_Description += "IP Source: " + Source_IP_Analyzer + "\n";
            Event_Description += "Nombre de tentatives: " + std::to_string(Attempt_2.Attempt_count) + "\n";
            Event_Description += "Tentatives enregistrées entre: " + std::to_string(Save_Attempt_time[Source_IP_Analyzer]) + "et" + std::to_string(Attempt_2.Last_Attempt_time)  + "\n";
            Event_Description += "Utilisateur: " + LSec.getUser() + "\n";
            Event_Description += "Action: " + LSec.getAction() + "\n";
            Event_Description += "Sévérité: " + LSec.getSeverity() + "\n";

            std::cout << Event_Description << std::endl;            // Affichage du message d'alerte dans le terminal

            
            //COMPLETER LE CODE POUR REMPLIR LES ATTRIBUTS DE LA CLASSE SECURITY_EVENT


            Attempt.erase(Source_IP_Analyzer);          // Reset après alerte
            return;
        }
    }
    else {
        Attempt[Source_IP_Analyzer] = {1, CurrentTime_Analyzer};  //Si le delay est depassé on reset l'enregistrement des tentatives
        return;
    }

    // Mise à jour du dernier timestamp
    Attempt_2.Last_Attempt_time = CurrentTime_Analyzer;
}



