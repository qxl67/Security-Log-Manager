#include <iostream>

//Classe mére Logs
class Logs {
protected:
    int Id_Logs;
    std::tm Time_stamp;
    std::string Source_Message;
    std::string Host;
    std::string User_or_User_Context; // !Combine les attributs de User et User_contexte!
    std::string Event_Type;
    int Processus_Id;   // !verifier si le processus_Id est bien un int!

public: // Permet de creer le constructeur
    Logs(int id, 
    std::tm time_stamp, 
    std::string source_message, 
    std::string host, 
    std::string user_or_user_context, //Combine les attributs de User et User_contexte
    std::string event_type,
    int processus_id): // !verifier si le processus_Id est bien un int!
        Id_Logs(id), 
        Time_stamp(time_stamp), 
        Source_Message(source_message), 
        Host(host), 
        Processus_Id(processus_id) {}
    
    ~Logs(); // Destructeur
};

// Classe fille Security_Logs
class Security_Logs : public Logs {
protected:
    std::string Ip_Adress;
    std::string Status;
    std::string Session_Id;
    std::string Fail_Reason;

public:
    Security_Logs(int id, 
    std::tm time_stamp, 
    std::string source_message, 
    std::string host, 
    int processus_id, 
    std::string user_or_user_context, //Combine les attributs de User et User_contexte
    std::string ip_adress,  
    std::string status, 
    std::string session_id, 
    std::string fail_reason): 
        Logs(id, time_stamp, source_message, host, processus_id),
        User(user), 
        Ip_Adress(ip_adress), 
        Event_Type(event_type), 
        Status(status),
        Session_Id(session_id), 
        Fail_Reason(fail_reason) {}
};

//Classe fille System_Logs
class System_Logs : public Logs {
protected:
    std::string Processus_name;
    std::string Severity;

public:
    System_Logs(int id, 
    std::tm time_stamp, 
    std::string source_message, 
    std::string host, 
    int processus_id, 
    std::string event_type, 
    std::string processus_name, 
    std::string user_or_user_context, //Combine les attributs de User et User_contexte
    std::string severity):
        Logs(id, time_stamp, source_message, host, processus_id),
        Event_type(event_type), 
        Processus_name(processus_name), 
        User_Context(user_context), 
        Severity(severity) {}
};

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
    std::tm time_stamp, 
    std::string source_message, 
    std::string host, 
    int processus_id,
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
        Security_Logs(id, time_stamp, source_message, host, processus_id, user, ip_adress, event_type, status, session_id, fail_reason),
        Event_ID(event_id), 
        Logon_Type(logon_type), 
        Account_Domain(account_domain), 
        Object_Name(object_name),
        Object_Type(object_type), 
        Access_Mask(access_mask), 
        Authentication_Package(authentication_package) {}
};

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
    std::tm time_stamp, 
    std::string source_message, 
    std::string host, 
    int processus_id,
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
        Security_Logs(id, time_stamp, source_message, host, processus_id, user, ip_adress, event_type, status, session_id, fail_reason),
        Service(service), 
        Facility(facility), 
        Priority(priority), 
        Command(command), 
        Terminal(terminal) {}
};

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
    std::tm time_stamp, 
    std::string source_message, 
    std::string host, 
    int processus_id,
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
        System_Logs(id, time_stamp, source_message, host, processus_id, event_type, processus_name, user_context, severity),
        Event_ID(event_id), 
        Event_Category(event_category), 
        Log_Name(log_name), 
        Keywords(keywords),
        Task_Category(task_category), 
        Operation_Code(operation_code) {}
};

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
    std::tm time_stamp, 
    std::string source_message, 
    std::string host, 
    int processus_id,
    std::string event_type, 
    std::string processus_name, 
    std::string user_or_user_context, 
    std::string severity,
    std::string facility, 
    std::string priority, 
    std::string syslog_tag, 
    std::string program,
    std::string processus_id_str): 
        System_Logs(id, time_stamp, source_message, host, processus_id, event_type, processus_name, user_context, severity),
        Facility(facility), 
        Priority(priority), 
        Syslog_Tag(syslog_tag), 
        Program(program), 
        Processus_Id_Str(processus_id_str) {}
};

//Classe Linux_Auth_Logs
/*class Linux_Auth_Logs : public Logs {
protected:
    std::string Service_Program;
    std::string User;
    std::string Ip_Adress;
    std::string Port;
    std::string Event_Type;
    std::string Status;
    std::string TTY_Terminal;
    std::string Command;
    std::string Authentication_Method;
    std::string PAM_Module;
    std::string Session_Id;
    std::string Facility;
    std::string Priority;

public:
    Linux_Auth_Logs(int id, 
    std::tm time_stamp, 
    std::string source_message, 
    std::string host, 
    int processus_id,
    std::string service_program, 
    std::string user, 
    std::string ip_adress, 
    std::string port, 
    std::string event_type, 
    std::string status, 
    std::string tty_terminal, 
    std::string command, 
    std::string authentication_method, 
    std::string pam_module, 
    std::string session_id, 
    std::string facility, 
    std::string priority): 
        Logs(id, time_stamp, source_message, host, processus_id),
        Service_Program(service_program), 
        User(user), 
        Ip_Adress(ip_adress), 
        Port(port),
        Event_Type(event_type), 
        Status(status), 
        TTY_Terminal(tty_terminal), 
        Command(command),
        Authentication_Method(authentication_method), 
        PAM_Module(pam_module), 
        Session_Id(session_id),
        Facility(facility), 
        Priority(priority) {}
};*/
