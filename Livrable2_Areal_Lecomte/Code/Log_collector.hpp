#ifndef LOG_COLLECTOR_HPP
#define LOG_COLLECTOR_HPP
#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include "Log.hpp"

/**
* @brief Transforme une chaine de caracteres en objet de type time_t.
* @param date String (viennent du fichier de logs)
*/
time_t convertisseur_date(const std::string& date);

/**
 * @class Log_collector
 * @brief Représente le processus de recuperation des logs.
 */
class Log_collector {

    private:
        /** @brief Chemin qui mene au fichier contenant les logs */
        std::string chemin;

    public:
        /**
        * @brief Constructeur de la classe Log_collector.
        * @param path Chemin qui mene au fichier contenant les logs
        */
        Log_collector(const std::string& path);

        /**
        * @brief Destructeur de la classe Log.
        */
        ~Log_collector();

        /**
        * @brief Initialisation d objets de type Log et ses heritiers via un objet de type Log_collector.
        */
        std::vector<std::unique_ptr<Log>> importer(); // prend une instance de Log_collector et le transforme en une instance de Log
};

#endif