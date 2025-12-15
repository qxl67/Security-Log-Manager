#include <iostream>

class Event_Rapport {
public:
    enum class EventPriority {
        IMMEDIATE,
        LATER
    };

    // Constructeur 
    Event_Rapport(int id_event_rapport,
        std::string recommendation,
        EventPriority event_priority = EventPriority::IMMEDIATE,
        std::tm time_stamp = {}): 
            Id_Event_Rapport(id_event_rapport),
            Recommendation(recommendation),
            Event_Priority(event_priority),
            Time_Stamp(time_stamp) {}

    // Getters
    //Getters a commenter selon les besoins
    int getIdEventRapport() const { return Id_Event_Rapport; }
    std::string getRecommendation() const { return Recommendation; }
    EventPriority getEventPriority() const { return Event_Priority; }
    std::tm getTimeStamp() const { return Time_Stamp; }


private:
    int Id_Event_Rapport;
    std::string Recommendation;
    EventPriority Event_Priority;
    std::tm Time_Stamp;

//Méthode pour établir des poiteur d'alerte



};