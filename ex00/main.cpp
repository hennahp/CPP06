# include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << RED << "Usage: ./scalar_converter <literal_value>" << RESET << std::endl;
        return 1;
    }
    std::cout << BLUE << "Converting literal: " << av[1] << RESET << std::endl;
    ScalarConverter::convert(av[1]);
    return 0;
}