#include "LogsTL.hpp"
#include <iostream>

// Classe fille Security_Logs
class Security_Logs : public Logs {
protected:
    std::string Ip_Adress;
    std::string Status;
    std::string Session_Id;
    std::string Fail_Reason;

public:
Security_Logs(int id,
    std::string synthesis_message,
    std::tm time_stamp,
    std::string source_message,
    std::string host,
    int processus_id,
    int level,
    std::string user_or_user_context, // Combine les attributs de User et User_contexte
    std::string ip_adress,
    std::string status,
    std::string session_id,
    std::string fail_reason)
    : Logs(id, synthesis_message, time_stamp, source_message, host, user_or_user_context, "Security", processus_id, level), // a quoi  sert le securite?
      Ip_Adress(ip_adress),
      Status(status),
      Session_Id(session_id),
      Fail_Reason(fail_reason) {}

    // Getters, determiner quels sont les attributs a utiliser dans l'algo. Ici, ils sont tous en getter, mais on pourrait limiter la selection pour plus de sécurité.
    // on commentera les logs qu'on utilisera pas
    std::string getIpAdress() const { return Ip_Adress; }
    std::string getStatus() const { return Status; }
    std::string getSessionId() const { return Session_Id; }
    std::string getFailReason() const { return Fail_Reason; }


    //INCERTITUDE DE LA SUITE A PARTIR DE LA

    // Méthode de parsing a ajouter

    // Méthode pour afficher
    void displayLogs() const override;

};