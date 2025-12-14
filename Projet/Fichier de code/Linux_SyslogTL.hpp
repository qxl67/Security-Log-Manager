#include "LogsTL.hpp"
#include <iostream>

//Classe Linux_Syslog
class Linux_Syslog : public System_Logs {
protected:
    std::string Facility;
    std::string Priority;
    std::string Syslog_Tag;
    std::string Program;
    std::string Processus_Id_Str;

public:
    Linux_Syslog(int id, 
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
    std::string facility, 
    std::string priority, 
    std::string syslog_tag, 
    std::string program,
    std::string processus_id_str): 
        System_Logs(id, synthesis_message, time_stamp, source_message, host, processus_id, level, event_type, processus_name, user_context, severity),
        Facility(facility), 
        Priority(priority), 
        Syslog_Tag(syslog_tag), 
        Program(program), 
        Processus_Id_Str(processus_id_str) {}

    // Getters, determiner quels sont les attributs a utiliser dans l'algo. Ici, ils sont tous en getter, mais on pourrait limiter la selection pour plus de sécurité.
    // on commentera les logs qu'on utilisera pas
    std::string getFacility() const { return Facility; }
    std::string getPriority() const { return Priority; }
    std::string getSyslogTag() const { return Syslog_Tag; }
    std::string getProgram() const { return Program; }
    std::string getProcessusIdStr() const { return Processus_Id_Str; }

    // Méthode de parsing a ajouter

    //Prototype pour afficher
    void displayLogs() const override;
};