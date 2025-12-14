#include "Linux_SecureTL.hpp"
#include <iostream>

    //Méthode pour afficher
    void displayLogs() const override {
        System_Logs::displayLogs(); 
        std::cout << "Service: " << Service << std::endl;
        std::cout << "Facilité: " << Facility << std::endl;
        std::cout << "Priorité: " << Priority << std::endl;
        std::cout << "Commande: " << Command << std::endl;
        std::cout << "Terminal: " << Terminal << std::endl;
        }