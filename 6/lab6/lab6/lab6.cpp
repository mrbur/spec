#include <iostream>
#include "pcout.h"
#include "SimpleNumCounter.h"
#include <algorithm>

using namespace std;

class House {
private:
    vector<int> stuf = {9, 44, 8, 11};
    mutex flagPush;
    mutex flagPop;
public:
    void thiefWork() {
        while (true)
        {
            this_thread::sleep_for(std::chrono::seconds(1));
            flagPop.lock();
            stuf.pop_back();
            flagPop.unlock();
        }
    }
    void ownerWork() {
        while (true)
        {
            this_thread::sleep_for(std::chrono::seconds(1));
            flagPush.lock();
            stuf.push_back(rand() % 100);
            std::sort(stuf.begin(), stuf.end());
            flagPush.unlock();
        }
    }
    void run() {
        thread st(&House::thiefWork, this);
        thread pt(&House::ownerWork, this);
        pcout << '\n';
        while (true)
        {
            this_thread::sleep_for(std::chrono::seconds(1));
            for (int i = 0; i < stuf.size(); i++) {
                pcout << stuf[i] << " ";
            }
            pcout << '\n';
        }
        st.join();
        pt.join();
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
    
    //task3
    {
        House h;
        h.run();
    }
    
}