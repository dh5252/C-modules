
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
                throw std::runtime_error("data is invalid");
            else
                date[i] = ' ';
        }
        else if (!std::isdigit(date[i]))
            throw std::runtime_error("data is invalid");
    }

    std::stringstream ss(date);
    int y, m, d;
    ss >> y >> m >> d;

    if (y > 9999 || y < 2009)
        throw std::runtime_error("year is invalid");
    else if (m < 1 || m > 12)
        throw std::runtime_error("month is invalid");
    else {
        if (m == 2) {
            if ((y % 4 == 0 && y % 100) || y % 4 == 0) {
                if (d < 1 || d > 29)
                    throw std::runtime_error("day is invalid");
            }
            else if (d < 1 || d > 28)
                throw std::runtime_error("day is invalid");
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11) {
            if (d < 1 || d > 30)
                throw std::runtime_error("day is invalid");
        }
        else {
            if (d < 1 || d > 31)
                throw std::runtime_error("day is invalid");
        }
    }
}

double BitcoinExchange::getValue(std::string value)
{
    int dotCount = 0;
    for (size_t i = 0 ; i < value.length() ; ++i) {
        if (std::isdigit(value[i]))
            continue;
        if (i == 0)
            throw std::runtime_error("value is invalid");
        else if (value[i] == '.')
            dotCount++;
        else
            throw std::runtime_error("value is invalid");
    }
    if (dotCount > 1)
        throw std::runtime_error("value is invalid");

    std::istringstream iss(value);

    double val;

    if (!(iss >> val))
        throw std::runtime_error("value is invalid");
    
    if (val < 0)
        throw std::runtime_error("value is minus");

    return val;
}

void BitcoinExchange::isValidDatabase()
{
    std::ifstream data(DATA_FILE);
    std::string readline;

    if (!data) 
        throw std::runtime_error("no database file");
    
    if (std::getline(data, readline).eof())
        throw std::runtime_error("file is empty");
    else if (readline != "date,exchange_rate")
        throw std::runtime_error("data is invalid");

    std::string before = "2008-12-31";
    while (std::getline(data, readline)) {
        if (readline.length() <= 10)
            throw std::runtime_error("data is invalid");
        else if (readline[10] != ',')
            throw std::runtime_error("data is invalid");

        std::string date = readline.substr(0, 10);
        std::string value = readline.substr(11);

        isValidDate(date);
        double val = getValue(value);

        if (date <= before)
            throw std::runtime_error("data order is invalid");
        before = date;

        bitcoinData.insert(std::make_pair(date, val));
    }
}

void BitcoinExchange::execute()
{
    isValidDatabase();
}