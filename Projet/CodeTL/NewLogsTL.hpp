//Ajouter les includes qui manque, les #ifndef #define, #endif
#include <iostream>

//Classe mére Log
class Logs {
protected:                     
    int Id_Logs;
    std::string Synthesis_Message;      //MESSAGE A SAISIR NOUS MEME SI ON VEUT AJOUTER UN COMMENTAIRE SUR LE LOG. ON PEUT LE SET A NULL PAR DEFAUT
    std::time_t Time_stamp;             // CORRESPOND AUX ATTRIBUTS "TIME CREATED" DANS LES LOGS WINDOWS ET "TIME STAMP" DANS LES LOGS LINUX. IL FAUT HAMONISER LES DEUX ATTRIBUT CAR LES LOGS LINUX N'UTILISENT PAS L"ANNÉE. DONC SOIT TU L'AJOUTE D'UN COTÉ (LE MIEU), SOIT TU LA SUPPRIME DE L'AUTRE. 
                                        // ATTENTION POUR LE TIME STAMP ON VEUT QUE LE LOGS SOIT COMPLETÉ AVEC UN TYPE STRING DASN UN FORMAT JOURS/MOIS/ANNEE/HEURE/MINUTE/SECONDE
    std::string Source_Log;             //CORRESPOND AU NOM DU LOG D'OU SON ORIGINAIRES LES DONNÉES (LINUX SYSLOG, LINUX SECURE, WINDOWS SYSTEM LOG, WINDOWS SECURITY LOG)
    //std::string Source_Message;       //CORRESPOND AU CONTENU D'ORIGINE DU LOG (C'EST A DIRE ENTRE LES DEUX BALISES EVENT). ON EST PAS OBLIGÉ DE GARDER CET ATTRIBUT
    int Processus_Id;                   // CORRESPOND A "ProcessId" DANS LES LOGS WINDOWS ET "PID" DANS LES LOGS LINUX  

public: // Permet de creer le constructeur
    Logs(int id, 
    std::string synthesis_message,
    std::time_t time_stamp, 
    std::string source_log,
    std::string source_message, 
    int processus_id):
        Id_Logs(id),
        Synthesis_Message(synthesis_message),
        Time_stamp(time_stamp),
        Source_Log(source_log),
        //Source_Message(source_message),
        Processus_Id(processus_id) {}
    
    ~Logs(); // Destructeur

    // Getters, determiner quels sont les attributs a utiliser dans l'algo. Ici, ils sont tous en getter, mais on pourrait limiter la selection pour plus de sécurité.
    // on commentera les attributs qu'on utilisera pas
    int getId() const { return Id_Logs; }
    std::time_t getTimeStamp() const { return Time_stamp; }
    std::string getSourceLog() const { return Source_Log; }
    //std::string getSourceMessage() const { return Source_Message; }
    int getProcessusId() const { return Processus_Id; }

    // Créer une méthode pour saisir (si on veut) un message dans synthesis_message (c'est un commentaire en quelque sorte). Sinon on initialise le synthesis_message a NULL
    // Prototype du setters pour saisir le synthesis_message
    void setSynthesis_message(const std::string& synthesis_message); 

    // Créer une méthode pour saisir (si on veut) un message dans level (c'est un commentaire en quelque sorte). Sinon on initialise le level a NULL
    // Prototype du setters pour saisir le level
    void setLevel(const std::string& level);

    // Créer une méthode pour afficher le contenu d'un log
    // Prototype de la fonction pour afficher le log
    virtual void displayLogs() const;

    //Creer une méthode pour trier les logs par ordre chronologique. On doit utiliser une methode de comparaison entre objet afin de repondre au exigences du proche.
    //On doit donc comparer les objets par leur time_stamp pour les classer chronologiauement malgré le fait qu'il viennent de systeme (windows/linux) différents.

    //Creer une méthode pour suppirmer une entrée dans les logs, ou pour modifier manuellement un attribut dans une des entrée (permettra d'implementer le passage par valeur)

};





