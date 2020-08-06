#ifndef student_h
#define student_h
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
class Student
{
	public:
		//this virtual function make it imposible to make a object of this class
		double virtual pdf(double) = 0;
		double integrator(double, double, double);
		double between(double, double);
		std::string GetName();

	private:
		double step_size{ 0.001 };
	protected:
	//this is protected so child classes can access it
	std::string name{ "Mohammad Javad Ranjbar " };
};
#endif