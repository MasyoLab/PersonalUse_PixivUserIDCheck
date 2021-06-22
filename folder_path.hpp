//==========================================================================
// �t�H���_�T��[folder_path.hpp]
// author: MasyoLab
//==========================================================================
#pragma once
#include <Windows.h>
#include <list>
#include <string>
#include <algorithm>
#include <stdexcept>

namespace folder_path {
	/**
	@brief ���s�t�@�C�������t�H���_�T��
	@return �T������
	*/
	std::list<std::wstring> get() noexcept(false);

	/**
	@brief �w��t�H���_�����t�H���_�T��
	@param folder_name [in] �T���Ώۂ̃t�H���_
	@return �T������
	*/
	std::list<std::wstring> get_in(const std::wstring& folder_name) noexcept(false);

	/**
	@brief �w��t�H���_�����t�H���_�̍ċA�T��
	@param path [in] �T���Ώۂ̃t�H���_
	@return �T������
	*/
	std::list<std::wstring> get_in_recursive(const std::list<std::wstring>& path) noexcept(false);

	/**
	@brief ���s�t�@�C�������t�H���_�S�T��
	@return �T������
	*/
	std::list<std::wstring> get_all() noexcept(false);

	size_t GetLength();

	void SetLength(size_t length);
}