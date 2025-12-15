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

    // Getters corrigés
    //Getters a commanter selon les besoins
    int getIdSecurityEvent() const { return Id_Security_Event; }
    std::string getDescription() const { return Description; }
    EventGravity getEventGravity() const { return Event_Gravity; }
    std::vector<Logs*> getAssociatedLogs() const { return Associated_Logs; }
    std::tm getTimeStamp() const { return Time_Stamp; }

    // Méthode pour vérifier si un critère est présent dans les attributs (lors de la recherche du Event_Log_filter)
    //bool contains(const std::string& criteria) const;

private:
    int Id_Security_Event;
    std::string Description;
    EventGravity Event_Gravity;
    std::vector<Logs*> Associated_Logs;
    std::tm Time_Stamp;

        //Méthode pour convertir l'énumeration EventGravity en str lors des recherches de event_log_filter
    //std::string eventGravityToString(EventGravity gravity) const;


};