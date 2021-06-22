//==========================================================================
// string encode [string_encode.hpp]
// author: MasyoLab 
//==========================================================================
#pragma once

#include <string> 

namespace string_encode
{
	// Convert a wide Unicode string to an ANSI string
	std::string wide_to_ansi_encode(const std::wstring& wstr);

	// Convert a ANSI string to an wide Unicode string
	std::wstring ansi_to_wide_encode(const std::string& str);

	// Convert a wide Unicode string to an UTF8 string
	std::string wide_to_utf8_encode(const std::wstring& wstr);

	// Convert a UTF8 string to an wide Unicode string
	std::wstring utf8_to_wide_encode(const std::string& str);

	// Convert a ANSI string to an UTF8 string
	std::string ansi_to_utf8_encode(const std::string& str);

	// Convert a UTF8 string to an ANSI string
	std::string utf8_to_ansi_encode(const std::string& str);
}
