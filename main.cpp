//==========================================================================
// (Personal Use) Pixiv User ID Check
//==========================================================================

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#define _GLIBCXX_DEBUG
#include <time.h>
#include <iostream>
#include <chrono>
#include <direct.h>
#include <unordered_map>

#include "data_save.hpp"
#include "file_path.hpp"
#include "folder_path.hpp"
#include "text_load.hpp"
#include "string_encode.hpp"

//==========================================================================
// ^è`
//==========================================================================
using list_string = std::list<std::string>;

//==========================================================================
// Öè`
//==========================================================================

//=============================================================================
// main
//=============================================================================
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	time_t timer;
	tm* date;
	std::string create_day; // ¶¬ú
	std::string create_time; // ¶¬Ô
	char str[256] = { 0 };

	//=============================================================================
	// ÀsJnÔðL^
	//=============================================================================
	timer = time(nullptr); // oßÔðæ¾
	date = localtime(&timer); // oßÔðÔð\·\¢Ì date ÉÏ·
	strftime(str, sizeof(str), "%Y/%m/%d", date); // Núªb
	create_day = str;
	strftime(str, sizeof(str), "%H:%M:%S", date); // Núªb
	create_time = str;

	// ¯¶fBNgàðTõ
	auto directory = folder_path::get();

	// õÎÛ
	auto wfindStrA = std::wstring(L"(ID[");
	// ö
	auto wfindStrB = std::wstring(L"])");
	// idJE^
	auto uuidCounter = std::unordered_map<std::string, int>();

	// ID`FbN
	for (auto& data : directory) {
		// õÎÛÌ¶ñÔðõ
		auto index = data.find(wfindStrA);
		if (data.size() < index)
			continue;

		// wè¶ÜÅjü
		data.erase(0, index + wfindStrA.size());
		// öÌ¶ðjü
		data.erase(data.size() - wfindStrB.size(), wfindStrB.size());

		// wstring ©ç string ÉÏ·
		auto uuidStr = string_encode::wide_to_utf8_encode(data);

		// IDJE^
		auto itr = uuidCounter.find(uuidStr);
		if (itr == uuidCounter.end()) {
			uuidCounter[uuidStr] = 1;
		}
		else {
			itr->second++;
		}
	}

	// oÍp
	list_string outputStr;

	outputStr.push_back("");
	outputStr.push_back("=========== Pixiv User ID Check ===========");
	outputStr.push_back("*** " + create_day);
	outputStr.push_back("*** " + create_time);
	outputStr.push_back("*** GtlÌl : " + std::to_string((int)uuidCounter.size()));
	outputStr.push_back("");
	outputStr.push_back("¡¡¡¡¡¡¡¡ ID oÍ ¡¡¡¡¡¡¡¡");

	for (auto& data : uuidCounter) {
		outputStr.push_back(data.first + ":" + std::to_string(data.second));
	}

	outputStr.push_back("¡¡¡¡¡¡¡¡ ID oÍ®¹  ¡¡¡¡¡¡¡¡");
	outputStr.push_back("");
	outputStr.push_back("¡¡¡¡¡¡¡¡ d¡ ID oÍ  ¡¡¡¡¡¡¡¡");

	for (auto& data : uuidCounter) {
		if (data.second <= 1)
			continue;
		outputStr.push_back(data.first + ":" + std::to_string(data.second));
	}

	outputStr.push_back("¡¡¡¡¡¡¡¡ d¡ ID oÍ®¹  ¡¡¡¡¡¡¡¡");

	// oÍ
	for (auto& data : outputStr) {
		std::cout << data << std::endl;
	}

	// OÌÛ¶
	data_save::save("Pixiv User ID Check.log", outputStr);

	return std::system("PAUSE");
}

