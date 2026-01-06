#ifndef RAPPORT_HPP
#define RAPPORT_HPP

#include "Security_Event.hpp"
#include <vector>
#include <string>
#include <ctime>

/**
 * @class Rapport
 * @brief Représente un rapport.
 */
class Rapport {

public:
    /**
    * @brief Constructeur de la classe Rapport.
    * @param events Evenement traites dans le rapport
    */
    Rapport(std::vector<std::unique_ptr<Security_Event>> events);

    /** @brief Liste des possibilites que peut prendre Event_Priority */
    enum class Event_Priority {
        CRITICAL,
        HIGH,
        MEDIUM,
        LOW,
        NONE};

    /** @brief Fonction qui cree un fichier texte avec un rapport d evenement */
    void exportation(const std::string& filename) const;

    /** @brief transforme enum en string */
    std::string getPriorityAsString() const;

private:
    /** @brief Identifiant unique du rapport */
    int Id_Rapport;

    /** @brief Date de creation du rapport */
    std::time_t creation_date;

    /** @brief Liste des priorites possible */
    Event_Priority priority;

    /** @brief String conseil */
    std::string recommendation;

    /** @brief Liste d evenements concerne par le rapport */
    std::vector<std::unique_ptr<Security_Event>> events;

    /** @brief Liste des id d evenements */
    std::vector<int> event_ids;

    /** @brief Donne la priorite au rapport en fonction des evenements */
    void compute_priority();

    /** @brief Donne une recommandation au rapport en fonction de la gravite*/
    void generate_recommendation();

};

#endif