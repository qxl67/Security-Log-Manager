#include <iostream>

// finir la methode display, ajouter une methode de correction manuelle? 
// est ce que les methodes ne devraient pas etre en .cpp? VIRER LA METHODE POUR LA METTRE DANS UN.CPP
//ajouter le parsing pour que les classes se remplissent bien. 
// Normalement le logs_collector va simplement harmonier et trier basiquement et c'est le logs qui va repartir les elements dans les classe heritiére.
//CREER UN PROTOTYPE DANS LE FICHIER

//Classe mére Logs
class Logs {
protected:
    int Id_Logs;
    std::string synthesis_message;
    std::tm Time_stamp;
    std::string Source_Log;
    std::string Source_Message;
    std::string Host;
    std::string User_or_User_Context; // !Combine les attributs de User et User_contexte!
    std::string Event_Type;
    int Processus_Id;
    int Level;   // !verifier si le processus_Id est bien un int!

public: // Permet de creer le constructeur
    Logs(int id, 
    std::string synthesis_message,
    std::tm time_stamp, 
    std::string source_log,
    std::string source_message, 
    std::string host, 
    std::string user_or_user_context, //Combine les attributs de User et User_contexte
    std::string event_type,
    int processus_id,
    int level): // !verifier si le processus_Id est bien un int!
        Id_Logs(id),
        Synthesis_Message(synthesis_message),
        Time_stamp(time_stamp),
        Source_Log(source_log),
        Source_Message(source_message),
        Host(host),
        User_or_User_Context(user_or_user_context),
        Event_Type(event_type),
        Processus_Id(processus_id),
        Level(level) {}
    
    ~Logs(); // Destructeur

    // Getters, determiner quels sont les attributs a utiliser dans l'algo. Ici, ils sont tous en getter, mais on pourrait limiter la selection pour plus de sécurité.
    // on commentera les attributs qu'on utilisera pas
    int getId() const { return Id_Logs; }
    std::tm getTimeStamp() const { return Time_stamp; }
    std::string getSourceLog() const { return Source_Log; }
    std::string getSourceMessage() const { return Source_Message; }
    std::string getHost() const { return Host; }
    std::string getUserOrUserContext() const { return User_or_User_Context; }
    std::string getEventType() const { return Event_Type; }
    int getProcessusId() const { return Processus_Id; }
    int getLevel() const { return Level; }
    

    //INCERTITUDE DE LA SUITE A PARTIR DE LA. AJOUTER LES METHODES NECESSAIRES

     // Setters (si nécessaire)
    void setSynthesis_message(const std::string& synthesis_message); 
    // permet de saisir un message resumant l'entrée du log, le completion du message n'est pas obligatoire

    // Prototype pour le parsing (à redéfinir dans les sous-classes)
    virtual Logs* parseLogsEntree(const std::string& LogsEntree) = 0;
    //!DEFINIR LA FONCTION DE PARSE!

    // Prototype pour afficher les logs
    virtual void displayLogs() const;

    // Méthodes pour appliquer les filtres // A VERIFIER
    std::vector<LogEntry> applyFilter(const Event_Log_Filter& filter) const;
    std::vector<LogEntry> sortLogs(const Event_Log_Filter& filter) const;
    std::vector<LogEntry> orderLogs(const Event_Log_Filter& filter) const;

};
