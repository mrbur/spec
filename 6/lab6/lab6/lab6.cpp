#include <iostream>
#include "pcout.h"
#include <chrono>
#include <thread>
#include <vector>

void print(int i) {
    pcout << i;
}
int main()
{
    {//task1
        vector<thread> v;
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
        thread th423(print, 13);
    }

    this_thread::sleep_for(std::chrono::seconds(20));
}