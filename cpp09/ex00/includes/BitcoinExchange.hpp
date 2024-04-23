
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

#define DATA_FILE "data.csv"

class BitcoinExchange
{
    private:
        std::string inputFile;
        std::map<std::string, double> bitcoinData;
        void isValidDate(std::string date);
        double getValue(std::string value);
        void isValidDatabase();

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &obj);
        BitcoinExchange& operator=(const BitcoinExchange &obj);
        ~BitcoinExchange();
        BitcoinExchange(std::string input);
        void execute();


};

#endif