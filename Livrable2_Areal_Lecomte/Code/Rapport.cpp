#include "Rapport.hpp"
#include <fstream>
#include <iostream>

static int Global_Rapport_Id = 0;

Rapport::Rapport(std::vector<std::unique_ptr<Security_Event>> events)
    : Id_Rapport(Global_Rapport_Id++),
      creation_date(std::time(nullptr)),
      events(std::move(events))
{
    for (const auto& e : this->events)
        event_ids.push_back(e->getId());

    compute_priority();
    generate_recommendation();
}

void Rapport::compute_priority() {

    priority = Event_Priority::NONE;

    for (const auto& e : events) {
        std::string gravity = e->getGravityAsString();

        if (gravity == "HIGH") {
            priority = Event_Priority::CRITICAL;
            return;
        }
        if (gravity == "MEDIUM")
            priority = Event_Priority::HIGH;
        else if (gravity == "LOW" && priority == Event_Priority::NONE)
            priority = Event_Priority::LOW;
    }
}

void Rapport::generate_recommendation() {

    switch (priority) {
        case Event_Priority::CRITICAL:
            recommendation = "Immediate action required: block affected accounts and audit the system.";
            break;
        case Event_Priority::HIGH:
            recommendation = "Investigate suspicious activities and reinforce authentication policies.";
            break;
        case Event_Priority::MEDIUM:
            recommendation = "Review logs and closely monitor the system.";
            break;
        case Event_Priority::LOW:
            recommendation = "No urgent action required. Continue monitoring.";
            break;
        default:
            recommendation = "No security incident detected.";
    }
}

std::string Rapport::getPriorityAsString() const {

    switch (priority) {
        case Event_Priority::CRITICAL: return "CRITICAL";
        case Event_Priority::HIGH:     return "HIGH";
        case Event_Priority::MEDIUM:   return "MEDIUM";
        case Event_Priority::LOW:      return "LOW";
        default:                       return "NONE";
    }
}

void Rapport::exportation(const std::string& filename) const {

    std::ofstream file(filename);

    if (!file) {
        std::cerr << "Error: unable to create report file\n";
        return;
    }

    file << "==================== SECURITY REPORT ====================\n";
    file << "Report ID       : " << Id_Rapport << "\n";
    file << "Creation date   : " << std::ctime(&creation_date);
    file << "Global priority : " << getPriorityAsString() << "\n\n";

    file << "Included Security Events:\n";
    for (int id : event_ids)
        file << " - Event ID " << id << "\n";

    file << "\n==================== DETAILS ====================\n\n";

    for (const auto& e : events) {
        e->export_to_stream(file);
        file << "\n-------------------------------------------------\n";
    }

    file << "\n==================== RECOMMENDATION ====================\n";
    file << recommendation << "\n";

    file.close();
}
