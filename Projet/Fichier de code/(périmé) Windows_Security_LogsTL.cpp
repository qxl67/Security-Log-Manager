#include "Windows_Security_LogsTL.hpp"
#include <iostream>


// Méthode pour afficher
    void displayLogs() const override {
        Security_Logs::displayLogs();
        std::cout << "ID de l'événement: " << Event_ID << std::endl;
        std::cout << "Type de connection: " << Logon_Type << std::endl;
        std::cout << "Domaine du compte: " << Account_Domain << std::endl;
        std::cout << "Nom de l'objet: " << Object_Name << std::endl;
        std::cout << "Type de l'objet: " << Object_Type << std::endl;
        std::cout << "Masque d'accés: " << Access_Mask << std::endl;
        std::cout << "Package d'authentification: " << Authentication_Package << std::endl;
        }
