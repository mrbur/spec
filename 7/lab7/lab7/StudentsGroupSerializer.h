#pragma once

#include <fstream>
#include "FullName.pb.h"
#include "Student.pb.h"
#include "StudentsGroup.pb.h"

using namespace std;

class IRepository {
	virtual void Open() = 0; // бинарная десериализация в файл
	virtual bool Save() = 0; // бинарная сериализация в файл
};


class IMethods {
	virtual double GetAverageScore(const FullName& name) = 0;
	virtual string GetAllInfo(const FullName& name) = 0;
	virtual string GetAllInfo() = 0;
};

class StudentsGroupSerializer : public IRepository, virtual public IMethods{
private:
	StudentsGroup* sg;
public:
	StudentsGroupSerializer(StudentsGroup* sg) : sg(sg){
	}
	bool Save() {
		ofstream out("StudentsGroup.bin", ios_base::binary);
		return (*sg).SerializeToOstream(&out);
	}
	void Open() {
		ifstream in("StudentsGroup.bin", ios_base::binary);

		if ((*sg).ParseFromIstream(&in)) {
			cout << "Success" << endl;
		}
		else {
			cout << "Error!" << endl;
		}
	}

	double GetAverageScore(const FullName& name) {
		for (rsize_t i = 0; i < sg->students_size(); i++) {
			if (sg->students(i).fullname() == (name.firstname() + " " + name.secondname() + " " + name.fathersname())) {
				return sg->students(i).averagegrade();
			}
		}
		return 0;
	}

	string GetAllInfo() {
		string all;
		for (rsize_t i = 0; i < sg->students_size(); i++) {
			all += sg->students(i).fullname()+"";
		}
		return all;
	}
	string GetAllInfo(const FullName& name) {
		string all;
		for (rsize_t i = 0; i < sg->students_size(); i++) {
			if (sg->students(i).fullname() == (name.firstname() + " " + name.secondname() + " " + name.fathersname())) {
				return sg->students(i).fullname() + " " + std::to_string(sg->students(i).averagegrade());
			}
		}
		return all;
	}
};