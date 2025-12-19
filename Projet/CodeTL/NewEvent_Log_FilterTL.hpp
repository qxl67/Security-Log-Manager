//Ajouter les includes qui manquent, les #ifndef #define, #endif
#include <iostream>
#include "Logs.hpp"

class Event_Log_Filter {
public:
    enum class AssetType {      //ON VEUT UN CHOIX DE SELECTION AVEC ENUM ENTRE LE FILTRE DES LOGS OU DES SECURITY_EVENT, ENSUITE ON APPLIQUE NOTRE FILTER_CRITERIA POUR RECHERCHER DANS LA CATÉGORIE QUI NOUS INTERESSE
        SECURITY_EVENT,
        LOGS
    };

    // Constructeur 
    Event_Log_Filter(int id_filter,
        AssetType asset_type = AssetType::SECURITY_EVENT,       //ON INITIALISE LE FILTRE SUR SECURITY_EVENT PAR DEFAUT, MAIS ON POURRAIT AUSSI INITIALISER A NULL
        const std::string& filter_criteria = ""):     //ICI J'AI FAIT COMME SI ON UTILISE UN FILTRE PAR SAISI (genre mot clé), MAIS ON PEUT AUSSI FAIRE UN FILTRE PAR ATTRIBUTS (dans ce cas on skip la recherche dans les classes heritiéres, ca serait trop compliqué. On recherche seulement dans les attributs transversaux de la classe logs)
            Id_Filter(id_filter),                     //JE PROPOSE DE FAIRE UN FILTRE PAR SAISI CAR J'AVAIS L'IMPRESSION QUE C'ETAIT MOI COMPLIQUÉ A METTTRE EN PLACE. MAIS ON PEUT CHANGER CA, IL Y A AUCUN PROBLEME. SI ON PAR SUR UN FILTRE PAR ATTRIBUTS DES OBJETS, IL EST POSSIBLE QUE LES ATTRIBUTS DE CETTE CLASSE CHANGENT AUSSI EN CONSÉQUENCE.
            Asset_Type(asset_type),                   //SI ON PART SUR UN FILTRE PAR SAISI, IL FAUDRA BIEN SASSURER QUE LES DONNÉES DE NOS LOGS SOIENT TOUTES TRADUITES EN STRING AUSSI POUR FAIRE DES == QUI FONCTIONNENT.
            Filter_Criteria(filter_criteria) {}

    // Getters
    int getIdFilter() const { return Id_Filter; }
    AssetType getAssetType() const { return Asset_Type; }
    std::string getFilterCriteria() const { return Filter_Criteria; }

    // AJOUTER LE PROTOTYPE DE LA METHODE DE FILTRAGE

    // AJOUTER LE PROTOTYPE DE LA METHODE POUR AFFICHER LE RESULTAT DE LA RECHERCHE


private:
    int Id_Filter;
    AssetType Asset_Type;
    std::string Filter_Criteria;        //ON PEUT CHANGER LE TYPE DE FILTER CRITERIA POUR FAIRE UN FILTRE PAR ATTRIBUT.
};

