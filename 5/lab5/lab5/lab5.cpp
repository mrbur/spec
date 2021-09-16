#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <string>
using namespace std;

template<typename T>
void printUnique(T begin, T end) {
    set<std::iterator_traits<T>::value_type> stringSet;

    for (auto it = begin; it != end; it++) {
        stringSet.insert(*it);
    }
    cout << endl;
    for (auto it = stringSet.begin(); it != stringSet.end(); it++) {
        cout << *it << " ";
    }
}

int main()
{
    //1 task
    {
        vector<string> v = { "1", "2", "2" };
        list<string> l = { "1", "2", "2" };

        printUnique(v.begin(), v.end());
        printUnique(l.begin(), l.end());
    }
}
