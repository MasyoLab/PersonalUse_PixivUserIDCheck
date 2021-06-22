//==========================================================================
// �t�@�C���T��[file_path.hpp]
// author: MasyoLab
//==========================================================================
#pragma once
#include <Windows.h>
#include <list>
#include <string>
#include <stdexcept>

namespace file_path {
    /**
    @brief �t�@�C���T��
    @param dir_name [in] �T���Ώۃf�B���N�g��
    @param extension [in] �g���q�w��
    @param set_ [in]
    @return �T������
    */
    std::list<std::wstring> get_in(const std::wstring& dir_name, const std::wstring& extension, std::wstring set_ = L"\\*.") noexcept(false);

    /**
    @brief �t�@�C���T��
    @param extension [in] �g���q�w��
    @return �T������
    */
    std::list<std::wstring> get(const std::wstring& extension) noexcept(false);

    size_t GetLength();

    void SetLength(size_t length);
}
