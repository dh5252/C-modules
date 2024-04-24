
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
        std::map<std::string, float> bitcoinData;
        void isValidDate(std::string date);
        float getValue(std::string value);
        void isValidDatabase();
        void executeByInputFile();

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &obj);
        BitcoinExchange& operator=(const BitcoinExchange &obj);
        ~BitcoinExchange();
        BitcoinExchange(std::string input);
        void execute();


};

#endif