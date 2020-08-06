#include"normalstudent.h"
double NormalStudent::operator()(double x)
{
	return pdf(x);
}
double NormalStudent::operator()(double a,double b)
{
	return between(a, b);
}
NormalStudent::NormalStudent(const char * name, double  mean, double std)
{
	this->name = name;
	this->mean = mean;
	this->std = std;

}
double NormalStudent::pdf(double x)
{
	return exp(-(x - mean)*(x - mean) / (2 * std*std)) / (sqrt(2 * 3.14159265359)*std);
}
NormalStudent::NormalStudent()
{
	this->name = "MohammadJavad Ranjbar";
}