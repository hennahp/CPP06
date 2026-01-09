# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

static bool isValidLiteral(char *end)
{
    if(*end == '\0')
        return true;
    if(*end == 'f' && *(end + 1) == '\0')
        return true;
    return false;
}

static void printChar(long double value)
{
    std::cout << BOLDGREEN << "char   :" << RESET;
    if(value < CHAR_MIN || value > CHAR_MAX || value != static_cast<int>(value))
        std::cout <<"impossible" << std::endl;
    else if(value < 32 || value > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(long double value)
{
    std::cout << BOLDGREEN << "int    :" << RESET;
    if(value < INT_MIN || value > INT_MAX || std::isnan(value) || std::isinf(value))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(long double value)
{
    std::cout << BOLDGREEN << "float  :" << RESET;
    if((value < -std::numeric_limits<float>::max() || 
        value > std::numeric_limits<float>::max()) && 
        !std::isinf(value))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    float fvalue = static_cast<float>(value);
    std::cout << fvalue;
    if(fvalue == static_cast<int>(fvalue))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

static void printDouble(long double value)
{
    std::cout << BOLDGREEN << "double :" << RESET;
    if ((value < -std::numeric_limits<double>::max() ||
        value > std::numeric_limits<double>::max()) &&
        !std::isinf(value))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    double dvalue = static_cast<double>(value);
    std::cout << dvalue;
    if(dvalue == static_cast<int>(dvalue))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    if(literal.length() == 1 && !std::isdigit(literal[0]))
    {
        char c = literal[0];
        printChar(c);
        printInt(c);
        printFloat(c);
        printDouble(c);
        return;
    }

    char *endptr;
    long double value = std::strtold(literal.c_str(), &endptr);
    if(!isValidLiteral(endptr))
    {
        std::cerr << RED << "Error: Invalid literal value." << RESET << std::endl;
        return;
    }
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}