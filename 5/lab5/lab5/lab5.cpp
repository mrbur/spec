#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <functional>


using namespace std;

template<typename T>
void printUnique(T begin, T end) {
    set<std::iterator_traits<T>::value_type> stringSet;

    for (auto it = begin; it != end; it++) {
        stringSet.insert(*it);
    }
    for (auto it = stringSet.begin(); it != stringSet.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

struct Compare
{
    bool operator()(const string str, const string str1) const { return str.length() > str1.length(); }
};

int main()
{
    //1 task
    {
        vector<string> v = { "1", "2", "2" };
        list<string> l = { "1", "2", "2" };

        printUnique(v.begin(), v.end());
        printUnique(l.begin(), l.end());
    }

    //2 lab
    {
        multiset <string, Compare> stringMultiset;

        char ch;
        string str;

        string line;
        if (getline(cin, line)) {
            size_t pos = 0;
            string token;
            while ((pos = line.find(".")) != string::npos) {
                token = line.substr(0, pos + 1);
                if(token.length() > 1)stringMultiset.insert(token);
                line.erase(0, pos + 1);
            }
        }
        if (line.length() > 0) {
            stringMultiset.insert(line);
        }
        
        cout << endl;
        for (auto it = stringMultiset.begin(); it != stringMultiset.end(); it++) {
            cout << "(" << *it << ") ";
        }
    }
}
