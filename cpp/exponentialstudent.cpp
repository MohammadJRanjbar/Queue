#include"exponentialstudent.h"
ExponentialStudent::ExponentialStudent()
{
	this->name = "Mohammad Javad Ranjbar";
}
ExponentialStudent::ExponentialStudent(const char * name , double lambda )
{
	this->name = name;
	this->lambda = lambda;
}
double ExponentialStudent::pdf(double x)
{
	return lambda*exp(-lambda*x);
}
double ExponentialStudent::operator()(double x)
{
	return pdf(x);
}
double ExponentialStudent::operator()(double a, double b)
{
	return between(a, b);
}