#include "LogsTL.hpp"
#include <iostream>

//Classe Linux_Secure
class Linux_Secure : public Security_Logs {
protected:
    std::string Service;
    std::string Facility;
    std::string Priority;
    std::string Command;
    std::string Terminal;

public:
    Linux_Secure(int id, 
    std::string synthesis_message,
    std::tm time_stamp,
    std::string source_log, 
    std::string source_message, 
    std::string host, 
    int processus_id,
    int level,
    std::string user_or_user_context, 
    std::string ip_adress, 
    std::string event_type, 
    std::string status,
    std::string session_id, 
    std::string fail_reason, 
    std::string service, 
    std::string facility,
    std::string priority, 
    std::string command, 
    std::string terminal): 
        Security_Logs(id, synthesis_message, time_stamp, source_log, source_message, host, processus_id, level, user, ip_adress, event_type, status, session_id, fail_reason),
        Service(service), 
        Facility(facility), 
        Priority(priority), 
        Command(command), 
        Terminal(terminal) {}

    // Getters, determiner quels sont les attributs a utiliser dans l'algo. Ici, ils sont tous en getter, mais on pourrait limiter la selection pour plus de sécurité.
    // on commentera les logs qu'on utilisera pas
    std::string getService() const { return Service; }
    std::string getFacility() const { return Facility; }
    std::string getPriority() const { return Priority; }
    std::string getCommand() const { return Command; }
    std::string getTerminal() const { return Terminal; }


    //INCERTITUDE DE LA SUITE A PARTIR DE LA

    // Méthode de parsing a ajouter

    //Prototype pour afficher
    void displayLogs() const override;
};