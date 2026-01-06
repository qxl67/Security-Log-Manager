#include "Log.hpp"
#include <ctime>
#include <iostream>



Log::Log(int id,
    const int& pid,
    const time_t& time_stamp,
    const std::string& h,
    const std::string& u,
    const std::string& synthesis_message)
    : ID_Log(id),
    PID(pid),
    time_stamp(time_stamp),
    host(h),
    user(u),
    synthesis_message(synthesis_message) {
        // vérifications
    }

time_t Log::getTimeStamp() const {
    return time_stamp;
}

void Log::setSynthesisMessage(const std::string& message) {
    synthesis_message = message;
}

std::string Log::getUser() const {
    return user;
}

int Log::getId() const {
    return ID_Log;
}

Log::~Log() {
    // ressources à libérer
}

void Log::afficher() const {
    std::cout << "ID_Log: " << ID_Log << std::endl;
    std::cout << "PID: " << PID << std::endl;
    std::cout << std::ctime(&time_stamp);
    std::cout << "Host: " << host << std::endl;
    std::cout << "User: " << user << std::endl;
    std::cout << "Synthesis Message: " << synthesis_message << std::endl;
}

// Windows_System_Log////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Windows_System_Log::Windows_System_Log(

    const Log& base,

    const std::string& name,
    const std::string& guid,
    const int& event_ID,
    const std::string& version,
    const std::string& level,
    const std::string& task,
    const std::string& opcode,
    const std::string& keywords,
    const std::string& eventRecordID,
    const std::string& activityID,
    const std::string& threadID,
    const std::string& channel,
    const std::string& eventData)
    : Log(base),
    name(name),
    guid(guid),
    event_ID(event_ID),
    version(version),
    level(level),
    task(task),
    opcode(opcode),
    keywords(keywords),
    eventRecordID(eventRecordID),
    activityID(activityID),
    threadID(threadID),
    channel(channel),
    eventData(eventData)    {
        // vérifications
    }

Windows_System_Log::~Windows_System_Log() {
    // ressources à libérer
}

void Windows_System_Log::afficher() const {
    // Appel de l'affichage de la classe mère
    Log::afficher();

    // Affichage spécifique Windows Security
    std::cout << "Name: " << name << std::endl;
    std::cout << "GUID: " << guid << std::endl;
    std::cout << "Event ID: " << event_ID << std::endl;
    std::cout << "Version: " << version << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Task: " << task << std::endl;
    std::cout << "Opcode: " << opcode << std::endl;
    std::cout << "Keywords: " << keywords << std::endl;
    std::cout << "EventRecordID: " << eventRecordID << std::endl;
    std::cout << "ActivityID: " << activityID << std::endl;
    std::cout << "ThreadID: " << threadID << std::endl;
    std::cout << "Channel: " << channel << std::endl;
    std::cout << "Event Data: " << eventData << std::endl;
}

// Windows_Security_Log////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Windows_Security_Log::Windows_Security_Log(

    const Log& base,
    //Au dessus attributs de Log, en dessous attributs de la classe héritière
    const std::string& name,
    const std::string& guid,
    const int& event_ID,
    const std::string& version,
    const std::string& level,
    const std::string& task,
    const std::string& opcode,
    const std::string& keywords,
    const std::string& eventRecordID,
    const std::string& activityID,
    const std::string& threadID,
    const std::string& channel,
    const std::string& eventData)
    : Log(base),
    name(name),
    guid(guid),
    event_ID(event_ID),
    version(version),
    level(level),
    task(task),
    opcode(opcode),
    keywords(keywords),
    eventRecordID(eventRecordID),
    activityID(activityID),
    threadID(threadID),
    channel(channel),
    eventData(eventData)    {
        // vérifications
    }

std::string Windows_Security_Log::getKeywords() const {
    return keywords;
}

Windows_Security_Log::~Windows_Security_Log() {
    // ressources à libérer
}

void Windows_Security_Log::afficher() const {
    // Appel de l'affichage de la classe mère
    Log::afficher();

    // Affichage spécifique Windows Security
    std::cout << "Name: " << name << std::endl;
    std::cout << "GUID: " << guid << std::endl;
    std::cout << "Event ID: " << event_ID << std::endl;
    std::cout << "Version: " << version << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Task: " << task << std::endl;
    std::cout << "Opcode: " << opcode << std::endl;
    std::cout << "Keywords: " << keywords << std::endl;
    std::cout << "EventRecordID: " << eventRecordID << std::endl;
    std::cout << "ActivityID: " << activityID << std::endl;
    std::cout << "ThreadID: " << threadID << std::endl;
    std::cout << "Channel: " << channel << std::endl;
    std::cout << "Event Data: " << eventData << std::endl;
}

// Linux_System_Log////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Linux_System_Log::Linux_System_Log(
    const Log& base,
    //Au dessus attributs de Log, en dessous attributs de la classe héritière
    const std::string& process,
    const std::string& severity,
    const std::string& message)
    : Log(base),
    process(process),
    severity(severity),
    message(message)    {
        // vérifications
    }

Linux_System_Log::~Linux_System_Log() {
    // ressources à libérer
}

void Linux_System_Log::afficher() const {
    // Appel de l'affichage de la classe mère
    Log::afficher();

    // Affichage spécifique Windows Security
    std::cout << "Process: " << process << std::endl;
    std::cout << "Severity: " << severity << std::endl;
    std::cout << "Message: " << message << std::endl;
}

// Linux_Security_Log////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Linux_Security_Log::Linux_Security_Log(
    const Log& base,
    //Au dessus attributs de Log, en dessous attributs de la classe héritière
    const std::string& process,
    const std::string& severity,
    const std::string& action,
    const std::string& source_ip,
    const std::string& message)
    : Log(base),
    process(process),
    severity(severity),
    action(action),
    source_ip(source_ip),
    message(message)    {
        // vérifications
    }

std::string Linux_Security_Log::getAction() const {
    return action;
}

Linux_Security_Log::~Linux_Security_Log() {
    // ressources à libérer
}

void Linux_Security_Log::afficher() const {
    // Appel de l'affichage de la classe mère
    Log::afficher();

    // Affichage spécifique Windows Security
    std::cout << "Process: " << process << std::endl;
    std::cout << "Severity: " << severity << std::endl;
    std::cout << "Action: " << action << std::endl;
    std::cout << "Soucrce IP: " << source_ip << std::endl;
    std::cout << "Message: " << message << std::endl;
}