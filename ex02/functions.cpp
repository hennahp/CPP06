#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate()
{
    int randNum = std::rand() % 3;
    switch(randNum)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL; 
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << CYAN <<"Identified type: A" << RESET << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << CYAN <<"Identified type: B" << RESET << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << CYAN <<"Identified type: C" << RESET << std::endl;
    else
        std::cout << RED <<"Unknown type" << RESET << std::endl;
}

void identify(Base& p)
{
    try{(void)dynamic_cast<A&>(p); 
        std::cout << CYAN <<"Identified type: A" << RESET << std::endl; 
        return;}
    catch(...){}
    try{(void)dynamic_cast<B&>(p); 
        std::cout << CYAN <<"Identified type: B" << RESET << std::endl; 
        return;}
    catch(...){}
    try{(void)dynamic_cast<C&>(p);
        std::cout << CYAN <<"Identified type: C" << RESET << std::endl; 
        return;}
    catch(...){}
    std::cout << RED <<"Unknown type" << RESET << std::endl;
}