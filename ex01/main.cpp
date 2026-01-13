#include "Serializer.hpp"

int main()
{
    Data original;
    original.text = "Hello, Serialization!";
    original.number = 42;

    std::cout << GREEN << "Original Data:" << RESET << std::endl;
    std::cout << MAGENTA << "----------------" << RESET << std::endl;
    std::cout << CYAN << "Text: " << RESET << original.text << std::endl;
    std::cout << CYAN << "Number: " << RESET << original.number << std::endl;
    std::cout << MAGENTA << "----------------" << RESET << std::endl;

    Data *originalptr = &original;

    uintptr_t raw = Serializer::serialize(originalptr);
    Data *recoverdeptr = Serializer::deserialize(raw);

    std::cout << CYAN << "Original Pointer Address    : " << RESET << originalptr << std::endl;
    std::cout << CYAN << "Serialized Raw Value        : " << RESET << raw << std::endl;
    std::cout << CYAN << "Deserialized Pointer Address: " << RESET << recoverdeptr << std::endl;

    if(originalptr == recoverdeptr)
    {
        std::cout << GREEN << "✅ Pointers match!" << RESET << std::endl;
    }
    else
    {
        std::cout << RED << "❌ Pointers do not match!" << RESET << std::endl;
    }
    std::cout << MAGENTA << "----------------" << RESET << std::endl;
    std::cout << YELLOW << "Recovered Data -> number: " 
              << recoverdeptr->number 
              << ", text: "
              << recoverdeptr->text 
              << RESET << std::endl;
    return 0;
}