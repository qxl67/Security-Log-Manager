#include "Windows_System_LogTL.hpp"
#include <iostream>

    //Méthode pour afficher
    void displayLogs() const override {
        System_Logs::displayLogs(); // Appelle la méthode display() de la classe parente
        std::cout << "ID de l'événement: " << Event_ID << std::endl;
        std::cout << "Categorie de l'événement: " << Event_Category << std::endl;
        std::cout << "Nom du journal: " << Log_Name << std::endl;
        std::cout << "Mot-clés: " << Keywords << std::endl;
        std::cout << "Catégorie de la tâche: " << Task_Category << std::endl;
        std::cout << "Code de l'opération: " << Operation_Code << std::endl
        }
