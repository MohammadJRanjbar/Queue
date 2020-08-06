#ifndef normalstudent_h
#define normalstudent_h
#include"student.h"
class NormalStudent : public Student
{
public:
	NormalStudent(const char *, double=12, double=2);
	NormalStudent();
	double pdf(double);
	double operator()(double);
	double operator()(double, double);
private:
	double mean{ 12 };
	double std{ 2 };

};
#endif