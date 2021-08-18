#pragma once
#include <string>
#include <optional>

using namespace std;

struct PhoneNumber {
	int stateCode;
	int cityCode;
	string number;
	optional<int> additionalCode;

	PhoneNumber(int stateCode, int cityCode, string number, optional<int> additionalCode) {
		this->stateCode = stateCode;
		this->cityCode = cityCode;
		this->number = number;
		this->additionalCode = additionalCode;
	}

	PhoneNumber(vector<string> v)  {
		string phone = v[0];
		size_t pos = phone.find("(");
		stateCode = atoi(phone.substr(1, pos).c_str());
		size_t pos1 = phone.find(")");
		string h = phone.substr(pos+1, pos1-3);
		cityCode = atoi(phone.substr(pos+1, pos1-3).c_str());
		pos = phone.find(" ");
		number = phone.substr(pos1+1, pos);
		if (v.size() > 1)
			this->additionalCode = atoi(v[1].c_str());
		else this->additionalCode = 0;
	}

	PhoneNumber(int stateCode, int cityCode, string number, int additionalCode) : stateCode(stateCode), cityCode(cityCode), number(number), additionalCode(additionalCode) {
	}

	
};

ostream& operator<< (std::ostream& out, const PhoneNumber& phone) {
	out << phone.stateCode << "(" << phone.cityCode << ")" << phone.number << " " << phone.additionalCode.value();
	return out;
}