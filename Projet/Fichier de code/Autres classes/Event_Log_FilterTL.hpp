#include <iostream>

class Event_Log_Filter {

public: 
    enum class SortBy {
        DATE_HEURE,
        LEVEL
    };

// Permet de creer le constructeur
    Event_Log_Filter(int id_filter,
        const std::string& filter_criteria = "", //on part sur un principe de barre de recherche. On saisi une donnée
        SortBy sort_by = SortBy::DATE_HEURE):
            Id_Filter(id_filter),
            Filter_Criteria(filter_criteria),
            Sort_By(sort_by) {}

// Getters
// a commenter selon les besoins
    int getIdFilter() const { return Id_Filter; }
    std::string getFilterCriteria() const { return Filter_Criteria; }
    SortBy getSortBy() const { return Sort_By; }
    

private:
    int Id_Filter;
    std::string Filter_Criteria;
    SortBy Sort_By;

//AJOUTER LES METHODES
    //On veut renvoyer les valeurs du eventlogfilter pour reformater les le visuel des Logs. On est a priori sur une methode virtuel

     // Méthode pour appliquer le filtre sur une liste de logs
    std::vector<std::string> applyFilter(const std::vector<std::string>& logs) const;

    // Méthode pour trier les logs
    std::vector<std::string> sortLogs(std::vector<std::string> logs) const;

};

