#include "LogsTL.hpp"
#include <iostream>

//Classe Windows_System_Log
class Windows_System_Log : public System_Logs {
protected:
    std::string Event_ID;
    std::string Event_Category;
    std::string Log_Name;
    std::string Keywords;
    std::string Task_Category;
    std::string Operation_Code;

public:
    Windows_System_Log(int id, 
    std::string synthesis_message,
    std::tm time_stamp, 
    std::string source_message, 
    std::string host, 
    int processus_id,
    int level,
    std::string event_type, 
    std::string processus_name, 
    std::string user_or_user_context, 
    std::string severity,
    std::string event_id, 
    std::string event_category, 
    std::string log_name, 
    std::string keywords,
    std::string task_category, 
    std::string operation_code): 
        System_Logs(id, synthesis_message, time_stamp, source_message, host, processus_id, level, event_type, processus_name, user_context, severity),
        Event_ID(event_id), 
        Event_Category(event_category), 
        Log_Name(log_name), 
        Keywords(keywords),
        Task_Category(task_category), 
        Operation_Code(operation_code) {}

    // Getters, determiner quels sont les attributs a utiliser dans l'algo. Ici, ils sont tous en getter, mais on pourrait limiter la selection pour plus de sécurité.
    // on commentera les logs qu'on utilisera pas
    std::string getEventID() const { return Event_ID; }
    std::string getEventCategory() const { return Event_Category; }
    std::string getLogName() const { return Log_Name; }
    std::string getKeywords() const { return Keywords; }
    std::string getTaskCategory() const { return Task_Category; }
    std::string getOperationCode() const { return Operation_Code; }

    //INCERTITUDE DE LA SUITE A PARTIR DE LA

    // Méthode de parsing a ajouter

    //Prototype pour afficher
    void displayLogs() const override;
};