#include <iostream>
#include <fstream>
#include "FullName.pb.h"
#include "Student.pb.h"
#include "StudentsGroup.pb.h"
#include "StudentsGroupSerializer.h"
#include "list"
#include <gtest/gtest.h>

using namespace std;

Student s;

TEST(StudentTest, fullnameNotEmpty)
{
	EXPECT_TRUE(s.fullname().size() > 0);
}

TEST(SudentGroup, SudentGroupSaveCheck)
{
	s.set_fullname("name");
	list<Student> students;
	students.push_back(s);

	StudentsGroup sg;

	StudentsGroupSerializer sgs(&sg);
	EXPECT_TRUE(sgs.Save());
}

int main()
{
	s.set_fullname("name");
	list<Student> students;
	students.push_back(s);

	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
