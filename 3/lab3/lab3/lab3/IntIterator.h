#pragma once

template<long SIZE>
class IntIterator : public std::iterator<std::input_iterator_tag, int> {
private:
	int* from;
public:
	IntIterator(int* from) : from(from) {
	}
	IntIterator& operator++() {
		from++;
		return *this;
	}
	IntIterator operator++(int) {
		IntIterator tmp = *this; ++(*this); return tmp;
	}

	bool operator==(const IntIterator& intNum) const { return from == intNum.from; }
	bool operator!=(const IntIterator& intNum) const {
		return from != intNum.from;
	}
	int& operator*() { return *from; }

	IntIterator begin() {
		return from;
	}

	IntIterator end() {
		return from + SIZE;
	}

	int val() const {
		return *from;
	}

};