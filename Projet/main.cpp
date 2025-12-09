#include "Log.hpp"
#include "Log_linux.hpp"
#include "Log_windows.hpp"
#include <iostream>

int main() {
    Log test1;
    std::cout << test1.getProvider_Name();
    test1.setProvider_Name("test2");
    std::cout << test1.getProvider_Name();





    return 0;
}