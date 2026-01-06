#include "Security_Event.hpp"
#include "Log.hpp"
#include "Global_Id_Log.hpp"

#include <iostream>
#include <vector>
#include <ctime>
#include <memory>
#include <algorithm>

int Global_Id_Event = 0; // Id Event

void Security_Event::analyser_logs() {

    constexpr int Seconde = 30;
    int compte = 0;
    std::time_t time_premier = 0;

    std::vector<Log*> suspects;

    for (const auto& log : logs) {

        bool is_failed =
            log->getKeywords().find("login_failed") != std::string::npos ||
            log->getAction().find("login_failed") != std::string::npos;

        if (!is_failed)
            continue;

        if (compte == 0) {
            time_premier = log->getTimeStamp();
            compte = 1;
            suspects.clear();
            suspects.push_back(log.get());
        }
        else if (log->getTimeStamp() - time_premier <= Seconde) {
            ++compte;
            suspects.push_back(log.get());

            if (compte >= 3) {
                Event_Type = EventType::BRUTEFORCE;
                Event_Gravity = EventGravity::HIGH;
                Description = "Bruteforce detected: 3 login_failed within 30 seconds";

                // Utilisateur concerné (celui du dernier log)
                concerned_user = log->getUser();

                // Logs impliqués + actions/keywords
                for (Log* l : suspects) {
                    involved_log_ids.push_back(l->getId());

                    if (!l->getAction().empty())
                        involved_actions.push_back(l->getAction());     // Linux security
                    else
                        involved_actions.push_back(l->getKeywords());  // Windows security
                }

                return;
            }
        }
        else {
            // fenêtre dépassée → reset
            time_premier = log->getTimeStamp();
            compte = 1;
            suspects.clear();
            suspects.push_back(log.get());
        }
    }

    // Aucun incident détecté
    Event_Type = EventType::UNKNOWN;
    Event_Gravity = EventGravity::UNKNOWN;
    Description = "No security incident detected";
}

Security_Event::Security_Event(std::vector<std::unique_ptr<Log>> logs)
    :   Id_Security_Event(Global_Id_Event++),
        logs(std::move(logs)),          // move d’abord
        Time_Stamp(std::time(nullptr))  // timestamp de l’événement
{
    analyser_logs();                  // analyse interne
}

std::string Security_Event::getTypeAsString() const {
    switch (Event_Type) {
        case EventType::BRUTEFORCE: return "BRUTEFORCE";
        case EventType::SCAN:       return "SCAN";
        default:                    return "UNKNOWN";
    }
}

std::string Security_Event::getGravityAsString() const {
    switch (Event_Gravity) {
        case EventGravity::LOW:    return "LOW";
        case EventGravity::MEDIUM: return "MEDIUM";
        case EventGravity::HIGH:   return "HIGH";
        default:                   return "UNKNOWN";
    }
}

void Security_Event::afficher() const {

    std::cout << "================ SECURITY EVENT ================\n";
    std::cout << "ID              : " << Id_Security_Event << '\n';
    std::cout << "Type            : " << getTypeAsString() << '\n';
    std::cout << "Gravity         : " << getGravityAsString() << '\n';
    std::cout << "Description     : " << Description << '\n';

    std::cout << "User            : " << concerned_user << '\n';

    std::cout << "Logs involved   : ";
    for (int id : involved_log_ids)
        std::cout << id << " ";
    std::cout << '\n';

    std::cout << "Actions/Keywords:\n";
    for (const auto& a : involved_actions)
        std::cout << "  - " << a << '\n';

    std::cout << "===============================================\n";
}

void Security_Event::export_to_stream(std::ostream& out) const {

    out << "Security Event ID : " << Id_Security_Event << "\n";
    out << "Type              : " << getTypeAsString() << "\n";
    out << "Gravity           : " << getGravityAsString() << "\n";
    out << "Description       : " << Description << "\n";
    out << "User              : " << concerned_user << "\n";

    out << "Logs involved     : ";
    for (int id : involved_log_ids)
        out << id << " ";
    out << "\n";

    out << "Actions:\n";
    for (const auto& a : involved_actions)
        out << " - " << a << "\n";
}