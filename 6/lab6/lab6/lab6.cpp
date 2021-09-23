#include <iostream>
#include "pcout.h"
#include <chrono>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

class SimpleNumCounter {
private:
    mutex nextNumToCheckFlag;
    mutex nextNumToCountFlag;
    long simpleNumNeeded = 0;
    long currentNum = 2;
    long count = 0;
    int maxThreads = std::thread::hardware_concurrency();

    long incCount() {
        const std::lock_guard<std::mutex> lock(nextNumToCountFlag);
        return count++;
    }
    bool needNext() const {
        return count < simpleNumNeeded;
    }
    bool isSimple(long num) {
        if (num < 4) return true;
        if (num % 2 == 0) return false;

        long to = num;
        if (num > 5) to = num / 2;
        for (long i = 3; i < to; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    void print() {
        while (count < simpleNumNeeded)
        {
            pcout << "current count is " << count << '\n';
        }
    }

    void search() {
        while (1)
        {
            if (isSimple(currentNum)) {
                count++;
            }
            if (count == simpleNumNeeded) {
                break;
            }
            currentNum++;
        }
    }
public:
    long findSimple(long i) {
        simpleNumNeeded = i;
        thread st(&SimpleNumCounter::search, this);
        thread pt(&SimpleNumCounter::print, this);
        st.join();
        pt.join();
        return currentNum;
    }
};


int main()
{
    {//task1
       /* vector<thread> v;
        thread th1(print, 0);
        thread th2(print, 1);
        thread th3(print, 2);
        thread th4(print, 4);
        thread th5(print, 5);
        thread th6(print, 6);
        thread th7(print, 7);
        thread th8(print, 8);
        thread th9(print, 9);
        thread th41(print, 11);
        thread th42(print, 12);
        thread th423(print, 13);*/
    }

    {//task2
        SimpleNumCounter s;
        cout<< "num is " << s.findSimple(9);
    }

    this_thread::sleep_for(std::chrono::seconds(20));
}