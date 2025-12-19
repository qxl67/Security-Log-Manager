//Ajouter les includes qui manque, les #ifndef #define, #endif
#include <iostream>

class Security_Event {
public:
    enum class EventGravity {
        HIGH,
        MEDIUM,
        LOW
    };

    // Constructeur 
    Security_Event(int id_security_event,
        std::string description,                    
        EventGravity event_gravity = EventGravity::HIGH,
        std::vector<Logs*> associated_logs = {},
        std::tm time_stamp = {}): 
            Id_Security_Event(id_security_event),
            Description(description),
            Event_Gravity(event_gravity),
            Associated_Logs(associated_logs),
            Time_Stamp(time_stamp) {}

    // Getters
    //Getters a commenter selon les besoins (utilisé pour creer le Event_Rapport)
    int getIdSecurityEvent() const { return Id_Security_Event; }
    std::string getDescription() const { return Description; }
    EventGravity getEventGravity() const { return Event_Gravity; }
    std::vector<Logs*> getAssociatedLogs() const { return Associated_Logs; }
    std::tm getTimeStamp() const { return Time_Stamp; }


    //CREER UN PROTOTYPE ET SA METHODE POUR DETECTER UNE ATTAQUE = THOMAS S'OCCUPE DE L'ALGO DE DETECTION
        //IL FAUT QUE LES INFOS DES GETTER UTILISÉ DANS L'ALGO DE DETECTION PUISSENT ETRE UTILISÉE POUR REMPLIR LE RAPPORT D'EVENT

    //CREER LE PROTOTYPE ET LA METHODE POUR EXPORTER LES EVENT DANS LES ARCHIVES

    //CREER UN PROTOTYPE ET SA METHODE POUR RENPLIR LE VECTEUR associated_log AVEC L'ID DES LOGS DE L'ATTAQUE

private:
    int Id_Security_Event;
    std::string Description;
    EventGravity Event_Gravity;
    std::vector<Logs*> Associated_Logs;
    std::tm Time_Stamp;

};