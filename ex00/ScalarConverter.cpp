# include "ScalarConverter.hpp"
# include <cctype>
# include <cstdlib>
# include <limits>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

static bool isCharLiteral(const std::string &str)
{
    return (str.length() == 1 && !std::isdigit(str[0]));
}

static bool isPseudoLiteral(const std::string &str)
{
    return (str == "nan" || str == "+inf" || 
            str == "-inf" || str == "nanf" ||
            str == "+inff" || str == "-inff");
}

static bool isIntLiteral(const std::string &str)
{
    char *endptr;
    std::strtol(str.c_str(), &endptr, 10);
    return (*endptr == '\0');
}

static bool isFloatLiteral(const std::string &str)
{
    if(str[str.length() - 1] != 'f')
        return false;
    
    char *endptr;
    std::strtof(str.c_str(), &endptr);
    return (*endptr == 'f' && *(endptr + 1) == '\0');
}

static bool isDoubleLiteral(const std::string &str)
{
    char *endptr;
    std::strtod(str.c_str(), &endptr);
    return (*endptr == '\0');
}

static void printPseudoLiterals(const std::string &literal)
{
   std::cout << "char: impossible" << std::endl;
   std::cout << "int: impossible" << std::endl;

   if(literal == "nan" || literal == "+inf" || literal == "-inf")
   {
    std::cout << "float: " << literal << "f" << std::endl;
    std::cout << "double: " << literal << std::endl;
   }
   else
   {
    std::cout << "float: " << literal << std::endl;
    std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
   }
}

void ScalarConverter::convert(const std::string &literal)
{
    if(isPseudoLiteral(literal))
    {
        printPseudoLiterals(literal);
        return;
    }
}
