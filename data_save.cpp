//==========================================================================
// �f�[�^�̏�������[data_save.hpp]
// author: MasyoLab
//==========================================================================
#include "data_save.hpp"

void data_save::save(const std::string& stdFileName, const std::vector<std::string>& InputData) noexcept(false)
{
	std::ofstream outputfile(stdFileName);
	for (auto& itr : InputData)
		outputfile << itr << std::endl;
	outputfile.close();
}

void data_save::save(const std::string& stdFileName, const std::list<std::string>& InputData) noexcept(false)
{
	std::ofstream outputfile(stdFileName);
	for (auto& itr : InputData)
		outputfile << itr << std::endl;
	outputfile.close();
}

void data_save::save(const std::string& stdFileName, const std::string& InputData) noexcept(false)
{
	std::ofstream outputfile(stdFileName);
	outputfile << InputData;
	outputfile.close();
}
