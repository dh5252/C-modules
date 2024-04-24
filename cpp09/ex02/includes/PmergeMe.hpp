
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <deque>
#include <limits.h>
#include <utility>

class PmergeMe
{
    private:
        std::vector<int> data;
        std::vector<int> jacobsthals;
        std::vector<int> vecRes;
        std::deque<int> deqRes;

        void makeSequenceVector(std::vector<int> &vec, int len);
        void makeSequenceDeque(std::deque<int> &deq, int len);

        void mergeVector(std::vector<std::pair<int, int> > &vec, int s, int m, int e);
        void mergeDeque(std::deque<std::pair<int, int> > &deq, int s, int m, int e);
        void mergeSortVector(std::vector<std::pair<int, int> > &vec, int s, int e);
        void mergeSortDeque(std::deque<std::pair<int, int> > &deq, int s, int e);


        int binarySearchVector(std::vector<int> &vec, int s, int e, int val);
        int binarySearchDeque(std::deque<int> &deq, int s, int e, int val);

        void insertionSortVector(std::vector<int> &main, std::vector<int> &sub);
        void insertionSortDeque(std::deque<int> &main, std::deque<int> &sub);

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &obj);
        PmergeMe &operator=(const PmergeMe &obj);
        PmergeMe(std::vector<int> _data);

        void executeVector();
        void executeDeque();

        std::vector<int> getVecRes() const;
        std::deque<int> getDeqRes() const;
};


#endif