#pragma once

#include <map>
#include <vector>
#include <string>
#include "person.h"
#include <fstream>
#include <sstream>
#include "PhoneNumber.h"
#include <algorithm>


using namespace std;

class PhoneBook {
    public:
        vector<tuple<Person, PhoneNumber>> personNumbers;

	    PhoneBook(ifstream & fin) {
            string line;

            string firstName, seconName, val, thirdName, phone;
            if ((fin).is_open())
            {
                Person *p;
                PhoneNumber *pn;

                vector<string> parsedLine;
                while (!fin.eof()) {
                    fin >> val;
                    parsedLine.push_back(val);
                    int y = fin.get();
                    if (y == 10 || y == -1) {
                        if (parsedLine[parsedLine.size() - 1].c_str()[0] == '+') {
                            p = new Person(vector<string>(parsedLine.begin(), parsedLine.end() - 1));
                            pn = new PhoneNumber(vector<string>(parsedLine.end() - 1, parsedLine.end()));
                            personNumbers.push_back(make_tuple(*p, *pn));
                        }
                        else {
                            p = new Person(vector<string>(parsedLine.begin(), parsedLine.end() - 2));
                            pn = new PhoneNumber(vector<string>(parsedLine.end() - 2, parsedLine.end()));
                            personNumbers.push_back(make_tuple(*p, *pn));
                        }
                        parsedLine.clear();
                    }
                }
                fin.close();
            }
	    }
        void SortByName() {
            sort(personNumbers.begin(), personNumbers.end(),
                [](const tuple<Person, PhoneNumber>& a, const tuple<Person, PhoneNumber>& b) -> bool
                {
                    return get<0>(a).secondName > get<0>(b).secondName;
                });
        }

        void SortByPhone() {
            sort(personNumbers.begin(), personNumbers.end(),
                [](const tuple<Person, PhoneNumber>& a, const tuple<Person, PhoneNumber>& b) -> bool
                {
                    int t = atoi(get<1>(a).number.c_str());
                    int t1 = atoi(get<1>(b).number.c_str());
                    return atoi(get<1>(a).number.c_str()) < atoi(get<1>(b).number.c_str());
                });
        }

        tuple<string, PhoneNumber*> GetPhoneNumber(string secondName) {
            vector<PhoneNumber> foundPhoneNumbers;
            for_each(personNumbers.begin(), personNumbers.end(),
                [&](tuple<Person, PhoneNumber> pn) {if (get<0>(pn).secondName == secondName)foundPhoneNumbers.push_back(get<1>(pn)); });
            if (foundPhoneNumbers.size() == 0) {
                return make_tuple("not found", nullptr);
            }
            else if (foundPhoneNumbers.size() > 1) {
                return make_tuple("found more than 1", nullptr);
            }
            return make_tuple("", &foundPhoneNumbers[0]);
        }

        void ChangePhoneNumber(Person p, PhoneNumber phone) {
            for (tuple<Person, PhoneNumber> &pn : personNumbers)
            {
                if (get<0>(pn) == p) {
                    get<1>(pn) = phone;
                }
            }
        }
        
};

ostream& operator<< (std::ostream& out, const PhoneBook& book) {
    for (tuple<Person, PhoneNumber> pn : book.personNumbers)
    {
        out << get<0>(pn) << get<1>(pn) << endl;
    }
    return out;
}