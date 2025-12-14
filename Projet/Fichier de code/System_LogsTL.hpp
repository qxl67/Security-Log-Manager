#include "LogsTL.hpp"
#include <iostream>

//Classe fille System_Logs
class System_Logs : public Logs {
protected:
    std::string Processus_name;
    std::string Severity;

public:
System_Logs(int id,
    std::string synthesis_message,
    std::tm time_stamp,
    std::string source_message,
    std::string host,
    int processus_id,
    int level,
    std::string event_type,
    std::string processus_name,
    std::string user_or_user_context,
    std::string severity)
    : Logs(id, synthesis_message, time_stamp, source_message, host, user_or_user_context, event_type, processus_id, level),
      Processus_name(processus_name),
      Severity(severity) {}

    // Getters, determiner quels sont les attributs a utiliser dans l'algo. Ici, ils sont tous en getter, mais on pourrait limiter la selection pour plus de sécurité.
    // on commentera les logs qu'on utilisera pas
    std::string getEventID() const { return Event_ID; }
    std::string getLogonType() const { return Logon_Type; }

    // Méthode de parsing a ajouter

    // Prototype pour afficher
    void displayLogs() const override;
};