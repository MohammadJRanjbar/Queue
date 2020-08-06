#ifndef apmidterm_h
#define apmidterm_h
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include"normalstudent.h"
#include"exponentialstudent.h"
#include"student.h"
#include <sstream>
std::vector<std::unique_ptr<Student>>getData(const char*);
#endif