//Ajouter les includes qui manque, les #ifndef #define, #endif

#include <iostream>
#include <vector>
#include <ctime>

class Security_Event {
public:
    enum class EventGravity {
        HIGH,
        MEDIUM,
        LOW
    };

    enum class EventType {          //On ne met que 2 EventType pour notre demonstration, on pourrait en rajouter autant qu'on veut
        BRUTEFORCE,
        SCAN,
        UNKNOWN
    };

    // Constructeur 
    Security_Event(int id_security_event,
        EventType event_type,
        std::string description,                    
        EventGravity event_gravity,
        std::vector<int> associated_log_ids,
        std::time_t time_stamp): 
            Id_Security_Event(id_security_event),
            Event_Type(event_type),
            Description(description),
            Event_Gravity(event_gravity),
            Associated_Log_Ids(associated_log_ids),
            Time_Stamp(time_stamp) {}

    // Getters
    //Getters a commenter selon les besoins (utilisé pour creer le Event_Rapport)
    int getIdSecurityEvent() const { return Id_Security_Event; }
    EventType getEventType() const { return Event_Type; }
    std::string getDescription() const { return Description; }
    EventGravity getEventGravity() const { return Event_Gravity; }
    std::vector<int> getAssociatedLogIds() const { return Associated_Log_Ids; }
    std::time_t getTimeStamp() const { return Time_Stamp; }

    // Setters
    //Setters a utiliser pour completer la classe
    void setIdSecurityEvent(int id) { Id_Security_Event = id; }
    void setEventType(EventType type) { Event_Type = type; }
    void setDescription(const std::string& desc) { Description = desc; }
    void setEventGravity(EventGravity gravity) { Event_Gravity = gravity; }
    void setAssociatedLogIds(const std::vector<int>& logs) { Associated_Log_Ids = logs; }
    void setTimeStamp(const std::time_t tm) { Time_Stamp = tm; }

    //CREER UN PROTOTYPE ET SA METHODE POUR RENPLIR LE VECTEUR associated_log AVEC L'ID DES LOGS DE L'ATTAQUE

    bool delay(std::time_t First_Time, std::time_t Last_Time, int Max_Time);    // regler pour un écart de 5 sec entre chaque tentative, attemtion Max_Time renvera toujours des valeurs en seconde


    //CREER UN PROTOTYPE ET SA METHODE POUR DETECTER UNE ATTAQUE = THOMAS S'OCCUPE DE L'ALGO DE DETECTION
        //IL FAUT QUE LES INFOS DES GETTER UTILISÉ DANS L'ALGO DE DETECTION PUISSENT ETRE UTILISÉE POUR REMPLIR LE RAPPORT D'EVENT

    //CREER LE PROTOTYPE ET LA METHODE POUR EXPORTER LES EVENT DANS LES ARCHIVES

    //CREER UN PROTOTYPE ET SA METHODE POUR RENPLIR LE VECTEUR associated_log AVEC L'ID DES LOGS DE L'ATTAQUE

    //CREER ET PROOTOTYPER LA METHODE DE TRI PAR HEURE QUI PRECEDE L'ANALYSER

    ////PROTOTYPE ET UTILISATION DE LA METHODE DE CREATION D'ID DE TOM POUR DONNER UN ID UNIQUE A CHAQUE SECURITY_EVENT

private:
    int Id_Security_Event;
    EventType Event_Type;
    std::string Description;
    EventGravity Event_Gravity;
    std::vector<int> Associated_Log_Ids;
    std::time_t Time_Stamp;

};

