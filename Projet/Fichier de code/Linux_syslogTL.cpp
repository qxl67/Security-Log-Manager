#include "Linux_SyslogTL.hpp"
#include <iostream>

    //Méthode pour afficher
    void displayLogs() const override {
        Logs::displayLogs();
        std::cout << "Facilité: " << Facility << std::endl;
        std::cout << "Priorité: " << Priority << std::endl;
        std::cout << "Syslog Tag: " << Syslog_Tag << std::endl;
        std::cout << "Programme: " << Program << std::endl;
        std::cout << "PID: " << Processus_Id_Str << std::endl;
    }
