//==========================================================================
// �e�L�X�g�ǂݎ��[text_load.cpp]
// author: MasyoLab
//==========================================================================
#include "text_load.hpp"

std::list<std::string> text_load::get(const std::string& Input) noexcept(false)
{
	std::ifstream ifs(Input); // c++�ɂ��t�@�C���ǂݍ���
	std::string str; // �i�[string
	std::list<std::string> _input;

	// �t�@�C�����J���Ȃ��������ɐ���
	if (ifs.fail()) {
		std::ofstream ifs(Input);
		return _input;
	}

	// �I���܂ŉ�
	for (; std::getline(ifs, str);)
		_input.push_back(str);
	ifs.close();

	return _input;
}
