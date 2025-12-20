//Ajouter les includes qui manque, les #ifndef #define, #endif
#include <iostream>

class Event_Rapport {
public:
    enum class EventPriority {
        IMMEDIATE,
        LATER
    };

    // Constructeur de la classe
    Event_Rapport(int id_event_rapport,         
        std::string recommendation,
        EventPriority event_priority = EventPriority::IMMEDIATE,
        std::vector<Security_Event*> associated_event = {},
        std::time_t time_stamp = {}):                               // LE TIME STAMP PEUT ETRE DE TYPE TM (time stamp) OU DE TYPE STRING. PERSO JE RECOMMENDE TIME_STAMP
            Id_Event_Rapport(id_event_rapport),
            Recommendation(recommendation),
            Event_Priority(event_priority),
            Associated_Event(associated_event),
            Time_Stamp(time_stamp) {}

    //Getters de la classe, a commenter selon les besoins
    int getIdEventRapport() const { return Id_Event_Rapport; }
    std::string getRecommendation() const { return Recommendation; }
    EventPriority getEventPriority() const { return Event_Priority; }
    std::vector<Security_Event*> getAssociated_Event() const { return Associated_Event; }
    std::time_t getTimeStamp() const { return Time_Stamp; }


private:
    int Id_Event_Rapport;
    std::string Recommendation;
    EventPriority Event_Priority;
    std::vector<Security_Event*> Associated_Event;
    std::time_t Time_Stamp;

//CREER LE PROTOTYPE ET LA METHODE POUR RECUPERER ET COMPILER LES SECURITY_EVENT DANS UN MEME RAPPORT
    //CREER UN MODELE DE RAPPORT

//CREER LE PROTOTYPE ET LA METHODE POUR EXPORTER LES RAPPORTS DANS LES ARCHIVES
    //L'exportation doit etre possible en tant que telechargement vers un fichier 
    // et l'exportation doit etre possible en direction des archives. Il faudra donc
    // laisser la possibilité de choisir entre les deux lors de l'exportation. 

//CREER UN PROTOTYPE ET SA METHODE POUR RENPLIR LE VECTEUR Associated_Event AVEC L'ID DES SECURITY_EVENT DE L'ATTAQUE

//Créer une méthode pour saisir un texte de recommandation si on veut. 

// Méthode statique pour créer un rapport
    static Event_Rapport createRapport(
        //int id_event_rapport,
        //const std::vector<Security_Event>& security_events,
        //const std::vector<Log>& logs,
        //EventPriority priority = EventPriority::IMMEDIATE,
        //std::tm time_stamp = {}
    );
    


};
