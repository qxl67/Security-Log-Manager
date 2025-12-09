#include "Log_linux.hpp"
#include <iostream>

void Log_linux::setProvider_Name(std::string m_Provider_Name)   {
    Provider_Name = m_Provider_Name;
}

std::string Log_linux::getProvider_Name() const   {
    return Provider_Name;
}