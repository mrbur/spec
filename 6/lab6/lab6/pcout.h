#pragma once
#include <ostream>
#include <iostream>
#include <mutex>

using namespace std;

struct Pcout {
	
};
mutex flag;
template <typename T>
Pcout& operator<< (Pcout& out, const T& data) {
	flag.lock();
	this_thread::sleep_for(std::chrono::microseconds(rand()));
	std::cout << data;
	flag.unlock();
	return out;
}

Pcout pcout;
