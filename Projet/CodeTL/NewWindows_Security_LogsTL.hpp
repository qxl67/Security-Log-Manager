#include "NewLogsTL.hpp"
#include <iostream>

class Windows_Security_Logs : public Logs {
protected:
    std::string Name;
    std::string GuID;
    int Event_ID;           
    int Version;
    int Level;          //POUR CHAQUE INT AVEC UNE VALEUR QUI A DU SENS, IL FAUDRA QUE LA FONCTION DE DISPLAY TRADUISE LE INT DANS SA SIGNIFICATION PRECISE. 
    int Task;           //VERIFIER QUAND LE INT CODE A UNE SIGNIFICATION  PRECISE
    int Opcode;
    std::string Keywords;
    int EventRecordID;
    int ActivityID;
    int ThreadID;
    std::string Channel;
    std::string Computer;

public:
Windows_Security_Logs(int id, 
    std::string synthesis_message,
    std::time_t time_stamp, 
    std::string source_log,
    std::string source_message, 
    int processus_id,
    std::string name,
    std::string guid,
    int event_ID, 
    int version,
    int level,
    int task,
    int opcode,
    std::string keywords,
    int eventrecordid,
    int activityid,
    int threadid,
    std::string channel,
    std::string computer): 
        Logs(id, synthesis_message, time_stamp, source_log, source_message, processus_id),
        Name(name),
        GuID(guid)
        Event_ID(event_ID)           
        Version(version)
        Level(level)        
        Task(task)           
        Opcode(opcode)
        Keywords(keywords)
        EventRecordID(eventrecordid)
        ActivityID(activityid)
        ThreadID(threadid)
        Channel(channel)
        Computer(computer) {}

    // Getters, determiner quels sont les attributs a utiliser dans l'algo. Ici, ils sont tous en getter, mais on pourrait limiter la selection pour plus de sécurité.
    // on commentera les logs qu'on utilisera pas
    std::string getName() const { return Name; }
    std::string getGuID() const { return GuID; }
    int getEventID() const { return Event_ID; }
    int getVersion() const { return Version; }
    int getLevel() const { return Level; }
    int getTask() const { return Task; }
    int getOpcode() const { return Opcode; }
    std::string getKeywords() const { return Keywords; }
    int getEventRecordID() const { return EventRecordID; }
    int getActivityID() const { return ActivityID; }
    int getThreadID() const { return ThreadID; }
    std::string getChannel() const { return Channel; }
    std::string getComputer() const { return Computer; }

    // Prototype pour afficher
    void displayLogs() const override;

    //verifier si d'autre methodes sont necessaires a implanter

};

