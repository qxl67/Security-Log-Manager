#include <iostream>
#include "LogsTL.hpp"
#include "Event_Log_Filter.hpp"


void setSynthesis_message(const std::string& synthesis_message); {
    this->synthesis_message = synthesis_message; // permet de saisir un message resumant l'entrée du log, le completion du message n'est pas obligatoire
    } 
// Méthode virtuelle pour le parsing (à redéfinir dans les sous-classes)
    //virtual Logs* parseLogsEntree(const std::string& LogsEntree) = 0;

    //FONCTION DE PARSING

    /*Logs::Logs(int id, const std::string& synthesis_message, const std::tm& time_stamp,
           const std::string& source_message, const std::string& host,
           const std::string& user_or_user_context, const std::string& event_type, int processus_id, int level)
    : Id_Logs(id), synthesis_message(synthesis_message), 
    Time_stamp(time_stamp),
    Source_Message(source_message), 
    Host(host),
    User_or_User_Context(user_or_user_context), 
    Event_Type(event_type),
    Processus_Id(processus_id), 
    Level (level){}*/



//Methode pour chercher si le filter_criteria est bon
/*virtual bool Logs::contains(const std::string& criteria) const {

    char timeBuffer[20];         // converti simestamp en string
    strftime(timeBuffer, sizeof(timeBuffer), "%d/%m/%Y %H:%M:%S", &Time_stamp);
    std::string timeStr(timeBuffer);

    // Recherche dans les attributs de la classe Logs
    return (Source_Message.find(criteria) != std::string::npos) ||
           (Host.find(criteria) != std::string::npos) ||
           (User_or_User_Context.find(criteria) != std::string::npos) ||
           (Event_Type.find(criteria) != std::string::npos) ||
           (timeStr.find(criteria) != std::string::npos) ||                      //convertir timstamp en chaine
           (std::to_string(Processus_Id).find(criteria) != std::string::npos);
        }*/

// Méthode pour afficher les logs et s'en servir lors de la création des evenements
// voir si il ne faudra pas commenter les element inutiles du display pour la production des rapports d'événement. 
virtual void displayLogs() const {
    std::cout << "ID : " << Id_Logs << std::endl;
    std::cout << "Date et Heure: " << std::put_time(&Time_stamp, "%d/%m/%Y %H:%M:%S") << std::endl;
    std::cout << "Journal source : " << Source_Log << std::endl;
    std::cout << "Host: " << Host << std::endl;
    std::cout << "User ou User context: " << User_or_User_Context << std::endl;
    std::cout << "Type d'événement: " << Event_Type << std::endl;
    std::cout << "PID: " << Processus_Id << std::endl;
    std::cout << "Niveau de menace: " << Level << std::endl;
    std::cout << "Commentaire: " << synthesis_message << std::endl;
    std::cout << "Message original: " << Source_Message << std::endl; // cet attribut peut etre optionnel
    }


