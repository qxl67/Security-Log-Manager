#ifndef SECURITY_EVENT_HPP
#define SECURITY_EVENT_HPP

#include "Log.hpp"

#include <iostream>
#include <vector>
#include <ctime>
#include <memory>

/**
 * @class Security_Event
 * @brief Représente un evenement de securite
 */
class Security_Event {
    
    private:
        /** @brief Liste des possibilites que peut prendre EventGravity */
        enum class EventGravity {
            UNKNOWN,
            HIGH,
            MEDIUM,
            LOW
        };

        /** @brief Liste des possibilites que peut prendre EventType */
        enum class EventType {
            UNKNOWN,
            BRUTEFORCE,
            SCAN,
        };

        /** @brief Identifiant unique du log */
        int Id_Security_Event = -1;

        /** @brief Liste des possibilites que peut prendre EventGravity */
        EventGravity Event_Gravity = EventGravity::UNKNOWN;

        /** @brief Liste des possibilites que peut prendre Event_Priority */
        EventType Event_Type = EventType::UNKNOWN;

        /** @brief Description de l evenement */
        std::string Description = "";

        /** @brief Date de l evenement */
        std::time_t Time_Stamp = 0;

        /** @brief Liste de pointeurs vers des logs */
        std::vector<std::unique_ptr<Log>> logs;

        /** @brief User concerne */
        std::string concerned_user;

        /** @brief ID des logs qui font un evenement */
        std::vector<int> involved_log_ids;

        /** @brief Quelle attaque detectee */
        std::vector<std::string> involved_actions;
        
        /** @brief verifie les conditions pour detecter une attaque */
        void analyser_logs();

    public:
        /** @brief Constructeur de Security_Event
         *  @param Liste de pointeur vers des logs
         */
        explicit Security_Event(std::vector<std::unique_ptr<Log>> logs);

        /** @brief Afficher/Ecrire un evenement*/
        void export_to_stream(std::ostream& out) const;
        
        /** @brief Donne l ID d evenement */
        int getId() const { return Id_Security_Event; }

        /** @brief Affiche un event */
        void afficher() const;

        /** @brief Donne le type en string */
        std::string getTypeAsString() const;
        
        /** @brief Donne la gravite en string */
        std::string getGravityAsString() const;

};

#endif