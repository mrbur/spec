#pragma once

#include <chrono>
#include <thread>
#include <vector>
#include <mutex>
#include "pcout.h"

class SimpleNumCounter {
private:
    mutex nextNumToCheckFlag;
    mutex nextNumToCountFlag;
    long simpleNumNeeded = 0;
    long currentNum = 2;
    long count = 0;

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