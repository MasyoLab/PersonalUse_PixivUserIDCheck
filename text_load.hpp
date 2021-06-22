//==========================================================================
// �e�L�X�g�ǂݎ��[text_load.hpp]
// author: MasyoLab
//==========================================================================
#pragma once

//==========================================================================
// include
//==========================================================================
#include <string>
#include <list>
#include <algorithm>
#include <fstream>
#include <stdexcept>

namespace text_load {
    /**
    @brief �w��t�@�C�����e�L�X�g�ǂݎ��
    @param Input [in] �ǂݎ��t�@�C��
    @return �ǂݎ�茋��
    */
    std::list<std::string> get(const std::string & Input) noexcept(false);
}
