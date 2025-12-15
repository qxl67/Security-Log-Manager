#include <iostream>

class Archives {
public:
    enum class ArchivesTypes {
        LOG,
        SECURITY_EVENT
    };

    // Constructeur
    Archives(int id_archives,
             std::tm archive_init_date,
             std::tm archive_end_date,
             ArchivesTypes archives_types = ArchivesTypes::SECURITY_EVENT) :
        Id_Archives(id_archives),
        Archive_Init_Date(archive_init_date),
        Archive_End_Date(archive_end_date),
        Archives_Types(archives_types) {}

    // Getters
    int getIdArchives() const { return Id_Archives; }
    std::tm getArchiveInitDate() const { return Archive_Init_Date; }
    std::tm getArchiveEndDate() const { return Archive_End_Date; }
    ArchivesTypes getArchivesTypes() const { return Archives_Types; }

private:
    int Id_Archives;
    std::tm Archive_Init_Date;
    std::tm Archive_End_Date;
    ArchivesTypes Archives_Types;

//Méthode pour établir des poiteur d'alerte



};