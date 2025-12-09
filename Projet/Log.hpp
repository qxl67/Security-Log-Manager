#ifndef LOG_HPP
#define LOG_HPP
#include <iostream>

class Log {
    private:
        std::string Provider_Name;
        // attributs et fonctions privées

    public:
        void setProvider_Name(std::string Provider_Name);
        std::string getProvider_Name() const;
        // attributs et fonctions publiques
};

#endif