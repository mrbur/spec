#include <iostream>
#include <fstream>
#include "FullName.pb.h"
#include "Student.pb.h"
#include "StudentsGroup.pb.h"
#include "StudentsGroupSerializer.h"
#include "list"

int main()
{
	Student s;
	s.set_fullname("name");
	list<Student> students;
	students.push_back(s);

	StudentsGroup sg;

	StudentsGroupSerializer sgs(&sg);
	sgs.Save();

	return 0;
}
