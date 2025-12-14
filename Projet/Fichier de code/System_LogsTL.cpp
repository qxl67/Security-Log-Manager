#include "System_LogsTL.hpp"
#include <iostream>

// Méthode pour afficher
    void displayLogs() const override {
        Logs::displayLogs(); // Appelle la méthode displayLogs() de la classe de base
        std::cout << "Nom du processus: " << Processus_name << std::endl;
        std::cout << "Sévérité: " << Severity << std::endl;
    }