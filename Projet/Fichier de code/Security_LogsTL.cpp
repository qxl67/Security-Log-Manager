#include "Security_LogsTL.hpp"
#include <iostream>

// Méthode pour afficher
    void displayLogs() const override {
        Logs::displayLogs(); // Appelle la méthode displayLogs() de la classe de base
        std::cout << "Adresse IP: " << Ip_Adress << std::endl;
        std::cout << "Status: " << Status << std::endl;
        std::cout << "ID de la session: " << Session_Id << std::endl;
        std::cout << "Raisons de l'échec: " << Fail_Reason << std::endl;
    }