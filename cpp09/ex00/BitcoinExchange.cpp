
#include "includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
    this->inputFile = obj.inputFile;
    this->bitcoinData = obj.bitcoinData;
}

BitcoinExchange::BitcoinExchange(std::string input)
{
    this->inputFile = input;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    if (this == &obj)
        return *this;
    
    this->inputFile = obj.inputFile;
    this->bitcoinData = obj.bitcoinData;
    return *this;
}

void BitcoinExchange::isValidDate(std::string date)
{
    for (size_t i = 0 ; i < date.length() ; ++i) {
        if (i == 4 || i == 7) {
            if (date[i] != '-')
                throw std::runtime_error("Error: date is invalid.");
            else
                date[i] = ' ';
        }
        else if (!std::isdigit(date[i]))
            throw std::runtime_error("Error: date is invalid.");
    }

    std::stringstream ss(date);
    int y, m, d;
    ss >> y >> m >> d;

    if (y > 9999 || y < 2009)
        throw std::runtime_error("Error: date is invalid.");
    else if (m < 1 || m > 12)
        throw std::runtime_error("Error: date is invalid.");
    else {
        if (m == 2) {
            if ((y % 4 == 0 && y % 100) || y % 4 == 0) {
                if (d < 1 || d > 29)
                    throw std::runtime_error("Error: date is invalid.");
            }
            else if (d < 1 || d > 28)
                throw std::runtime_error("Error: date is invalid.");
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11) {
            if (d < 1 || d > 30)
                throw std::runtime_error("Error: date is invalid.");
        }
        else {
            if (d < 1 || d > 31)
                throw std::runtime_error("Error: date is invalid.");
        }
    }
}

float BitcoinExchange::getValue(std::string value)
{
    int dotCount = 0;
    for (size_t i = 0 ; i < value.length() ; ++i) {
        if (std::isdigit(value[i]))
            continue;
        if (i == 0) {
            if (value[i] != '-')
                throw std::runtime_error("Error: value is invalid.");
        }
        else if (value[i] == '.')
            dotCount++;
        else
            throw std::runtime_error("Error: value is invalid.");
    }
    if (dotCount > 1)
        throw std::runtime_error("Error: value is invalid.");

    std::istringstream iss(value);

    double val;
    if (!(iss >> val))
        throw std::runtime_error("Error: value is invalid.");
    
    if (val < 0)
        throw std::runtime_error("Error: not a positive number.");

    return val;
}

void BitcoinExchange::isValidDatabase()
{
    std::ifstream data(DATA_FILE);
    std::string readline;

    if (!data) 
        throw std::runtime_error("Error: no database file");
    
    if (std::getline(data, readline).eof())
        throw std::runtime_error("Error: file is empty");
    else if (readline != "date,exchange_rate")
        throw std::runtime_error("Error: data is invalid");

    std::string before = "2008-12-31";
    while (std::getline(data, readline)) {
        if (readline.length() <= 10)
            throw std::runtime_error("Error: data is invalid");
        else if (readline[10] != ',')
            throw std::runtime_error("Error: data is invalid");

        std::string date = readline.substr(0, 10);
        std::string value = readline.substr(11);

        isValidDate(date);
        float val = getValue(value);

        if (date <= before)
            throw std::runtime_error("Error: data order is invalid");
        before = date;

        bitcoinData.insert(std::make_pair(date, val));
    }
}

void BitcoinExchange::executeByInputFile()
{
    std::ifstream data(this->inputFile);
    std::string readline;

    if (!data) 
        throw std::runtime_error("Error: could not open file.");
    
    if (std::getline(data, readline).eof())
        throw std::runtime_error("Error: input file is empty");
    else if (readline != "date | value")
        throw std::runtime_error("Error: input file is invalid");
    
    while (std::getline(data, readline)) {
        try {
            if (readline.length() < 14)
                throw std::runtime_error("Error: bad input => " + readline);
            else if (readline.substr(10, 3) != " | ")
                throw std::runtime_error("Error: bad input => " + readline);

            std::string date = readline.substr(0, 10);
            std::string value = readline.substr(13);

            isValidDate(date);
            float val = getValue(value);
            if (val <= 0)
                throw std::runtime_error("Error: not a positive number.");
            else if (val >= 1000)
                throw std::runtime_error("Error: too large a number.");

            std::map<std::string, float>::iterator it = bitcoinData.find(date);
            if (it != bitcoinData.end()) {
                std::cout << date << " => " << val << " = " << it->second * val << std::endl;
            }
            else {
                it = bitcoinData.lower_bound(date);
                if (it == bitcoinData.begin())
                    throw std::runtime_error("Error: input is invalid.");
                --it;
                std::cout << date << " => " << val << " = " << it->second * val << std::endl;
            }
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void BitcoinExchange::execute()
{
    isValidDatabase();
    executeByInputFile();
}