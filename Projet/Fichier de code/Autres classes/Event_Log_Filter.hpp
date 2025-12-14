#include <iostream>

class Logs {
public: 
    enum FilterCriteria {
        EVENT_TYPE,
        HOST,
        PROCESSUS_ID,
        TIME_STAMP,
        USER_OR_USER_CONTEXT,
        SOURCE
    };

    enum class SortBy {
        DATE_HEURE,
        NIVEAU_SEVERITE,
        IP_SOURCE,
        IP_DESTINATION
    };

    enum class OrderBy {
        ASCENDANT,
        DESCENDANT
    };

protected:
    int Id_Filter;
    FilterCriteria Filter_Criteria;
    SortBy Sort_By; 
    OrderBy Order_By;

public: // Permet de creer le constructeur
    Logs(int id, 
    std::string synthesis_message,
    std::tm time_stamp, 
    std::string source_message, 
    std::string host, 
    std::string user_or_user_context, //Combine les attributs de User et User_contexte
    std::string event_type,
    int processus_id,
    int level): // !verifier si le processus_Id est bien un int!
        Id_Logs(id), 
        Time_stamp(time_stamp), 
        Source_Message(source_message), 
        Host(host), 
        Processus_Id(processus_id) {}
    
    ~Logs(); // Destructeur

};