#include "Log_collector.hpp"
#include "Log.hpp"
#include "Global_Id_Log.hpp"

#include "pugixml.hpp"

#include <vector>
#include <iostream>
#include <iomanip>
#include <memory>
#include <sstream>
#include <ctime>

int Global_Id_Log = 0; // Id Log

time_t convertisseur_date(const std::string& date)  {
    std::tm tm = {};
    std::istringstream ss(date);

    ss >> std::get_time(&tm, "%Y/%m/%d %H:%M:%S");

    if (ss.fail()) {
        throw std::runtime_error("Format de date invalide : " + date);
    }

    return std::mktime(&tm); // heure locale
}

Log_collector::Log_collector(const std::string& path)
    : chemin(path) 
    {
    //
    }

Log_collector::~Log_collector() {
    // ressources à libérer
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<std::unique_ptr<Log>> Log_collector::importer()   {
    std::vector<std::unique_ptr<Log>> logs;
    pugi::xml_document xml;
    pugi::xml_parse_result parsing = xml.load_file(chemin.c_str());
    if (xml.child("Events").attribute("log_type")) {
        // l’attribut existe linux
        if (xml.child("Events").attribute("log_type").as_string() == std::string("secure")) {
            // linux sec
            pugi::xml_node Events = xml.child("Events");
            for (pugi::xml_node Event : Events.children("event")) {
                logs.push_back(std::make_unique<Linux_Security_Log>(
                    Log(Global_Id_Log++,
                    Event.child("pid").text().as_int(),
                    convertisseur_date(Event.child("timestamp").text().as_string()), //a modifier
                    Event.child("hostname").text().as_string(),
                    Event.child("user").text().as_string(),
                    ""),
                    
                    Event.child("process").text().as_string(),
                    Event.child("sevenity").text().as_string(),
                    Event.child("action").text().as_string(),
                    Event.child("source_ip").text().as_string(),
                    Event.child("message").text().as_string()
                ));
            }
            return logs;
        } else {
            // linux sys
            pugi::xml_node Events = xml.child("Events");
            for (pugi::xml_node Event : Events.children("event")) {
                logs.push_back(std::make_unique<Linux_System_Log>(
                    Log(Global_Id_Log++,
                    Event.child("pid").text().as_int(),
                    convertisseur_date(Event.child("timestamp").text().as_string()), //a modifier
                    Event.child("hostname").text().as_string(),
                    Event.child("user").text().as_string(),
                    ""),

                    Event.child("process").text().as_string(),
                    Event.child("sevenity").text().as_string(),
                    Event.child("message").text().as_string()
                ));
            }
            return logs;
            }
    } else if (xml.child("Events").child("Event").child("System").child("Provider").attribute("Name").as_string() == std::string("Microsoft-Windows-Security-Auditing")) { // si c'est du windows secure
        // windows sec
        for (pugi::xml_node Event : xml.child("Events").children("Event")) {
            pugi::xml_node System = Event.child("System");
            pugi::xml_node EventData = Event.child("EventData");
            std::ostringstream oss;
            for (pugi::xml_node data : EventData.children())    {
                data.print(oss);
                }
            std::string eventDataStr = oss.str(); // CHatGPT
            logs.push_back(std::make_unique<Windows_Security_Log>(
                Log(Global_Id_Log++,
                System.child("Execution").attribute("ProcessID").as_int(),
                convertisseur_date(System.child("TimeCreated").attribute("SystemTime").as_string()),
                System.child("Computer").text().as_string(),
                "",
                ""),

                System.child("Provider").attribute("Name").as_string(),
                System.child("Provider").attribute("Guid").as_string(),
                System.child("EventID").text().as_int(),
                System.child("Version").text().as_string(),
                System.child("Level").text().as_string(),
                System.child("Task").text().as_string(),
                System.child("Opcode").text().as_string(),
                System.child("Keywords").text().as_string(),
                System.child("EventRecordID").text().as_string(),
                System.child("Correlation").attribute("ActivityID").as_string(),
                System.child("Execution").attribute("ThreadID").as_string(),
                System.child("Channel").text().as_string(),
                eventDataStr
            ));
        }
        return logs;
    } else {
        // windows sys
        for (pugi::xml_node Event : xml.child("Events").children("Event")) {
            pugi::xml_node System = Event.child("System");
            pugi::xml_node EventData = Event.child("EventData");
            std::ostringstream oss;
            for (pugi::xml_node data : EventData.children())    {
                data.print(oss);
                }
            std::string eventDataStr = oss.str();
            logs.push_back(std::make_unique<Windows_System_Log>(
                Log(Global_Id_Log++,
                System.child("Execution").attribute("ProcessID").as_int(),
                convertisseur_date(System.child("TimeCreated").attribute("SystemTime").as_string()),
                System.child("Computer").text().as_string(),
                System.child("Security").attribute("UserID").as_string(),
                ""),

                System.child("Provider").attribute("Name").as_string(),
                System.child("Provider").attribute("Guid").as_string(),
                System.child("EventID").text().as_int(),
                System.child("Version").text().as_string(),
                System.child("Level").text().as_string(),
                System.child("Task").text().as_string(),
                System.child("Opcode").text().as_string(),
                System.child("Keywords").text().as_string(),
                System.child("EventRecordID").text().as_string(),
                System.child("Correlation").attribute("ActivityID").as_string(),
                System.child("Execution").attribute("ThreadID").as_string(),
                System.child("Channel").text().as_string(),
                eventDataStr
            ));
    }
    return logs;
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

