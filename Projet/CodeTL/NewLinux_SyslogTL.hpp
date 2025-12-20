#include "NewLogsTL.hpp"
#include <iostream>

//Classe Linux_Secure
class Linux_Syslog : public Logs {
protected:
    std::string Hostname;
    std::string Process;
    std::string Severity;
    std::string Message;

public:
    Linux_Syslog(int id, 
    std::string synthesis_message,
    std::time_t time_stamp, 
    std::string source_log,
    std::string source_message, 
    int processus_id,
    std::string hostname, 
    std::string process, 
    std::string severity, 
    std::string message): 
        Logs(id, synthesis_message, time_stamp, source_log, source_message, processus_id),
        Hostname(hostname), 
        Process(process), 
        Severity(severity), 
        Message(message) {}

    // Getters, determiner quels sont les attributs a utiliser dans l'algo. Ici, ils sont tous en getter, mais on pourrait limiter la selection pour plus de sécurité.
    // on commentera les logs qu'on utilisera pas
    std::string getHostname() const { return Hostname; }
    std::string getProcess() const { return Process; }
    std::string getSeverity() const { return Severity; }
    std::string getMessage() const { return Message; }

    //Prototype pour afficher
    void displayLogs() const override;

    //verifier si d'autre methodes sont necessaires a implanter

};

