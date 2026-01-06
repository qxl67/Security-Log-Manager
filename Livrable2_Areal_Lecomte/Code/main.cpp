#include "Log.hpp"
#include "Log_collector.hpp"
#include "Security_Event.hpp"
#include "Rapport.hpp"

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

/**Prends une liste de pointeurs uniques et les tri de manière croissante**/
std::vector<std::unique_ptr<Log>> trier_logs_croissant(
    std::vector<std::unique_ptr<Log>> logs
) {
    std::sort(
        logs.begin(),
        logs.end(),
        [](const std::unique_ptr<Log>& a, const std::unique_ptr<Log>& b) {
            return *a < *b;
        }
    );

    return std::move(logs); // move implicite
}

/**Prends une liste de pointeurs uniques et les tri de manière décroissante**/
std::vector<std::unique_ptr<Log>> trier_logs_decroissant(
    std::vector<std::unique_ptr<Log>> logs
) {
    std::sort(
        logs.begin(),
        logs.end(),
        [](const std::unique_ptr<Log>& a, const std::unique_ptr<Log>& b) {
            return *a > *b;
        }
    );

    return std::move(logs); // move implicite
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {

    std::cout << "Le programme va commencer, nous allons commencer par lire un un fichier xml contenant plusieurs logs provenant de linux system. Appuyez sur Entrée pour continuer ";
    std::cin.get();

    /* ===================== LINUX SYSTEM ===================== */

    Log_collector linux_system("Log_test/Linux_Syslog.xml");

    auto linux_logs_system = linux_system.importer();

    std::cout << "\n===== LINUX SYSTEM LOGS =====\n";
    for (const auto& log : linux_logs_system) {
        log->afficher();
        std::cout << "----------------------------------\n";
    }

    std::cout << "La meme chose que precedement mais cette fois ci avec windozs system. Appuyez sur Entrée pour continuer ";
    std::cin.get();

    /* ===================== WINDOWS SYSTEM ===================== */

    Log_collector windows_system("Log_test/Windows_System_Log.xml");

    auto windows_logs_system = windows_system.importer();

    std::cout << "\n===== WINDOWS SYSTEM LOGS =====\n";
    for (const auto& log : windows_logs_system) {
        log->afficher();
        std::cout << "----------------------------------\n";
    }

    std::cout << "La meme chose que precedement mais cette fois ci avec un log linux suspect le but etant de detecter la faille. Appuyez sur Entrée pour continuer ";
    std::cin.get();

    /* ===================== SUSPECT LINUX ===================== */

    Log_collector linux_collector("Log_test/Linux_Secure_Suspect.xml");

    auto linux_logs = linux_collector.importer();

    auto linux_logs_triees = trier_logs_croissant(std::move(linux_logs));

    std::cout << "\n===== LINUX LOGS =====\n";
    for (const auto& log : linux_logs_triees) {
        log->afficher();
        std::cout << "----------------------------------\n";
    }

    Security_Event linux_event(std::move(linux_logs_triees));

    linux_event.afficher();

    std::cout << "La meme chose que precedement mais cette fois ci avec un log windows suspect le but etant de detecter la faille. Appuyez sur Entrée pour continuer ";
    std::cin.get();

    /* ===================== SUSPECT WINDOWS ===================== */

    Log_collector windows_collector("Log_test/Windows_Security_Log.xml");

    auto windows_logs = windows_collector.importer();

    auto windows_logs_triees = trier_logs_croissant(std::move(windows_logs));

    std::cout << "\n===== WINDOWS LOGS =====\n";
    for (const auto& log : windows_logs_triees) {
        log->afficher();
        std::cout << "----------------------------------\n";
    }

    Security_Event windows_event(std::move(windows_logs_triees));

    windows_event.afficher();

    std::cout << "On cree un rapport de securite avec les evenements crees precedement. Appuyez sur Entrée pour continuer ";
    std::cin.get();

    /* ===================== CREATION DE RAPPORT ===================== */

    std::vector<std::unique_ptr<Security_Event>> all_events;

    all_events.push_back(std::make_unique<Security_Event>(std::move(linux_event)));
    all_events.push_back(std::make_unique<Security_Event>(std::move(windows_event)));

    Rapport rapport(std::move(all_events));
    rapport.exportation("security_report.txt");


    return 0;
}