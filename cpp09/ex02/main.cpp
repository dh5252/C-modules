
#include "includes/PmergeMe.hpp"

int returnInteger(std::string str)
{
    int num = 0;
    for (size_t i = 0 ; i < str.length() ; ++i) {
        if (!std::isdigit(str[i]))
            throw std::runtime_error("Error.");
        num *= 10;
        num += str[i] - '0';
    }
    return num;
}


int main(int argc, char **argv)
{
     if (argc < 2) {
        std::cerr << "Argument is not valid.\n";
        return (0); 
    }

    std::vector<int> data;
    try {
        for (int i = 1 ; i < argc ; ++i) {
            std::string tmp(argv[i]);
            std::istringstream ss(tmp);
            std::string str;
            
            while (std::getline(ss, str, ' ')) {
                if (str.empty())
                    continue;
                data.push_back(returnInteger(str));
            }
        }

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    PmergeMe a(data);

    a.executeDeque();

    clock_t vecTime = clock();
    a.executeVector();
    vecTime = clock() - vecTime;
    
    clock_t deqTime = clock();
    a.executeDeque();
    deqTime = clock() - deqTime;

    std::cout << "Before:  ";
    for (size_t i = 0 ; i < data.size() ; ++i)
        std::cout << " " << data[i];

    std::vector<int> vec = a.getVecRes();
    std::deque<int> deq = a.getDeqRes();

    std::cout << "\nAfter:   ";
    for (size_t i = 0 ; i < vec.size() ; ++i) {
        if (vec[i] == deq[i]) {
            if (i >= 1 && vec[i] < vec[i - 1]) {
                std::cout << "Test Failed" << std::endl;
                return 0;
            }
            std::cout << " " << vec[i];
        }
        else
            std::cout << "Test Failed" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << argc - 1 << " element with std::vector : " << (float)vecTime * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " element with std::deque : " << (float)deqTime * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
}