#include <iostream>
#include <vector>
#include <cmath>  
#include <list>
#include <deque>
#include <set>
#include <algorithm>
#include <numeric>


using namespace std;

template <typename Container, typename Iterator, typename T>
void process(Container* contaner, Iterator begin, Iterator end, T val)
{
    auto pos = lower_bound(begin, end, val);
    std::fill_n(std::inserter(*contaner, pos), 1, val);
}

int main() {
    //1 task
    {
        vector<int> vec = { 2,3,8 };
        list<float> list = { 2,3,8 };
        std::multiset<long> s{ 1, 2, 3 };

        process(&s, s.begin(), s.end(), 2);
        process(&list, list.begin(), list.end(), 3);
        process(&vec, vec.begin(), vec.end(), 3);
    }

    //2 task
    {
        vector<double> analogVec(100);
        for (int i = 0; i < 100; i++) {
            analogVec[i] = 10 * sin(3.14159265 * i / 180);
        }

        cout << accumulate(begin(analogVec), end(analogVec), 0.0, 
            [](double sum, double fVal) {
                fVal -= (int)fVal;
                float square = pow(fVal, 2);
                return sum + square;
            }) << endl;
    }
}