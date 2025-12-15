#include <iostream>
#include "Logs.hpp"

class Event_Log_Filter {
public:
    enum class AssetType {
        SECURITY_EVENT,
        LOGS
    };

    // Constructeur 
    Event_Log_Filter(int id_filter,
        AssetType asset_type = AssetType::SECURITY_EVENT,
        const std::string& filter_criteria = ""):     //preciser qu'il faut seulement saisir l'une des valeur allouée aux attributs de la classe Logs (pas de recherche dans les classe heritiére, ca serait trop compliqué)
            Id_Filter(id_filter),
            Asset_Type(asset_type),
            Filter_Criteria(filter_criteria) {}

    // Getters
    int getIdFilter() const { return Id_Filter; }
    AssetType getAssetType() const { return Asset_Type; }
    std::string getFilterCriteria() const { return Filter_Criteria; }

    // Méthodes de filtrage
    //std::vector<Logs*> applyFilter(const std::vector<Logs*>& logs) const;

private:
    int Id_Filter;
    AssetType Asset_Type;
    std::string Filter_Criteria;
};

