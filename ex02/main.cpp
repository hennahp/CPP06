#include "Base.hpp"
#include "functions.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Base* ptr = generate();
    Base *john = 
    Base* invalid = NULL;

    std::cout << GREEN <<"Identifying using pointer:" << RESET << std::endl;
    identify(ptr);
    std::cout << GREEN <<"Identifying using reference:" << RESET << std::endl;
    identify(*ptr);
    std::cout << GREEN <<"Identifying nullptr using pointer:" << RESET << std::endl;
    identify(invalid);
    std::cout << GREEN <<"Identifying nullptr using reference:" << RESET << std::endl;
    identify(*invalid);
    delete ptr;

    return 0;
}