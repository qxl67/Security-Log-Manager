//Ajouter les includes qui manque, les #ifndef #define, #endif
#include <vector>
#include <ctime>
#include <iostream>
#include "NewLogsTL.hpp"
#include "NewSecurity_EventTL.hpp"
#include "NewEvent_RapportTL.hpp"

class Archives {
public:
    enum class ArchivesTypes {
        LOG,
        SECURITYEVENT,
        EVENT_RAPPORT
    };

    static constexpr std::time_t Life_Time = 30 * 24 * 60 * 60; // On fixe la durée de vie par défaut des archives a 1 mois (30 jours en secondes)

    // Constructeur
    Archives(int id_archives,
             std::time_t archive_init_date,
             std::time_t archive_end_date,
             ArchivesTypes archives_types) :
        Id_Archives(id_archives),
        Archive_Init_Date(archive_init_date),
        Archive_End_Date(archive_end_date),
        Archives_Types(archives_types) {
        Archive_Init_Date = (archive_init_date == 0) ? std::time(nullptr) : archive_init_date;
        Archive_End_Date = (archive_end_date == 0) ? Archive_Init_Date + Life_Time : archive_end_date;
        }
    
    //Prototype de la méthode d'archivage
    void addLog(const Logs& log);
    void addSecurityEvent(const Security_Event& event);
    void addEventRapport(const Event_Rapport& rapport);
    bool isExpired() const ; //Vérifie la date d'expiration indiquée
    void clear(); //Clear L,archive si expirée


    // Exporter les documents archivés
    void exportLogs(const std::string& filename) const;
    void exportSecurityEvents(const std::string& filename) const;
    void exportEventRapports(const std::string& filename) const;

    // Getters
    //On commentera ce qui n'est pas necessaire
    int getIdArchives() const { return Id_Archives; }
    std::time_t getArchiveInitDate() const { return Archive_Init_Date; }
    std::time_t getArchiveEndDate() const { return Archive_End_Date; }
    ArchivesTypes getArchivesTypes() const { return Archives_Types; }


private:
    int Id_Archives;
    std::time_t Archive_Init_Date;
    std::time_t Archive_End_Date;
    ArchivesTypes Archives_Types;

    std::vector<Logs> Logs_Archive;
    std::vector<Security_Event> Security_Events_Archive;
    std::vector<Event_Rapport> Event_Rapports_Archive;
};