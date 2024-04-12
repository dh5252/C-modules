
#include "includes/MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "\n<basic test>\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "\n<upcasting test>\n";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }

    std::cout << "\n\n<list test>\n";
    MutantStack<int> test1;
    std::list<int> test2;

    for (int i = 0 ; i < 10 ; ++i) {
        test1.push(i);
        test2.push_back(i);
    }
    it = test1.begin();
    std::list<int>::iterator it2 = test2.begin();
    while (it != test1.end()) {
        std::cout << *it << " " << *it2 << "\n";
        it++;
        it2++;
    }
    return 0;
}
