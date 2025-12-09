#include "Log.hpp"
#include <iostream>

void Log::setProvider_Name(std::string m_Provider_Name)   {
    Provider_Name = m_Provider_Name;
}

std::string Log::getProvider_Name() const   {
    return Provider_Name;
}