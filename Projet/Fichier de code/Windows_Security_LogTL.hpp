#include "LogsTL.hpp"
#include <iostream>

//Classe Windows_Security_Log
class Windows_Security_Log : public Security_Logs {
protected:
    std::string Event_ID;
    std::string Logon_Type;
    std::string Account_Domain;
    std::string Object_Name;
    std::string Object_Type;
    std::string Access_Mask;
    std::string Authentication_Package;

public:
    Windows_Security_Log(int id, 
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
    std::string event_id, 
    std::string logon_type,
    std::string account_domain, 
    std::string object_name, 
    std::string object_type,
    std::string access_mask, 
    std::string authentication_package): 
        Security_Logs(id, synthesis_message, time_stamp, source_log, source_message, host, processus_id, level, user, ip_adress, event_type, status, session_id, fail_reason),
        Event_ID(event_id), 
        Logon_Type(logon_type), 
        Account_Domain(account_domain), 
        Object_Name(object_name),
        Object_Type(object_type), 
        Access_Mask(access_mask), 
        Authentication_Package(authentication_package) {}

    // Getters, determiner quels sont les attributs a utiliser dans l'algo. Ici, ils sont tous en getter, mais on pourrait limiter la selection pour plus de sécurité.
    // on commentera les logs qu'on utilisera pas
    std::string getEventID() const { return Event_ID; }
    std::string getLogonType() const { return Logon_Type; }
    std::string getAccountDomain() const { return Account_Domain; }
    std::string getObjectName() const { return Object_Name; }
    std::string getObjectType() const { return Object_Type; }
    std::string getAccessMask() const { return Access_Mask; }
    std::string getAuthenticationPackage() const { return Authentication_Package; }


//INCERTITUDE DE LA SUITE A PARTIR DE LA

    // Méthode de parsing 
 

    // Prototype pour afficher
    void displayLogs() const override;
};