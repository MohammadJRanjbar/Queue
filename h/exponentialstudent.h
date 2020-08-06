#ifndef exponentialstudent_h
#define exponentialstudent_h
#include"student.h"
class ExponentialStudent : public Student
{
public:
	ExponentialStudent(const char *, double=0.07);
	ExponentialStudent();
	double operator()(double);
	double operator()(double, double);
	double pdf(double);
private:
	double lambda{ 0.07 };
};
#endif