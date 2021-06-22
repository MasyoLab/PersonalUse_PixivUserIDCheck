//==========================================================================
// �f�[�^�̏�������[data_save.hpp]
// author: MasyoLab
//==========================================================================
#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>

namespace data_save {
    /**
    @brief �f�[�^�̏�������
    @param stdFileName [in] �t�@�C����
    @param InputData [in] �ۑ�����f�[�^
    */
    void save(const std::string &stdFileName, const std::vector<std::string>&InputData) noexcept(false);

    /**
    @brief �f�[�^�̏�������
    @param stdFileName [in] �t�@�C����
    @param InputData [in] �ۑ�����f�[�^
    */
    void save(const std::string &stdFileName, const std::list<std::string>&InputData) noexcept(false);

    /**
    @brief �f�[�^�̏�������
    @param stdFileName [in] �t�@�C����
    @param InputData [in] �ۑ�����f�[�^
    */
    void save(const std::string &stdFileName, const std::string&InputData) noexcept(false);
}