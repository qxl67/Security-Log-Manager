#include "Log_windows.hpp"
#include <iostream>

void Log_windows::setProvider_Name(std::string m_Provider_Name)   {
    Provider_Name = m_Provider_Name;
}

std::string Log_windows::getProvider_Name() const   {
    return Provider_Name;
}