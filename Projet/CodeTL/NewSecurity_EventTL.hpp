//Ajouter les includes qui manque, les #ifndef #define, #endif
#ifndef SECURITY_EVENT_HPP
#define SECURITY_EVENT_HPP
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

    // Constructeur 
    Security_Event(int id_security_event,
        std::string description,                    
        EventGravity event_gravity,
        std::vector<int> associated_log_ids,
        std::time_t time_stamp = {}): 
            Id_Security_Event(id_security_event),
            Description(description),
            Event_Gravity(event_gravity),
            Associated_Log_Ids(associated_logs_ids),
            Time_Stamp(time_stamp) {}

    // Getters
    //Getters a commenter selon les besoins (utilisé pour creer le Event_Rapport)
    int getIdSecurityEvent() const { return Id_Security_Event; }
    std::string getDescription() const { return Description; }
    EventGravity getEventGravity() const { return Event_Gravity; }
    std::vector<int> getAssociatedLogIds() const { return Associated_Log_Ids; }
    std::time_t getTimeStamp() const { return Time_Stamp; }

    // Setters
    //Setters a utiliser pour completer la classe
    void setIdSecurityEvent(int id) { Id_Security_Event = id; }
    void setDescription(const std::string& desc) { Description = desc; }
    void setEventGravity(EventGravity gravity) { Event_Gravity = gravity; }
    void setAssociatedLogIds(const std::vector<int>& logs) { Associated_Log_Ids = logs; }
    void setTimeStamp(const std::time_t tm) { Time_Stamp = tm; }

    //CREER UN PROTOTYPE ET SA METHODE POUR RENPLIR LE VECTEUR associated_log AVEC L'ID DES LOGS DE L'ATTAQUE
    void addAssociatedLogId(int log_id) {Associated_Log_Ids.push_back(log_id);}

    //CREER UN PROTOTYPE ET SA METHODE POUR DETECTER UNE ATTAQUE = THOMAS S'OCCUPE DE L'ALGO DE DETECTION
        //IL FAUT QUE LES INFOS DES GETTER UTILISÉ DANS L'ALGO DE DETECTION PUISSENT ETRE UTILISÉE POUR REMPLIR LE RAPPORT D'EVENT

    //CREER LE PROTOTYPE ET LA METHODE POUR EXPORTER LES EVENT DANS LES ARCHIVES

    //CREER UN PROTOTYPE ET SA METHODE POUR RENPLIR LE VECTEUR associated_log AVEC L'ID DES LOGS DE L'ATTAQUE

    //CREER ET PROOTOTYPER LA METHODE DE TRI PAR HEURE QUI PRECEDE L'ANALYSER

    ////PROTOTYPE ET UTILISATION DE LA METHODE DE CREATION D'ID DE TOM POUR DONNER UN ID UNIQUE A CHAQUE SECURITY_EVENT

private:
    int Id_Security_Event;
    std::string Description;
    EventGravity Event_Gravity;
    std::vector<int> Associated_Log_Ids;
    std::time_t Time_Stamp;

};

#endif;


