#ifndef LOG_HPP
#define LOG_HPP
#include <iostream>
#include <ctime>

/**
 * @class Log
 * @brief Représente un log, il contient tout les caracteristiques d un log c est la definition meme d un log sans superflux.
 *
 * Cette classe est la base de tous les types de logs
 * (Linux_Security_Log, Linux_System_Log, Windows_Security_Log, Windows_System_Log).
 */
class Log {
    protected:
        /** @brief Identifiant unique du log */
        int ID_Log = -1;
        /** @brief Identifiant de processus */
        int PID = -1;
        /** @brief Date de creation du log */
        time_t time_stamp = 0;
        /** @brief Hote concerne par le log */
        std::string host = "";
        /** @brief User concerner par le log */
        std::string user = "";
        /** @brief Message de synthese du log (accessoire) */
        std::string synthesis_message = "";

    public:

        /**
        * @brief Constructeur de la classe Log.
        * @param id Identifiant unique du log
        * @param pid Identifiant du processus
        * @param time_stamp Date de creation
        * @param h Hote
        * @param u Utilisateur
        * @param synthesis_message Message de synthese
        */
        Log(int id, 
        const int& pid,
        const time_t& time_stamp,
        const std::string& h,
        const std::string& u,
        const std::string& synthesis_message);

        /**
        * @brief Destructeur de la classe Log.
        */
        virtual ~Log();

        /**
        * @brief Compare deux logs par leur timestamp via "<".
        * @param other Log à comparer
        * @return true si ce log est plus ancien que other
        */
        bool operator<(const Log& other) const {
            return this->getTimeStamp() < other.getTimeStamp();
        }
        
        /**
        * @brief Compare deux logs par leur timestamp via ">".
        * @param other Log à comparer
        * @return true si ce log est plus ancien que other
        */
        bool operator>(const Log& other) const {
            return this->getTimeStamp() > other.getTimeStamp();
        }

        /**
        * @brief Compare deux logs par leur timestamp via "==".
        * @param other Log à comparer
        * @return true si ce log est plus ancien que other
        */
        bool operator==(const Log& other) const {
            return this->getTimeStamp() == other.getTimeStamp();
        }

        /**
        * @brief Instantialisisation de synthesis_message.
        */
        void setSynthesisMessage(const std::string& message);
        
        /**
        * @brief Recupere ID_Log.
        * @return Un int.
        */
        virtual int getId() const;

        /**
        * @brief Recupere time_stamp.
        * @return Un time_t.
        */
        time_t getTimeStamp() const;

        /**
        * @brief Recupere user.
        * @return Un string.
        */
        virtual std::string getUser() const;

        /**
        * @brief Retourne le Keywords associés au log (evite une erreur puis log ne possede pas d attribut Keywords).
        * @return Keywords.
        */
        virtual std::string getKeywords() const { return ""; }
        
        /**
        * @brief Retourne l Action associés au log (evite une erreur puis log ne possede pas d attribut Action).
        * @return Action.
        */
        virtual std::string getAction() const { return ""; }

        /**
        * @brief Affiche un objet de type Log.
        */
        virtual void afficher() const;
};

/**
 * @class Windows_System_Log
 * @brief Représente un log système de windows.
 */
class Windows_System_Log : public Log{
    private:

        /** @brief Name du log */
        std::string name = "";

        /** @brief Globally Unique Identifier du log */
        std::string guid = "";

        /** @brief Numero de l evenement du log */
        int event_ID = -1;

        /** @brief Version utilisee lorsque le log a eu lieu */
        std::string version = "";

        /** @brief Level du log */
        std::string level = "";

        /** @brief Task du log */
        std::string task = "";

        /** @brief Opcode du log */
        std::string opcode = "";

        /** @brief Keywords du log */
        std::string keywords = "";

        /** @brief eventRecordID du log */
        std::string eventRecordID = "";

        /** @brief activityID du log */
        std::string activityID = "";

        /** @brief threadID du log */
        std::string threadID = "";

        /** @brief channel du log */
        std::string channel = "";

        /** @brief eventData du log */
        std::string eventData = "";

    public:

        /**
        * @brief Constructeur de la classe Windows_System_Log.
        * @param base Obejt de type Log qui forme la base de ce log
        * @param name Name du log
        * @param guid Globally Unique Identifier du log
        * @param event_ID Numero de l evenement du log
        * @param version Version utilisee lorsque le log a eu lieu
        * @param level Level du log
        * @param task Task du log
        * @param opcode Opcode du log
        * @param keywords Keywords du log
        * @param eventRecordID eventRecordID du log
        * @param activityID activityID du log
        * @param threadID threadID du log
        * @param channel channel du log
        * @param eventData eventData du log
        */
        Windows_System_Log(
            const Log& base,
            //Au dessus attributs de Log, en dessous attributs de la classe héritière
            const std::string& name,
            const std::string& guid,
            const int& event_ID,
            const std::string& version,
            const std::string& level,
            const std::string& task,
            const std::string& opcode,
            const std::string& keywords,
            const std::string& eventRecordID,
            const std::string& activityID,
            const std::string& threadID,
            const std::string& channel,
            const std::string& eventData);
        
        /**
        * @brief Destructeur de la classe Windows_Security_Log.
        */
        ~Windows_System_Log() override;
        
        /**
        * @brief Affiche un objet de type Windows_Security_Log.
        */
        void afficher() const override;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class Windows_Security_Log
 * @brief Représente un log secure de windows.
 */
class Windows_Security_Log : public Log{
    private:

        /** @brief Name du log */
        std::string name = "";

        /** @brief Globally Unique Identifier du log */
        std::string guid = "";

        /** @brief Numero de l evenement du log */
        int event_ID = -1;

        /** @brief Version utilisee lorsque le log a eu lieu */
        std::string version = "";

        /** @brief Level du log */
        std::string level = "";

        /** @brief Task du log */
        std::string task = "";

        /** @brief Opcode du log */
        std::string opcode = "";

        /** @brief Keywords du log */
        std::string keywords = "";

        /** @brief eventRecordID du log */
        std::string eventRecordID = "";

        /** @brief activityID du log */
        std::string activityID = "";

        /** @brief threadID du log */
        std::string threadID = "";

        /** @brief channel du log */
        std::string channel = "";

        /** @brief eventData du log */
        std::string eventData = "";

    public:

        /**
        * @brief Constructeur de la classe Windows_System_Log.
        * @param base Obejt de type Log qui forme la base de ce log
        * @param name Name du log
        * @param guid Globally Unique Identifier du log
        * @param event_ID Numero de l evenement du log
        * @param version Version utilisee lorsque le log a eu lieu
        * @param level Level du log
        * @param task Task du log
        * @param opcode Opcode du log
        * @param keywords Keywords du log
        * @param eventRecordID eventRecordID du log
        * @param activityID activityID du log
        * @param threadID threadID du log
        * @param channel channel du log
        * @param eventData eventData du log
        */
        Windows_Security_Log(
            const Log& base,
            //Au dessus attributs de Log, en dessous attributs de la classe héritière
            const std::string& name,
            const std::string& guid,
            const int& event_ID,
            const std::string& version,
            const std::string& level,
            const std::string& task,
            const std::string& opcode,
            const std::string& keywords,
            const std::string& eventRecordID,
            const std::string& activityID,
            const std::string& threadID,
            const std::string& channel,
            const std::string& eventData);

        /**
        * @brief Destructeur de la classe Log.
        */
        ~Windows_Security_Log() override;

        /**
        * @brief Retourne le keywords associés au log.
        * @return Keywords.
        */
        std::string getKeywords() const override;

        /**
        * @brief Affiche un objet de type Log.
        */
        void afficher() const override;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class Windows_System_Log
 * @brief Représente un log système de windows.
 */
class Linux_System_Log : public Log{
    private:

        /** @brief Processus du log */
        std::string process = "";

        /** @brief Severity du log */
        std::string severity = "";

        /** @brief Message du log */
        std::string message = "";

    public:

        /**
        * @brief Constructeur de la classe Linux_System_Log.
        * @param base Obejt de type Log qui forme la base de ce log
        * @param process Processus du log
        * @param severity Severity du log
        * @param message Message du log
        */
        Linux_System_Log(
            const Log& base,
            //Au dessus attributs de Log, en dessous attributs de la classe héritière
            const std::string& process,
            const std::string& severity,
            const std::string& message);
        
        /**
        * @brief Destructeur de la classe Linux_System_Log.
        */
        ~Linux_System_Log() override;

        /**
        * @brief Affiche un objet de type Linux_System_Log.
        */
        void afficher() const override;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Linux_Security_Log : public Log{
    private:

        /** @brief Processus du log */
        std::string process = "";

        /** @brief Severity du log */
        std::string severity = "";

        /** @brief action du log */
        std::string action = "";

        /** @brief Source ip du log */
        std::string source_ip = "";

        /** @brief Message du log */
        std::string message = "";

    public:

        /**
        * @brief Constructeur de la classe Linux_System_Log.
        * @param base Obejt de type Log qui forme la base de ce log
        * @param process Processus du log
        * @param severity Severity du log
        * @param action Action du log
        * @param source_ip Source ip du log
        * @param message Message du log
        */
        Linux_Security_Log(
            const Log& base,
            //Au dessus attributs de Log, en dessous attributs de la classe héritière
            const std::string& process,
            const std::string& severity,
            const std::string& action,
            const std::string& source_ip,
            const std::string& message);

        /**
        * @brief Destructeur de la classe Linux_Security_Log.
        */
        ~Linux_Security_Log() override;

        /**
        * @brief Retourne l Action associés au log.
        * @return Action.
        */
        std::string getAction() const override;
        
        /**
        * @brief Affiche un objet de type Linux_Security_Log.
        */
        void afficher() const override;
};

#endif