#include "Archives.hpp"
#include <fstream>
#include <iostream>

void Archives::addLog(const Logs& log) {
    Logs_Archive.push_back(log);
}

void Archives::addSecurityEvent(const Security_Event& event) {
    Security_Events_Archive.push_back(event);
}

void Archives::addEventRapport(const Event_Rapport& rapport) {
    Event_Rapports_Archive.push_back(rapport);
}


void Archives::exportLogs(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Erreur ouverture fichier logs\n";
        return;
    }

    file << "ID;TimeStamp;Source;ProcessID\n";

    for (const auto& log : Logs_Archive) {
        file << log.getId() << ";"
             << log.getTimeStamp() << ";"
             << log.getSourceLog() << ";"
             << log.getProcessusId() << "\n";
    }
}

void Archives::exportSecurityEvents(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Erreur ouverture fichier security events\n";
        return;
    }

    file << "ID;Type;Gravity;Timestamp\n";

    for (const auto& ev : Security_Events_Archive) {
        file << ev.getIdSecurityEvent() << ";"
             << static_cast<int>(ev.getEventType()) << ";"
             << static_cast<int>(ev.getEventGravity()) << ";"
             << ev.getTimeStamp() << "\n";
    }
}

void Archives::exportEventRapports(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Erreur ouverture fichier rapports\n";
        return;
    }

    file << "ID;Priority;TimeStamp;Recommendation\n";

    for (const auto& rp : Event_Rapports_Archive) {
        file << rp.getIdEventRapport() << ";"
             << static_cast<int>(rp.getEventPriority()) << ";"
             << rp.getTimeStamp() << ";"
             << rp.getRecommendation() << "\n";
    }
}

// Archive expirée ?
bool Archives::isExpired() const {
    return std::time(nullptr) >= Archive_End_Date;
}

//REGLER LA DATE D'EXPERITATION PAR DEFAUT A 1 MOIS

// Vider l’archive (destruction logique)
void Archives::clear() {
    Logs_Archive.clear();
    Security_Events_Archive.clear();
    Event_Rapports_Archive.clear();
}