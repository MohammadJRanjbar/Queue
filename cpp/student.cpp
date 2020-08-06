#include"student.h"
double Student::integrator(double step_size, double a, double b)
{
	//using Trapezoidal rule
	double s{ 0 };
	double n = (b - a) / step_size;
	for (size_t i = 0; i < n; i++)
		s += pdf(a + i*step_size)*step_size;
	return s;
}
double Student::between(double a, double b)
{
	return integrator(step_size, a, b);
}
std::string Student::GetName()
{
	//so we can access the name
	return this->name;
}
