#include "LogsTL.hpp"
#include <iostream>




// Méthode virtuelle pour le parsing (à redéfinir dans les sous-classes)
    virtual Logs* parseLogsEntree(const std::string& LogsEntree) = 0;
    //!DEFINIR LA FONCTION DE PARSE!

// Méthode pour afficher les logs et s'en servir lors de la création des evenements
// voir si il ne faudra pas commenter les element inutiles du display pour la production des rapports d'événement. 
    virtual void displayLogs() const {
        std::cout << "ID : " << Id_Logs << std::endl;
        std::cout << "Date et Heure: " << std::put_time(&Time_stamp, "%d/%m/%Y %H:%M:%S") << std::endl;
        std::cout << "Host: " << Host << std::endl;
        std::cout << "User ou User context: " << User_or_User_Context << std::endl;
        std::cout << "Type d'événement: " << Event_Type << std::endl;
        std::cout << "PID: " << Processus_Id << std::endl;
        std::cout << "Commentaire: " << synthesis_message << std::endl;
        std::cout << "Message original: " << Source_Message << std::endl; // cet attribut peut etre optionnel
        }
