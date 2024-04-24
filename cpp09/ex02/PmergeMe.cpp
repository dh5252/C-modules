

#include "includes/PmergeMe.hpp"

std::vector<int> PmergeMe::getVecRes() const
{
    return vecRes;
}

std::deque<int> PmergeMe::getDeqRes() const
{
    return deqRes;
}

void PmergeMe::mergeVector(std::vector<std::pair<int, int> > &vec, int s, int m, int e)
{
    int i, j, k, l;
    i = s;
    j = m + 1;
    k = s;

    std::vector<std::pair<int, int> > sorted(vec.size());

    while (i <= m && j <= e) {
        if (vec[i].first <= vec[j].first)
            sorted[k++] = vec[i++];
        else
            sorted[k++] = vec[j++];
    }
    if (i > m)
    {
        for (l = j ; l <= e ; l++)
            sorted[k++] = vec[l];
    }
    else
    {
        for (l = i ; l <= m ; l++)
            sorted[k++] = vec[l];
    }
    for (l = s ; l <= e ; ++l)
        vec[l] = sorted[l];
}

void PmergeMe::mergeSortVector(std::vector<std::pair<int, int> > &vec, int s, int e)
{
    int m;
    if (s >= e)
        return ;
    m = (s + e) / 2;
    this->mergeSortVector(vec, s, m);
    this->mergeSortVector(vec, m + 1, e);
    this->mergeVector(vec, s, m, e);
}

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    if (this == &obj)
        return *this;
    this->data = obj.data;
    this->jacobsthals = obj.data;
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
    this->data = obj.data;
    this->jacobsthals = obj.data;
}

PmergeMe::PmergeMe(std::vector<int> _data)
{
    this->data = _data;

    this->jacobsthals.clear();
    this->jacobsthals.push_back(1);
    this->jacobsthals.push_back(1);
    for (int i = 2 ; ; ++i) {
        if (jacobsthals[i - 1] + 2 * jacobsthals[i - 2] > 3000)
            break;
        jacobsthals.push_back(jacobsthals[i - 1] + 2 * jacobsthals[i - 2]);
    }
}

void PmergeMe::makeSequenceVector(std::vector<int> &vec, int len)
{
    int k = 1;
    int index = 0;

    while ((int)vec.size() < len) {
        vec.push_back(index);

        if (index - 1 <= jacobsthals[k - 1] - 1) {
            k++;
            index = std::min(jacobsthals[k] - 1, len - 1);
        }
        else
            --index;
    }
}

int PmergeMe::binarySearchVector(std::vector<int> &vec, int s, int e, int val)
{
    int mid;

    while (s < e) {
        mid = (s + e) / 2;
        if (vec[mid] < val)
            s = mid + 1;
        else
            e = mid;
    }
    return e;
}

void PmergeMe::insertionSortVector(std::vector<int> &main, std::vector<int> &sub)
{
    int s, e;
    int addCount = 0;
    int jacobIdx = 1;

    std::vector<int> sequence;
    makeSequenceVector(sequence, sub.size());
    s = 0;
    e = 0;

    for (size_t i = 0 ; i < sequence.size() ; ++i) {
        if (sequence[i] == jacobsthals[jacobIdx + 1] - 1) {
            jacobIdx++;
            e = jacobsthals[jacobIdx] - 1;
        }
        else if (sequence[i] == (int)sub.size() - 1) {
            e = (int)sub.size() - 1;
        }
        int insertLoc = binarySearchVector(main, s, e + addCount, sub[sequence[i]]);
        main.insert(main.begin() + insertLoc, sub[sequence[i]]);
        addCount++;
    }
    if (data.size() == 1) 
        main.push_back(data.back());
    else if (data.size() % 2 != 0) {
        int insertLoc = binarySearchVector(main, s, e + addCount + 1, data.back());
        main.insert(main.begin() + insertLoc, data.back());
    }
}

void PmergeMe::mergeDeque(std::deque<std::pair<int, int> > &deq, int s, int m, int e)
{
    int i, j, k, l;
    i = s;
    j = m + 1;
    k = s;

    std::deque<std::pair<int, int> > sorted(deq.size());

    while (i <= m && j <= e) {
        if (deq[i].first <= deq[j].first)
            sorted[k++] = deq[i++];
        else
            sorted[k++] = deq[j++];
    }
    if (i > m)
    {
        for (l = j ; l <= e ; l++)
            sorted[k++] = deq[l];
    }
    else
    {
        for (l = i ; l <= m ; l++)
            sorted[k++] = deq[l];
    }
    for (l = s ; l <= e ; ++l)
        deq[l] = sorted[l];
}

void PmergeMe::mergeSortDeque(std::deque<std::pair<int, int> > &deq, int s, int e)
{
    int m;
    if (s >= e)
        return ;
    m = (s + e) / 2;
    this->mergeSortDeque(deq, s, m);
    this->mergeSortDeque(deq, m + 1, e);
    this->mergeDeque(deq, s, m, e);
}

void PmergeMe::makeSequenceDeque(std::deque<int> &deq, int len)
{
    int k = 1;
    int index = 0;

    while ((int)deq.size() < len) {
        deq.push_back(index);

        if (index - 1 <= jacobsthals[k - 1] - 1) {
            k++;
            index = std::min(jacobsthals[k] - 1, len - 1);
        }
        else
            --index;
    }
}

int PmergeMe::binarySearchDeque(std::deque<int> &deq, int s, int e, int val)
{
    int mid;

    while (s < e) {
        mid = (s + e) / 2;
        if (deq[mid] < val)
            s = mid + 1;
        else
            e = mid;
    }
    return e;
}

void PmergeMe::insertionSortDeque(std::deque<int> &main, std::deque<int> &sub)
{
    int s, e;
    int addCount = 0;
    int jacobIdx = 1;

    std::deque<int> sequence;
    makeSequenceDeque(sequence, sub.size());
    s = 0;
    e = 0;

    for (size_t i = 0 ; i < sequence.size() ; ++i) {
        if (sequence[i] == jacobsthals[jacobIdx + 1] - 1) {
            jacobIdx++;
            e = jacobsthals[jacobIdx] - 1;
        }
        else if (sequence[i] == (int)sub.size() - 1) {
            e = (int)sub.size() - 1;
        }
        int insertLoc = binarySearchDeque(main, s, e + addCount, sub[sequence[i]]);
        main.insert(main.begin() + insertLoc, sub[sequence[i]]);
        addCount++;
    }

    if (data.size() == 1) 
        main.push_back(data.back());
    else if (data.size() % 2 != 0) {
        int insertLoc = binarySearchDeque(main, s, e + addCount + 1, data.back());
        main.insert(main.begin() + insertLoc, data.back());
    }
}

void PmergeMe::executeVector()
{
    std::vector<std::pair<int, int> > pre;
    
    for (size_t i = 0 ; i + 1 < data.size() ; i += 2) {
        if (data[i + 1] > data[i])
            pre.push_back(std::make_pair(data[i + 1], data[i]));
        else
            pre.push_back(std::make_pair(data[i], data[i + 1]));
    }

    mergeSortVector(pre, 0, pre.size() - 1);
    
    std::vector<int> main;
    std::vector<int> sub;
    for (size_t i = 0 ; i < pre.size() ; ++i) {
        main.push_back(pre[i].first);
        sub.push_back(pre[i].second);
    }
    insertionSortVector(main, sub);

    vecRes = main;
}

void PmergeMe::executeDeque()
{
    std::deque<std::pair<int, int> > pre;
    
    for (size_t i = 0 ; i + 1 < data.size() ; i += 2) {
        if (data[i + 1] > data[i])
            pre.push_back(std::make_pair(data[i + 1], data[i]));
        else
            pre.push_back(std::make_pair(data[i], data[i + 1]));
    }

    mergeSortDeque(pre, 0, pre.size() - 1);
    
    std::deque<int> main;
    std::deque<int> sub;
    for (size_t i = 0 ; i < pre.size() ; ++i) {
        main.push_back(pre[i].first);
        sub.push_back(pre[i].second);
    }
    insertionSortDeque(main, sub);

    deqRes = main;
}