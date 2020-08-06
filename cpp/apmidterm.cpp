#include"apmidterm.h"
std::vector<std::unique_ptr<Student>> getData(const char* FileAddress)
{
	std::vector <std::unique_ptr<Student>> Studentlist;
	std::ifstream studentNames;
	studentNames.open(FileAddress);
	std::string line{};
	size_t temp{ 0 };
	std::string word;

	while (studentNames.good())
	{
		while (getline(studentNames, line))
		{	
			std::vector<std::string>SL;
			std::stringstream ss(line);
			while (getline(ss, word, ','))
			{
				SL.push_back(word);
				temp++;
			}
			if (temp == 2)
			{
				ExponentialStudent Temp_S{ SL[0].c_str(),std::stod(SL[1]) };
				temp = 0;
				Studentlist.push_back(std::make_unique<ExponentialStudent>(Temp_S));
			}
			else if (temp == 3)
			{
				NormalStudent Temp_S{ SL[0].c_str(),std::stod(SL[1]),std::stod(SL[2]) };
				temp = 0;
				Studentlist.push_back(std::make_unique<NormalStudent>(Temp_S));
				
			}
			
		}
	}

	return Studentlist;
}