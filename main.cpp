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
// 型定義
//==========================================================================
using list_string = std::list<std::string>;

//==========================================================================
// 関数定義
//==========================================================================

//=============================================================================
// main
//=============================================================================
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	time_t timer;
	tm* date;
	std::string create_day; // 生成日
	std::string create_time; // 生成時間
	char str[256] = { 0 };

	//=============================================================================
	// 処理実行開始時間を記録
	//=============================================================================
	timer = time(nullptr); // 経過時間を取得
	date = localtime(&timer); // 経過時間を時間を表す構造体 date に変換
	strftime(str, sizeof(str), "%Y/%m/%d", date); // 年月日時分秒
	create_day = str;
	strftime(str, sizeof(str), "%H:%M:%S", date); // 年月日時分秒
	create_time = str;

	// 同じディレクトリ内を探索
	auto directory = folder_path::get();

	// 検索対象
	auto wfindStrA = std::wstring(L"(ID[");
	// 末尾
	auto wfindStrB = std::wstring(L"])");
	// idカウンタ
	auto uuidCounter = std::unordered_map<std::string, int>();

	// IDチェック
	for (auto& data : directory) {
		// 検索対象の文字列番号を検索
		auto index = data.find(wfindStrA);
		if (data.size() < index)
			continue;

		// 指定文字まで破棄
		data.erase(0, index + wfindStrA.size());
		// 末尾の文字を破棄
		data.erase(data.size() - wfindStrB.size(), wfindStrB.size());

		// wstring から string に変換
		auto uuidStr = string_encode::wide_to_utf8_encode(data);

		// IDカウンタ
		auto itr = uuidCounter.find(uuidStr);
		if (itr == uuidCounter.end()) {
			uuidCounter[uuidStr] = 1;
		}
		else {
			itr->second++;
		}
	}

	// 出力用
	list_string outputStr;

	outputStr.push_back("");
	outputStr.push_back("=========== Pixiv User ID Check ===========");
	outputStr.push_back("*** " + create_day);
	outputStr.push_back("*** " + create_time);
	outputStr.push_back("*** 絵師様の人数 : " + std::to_string((int)uuidCounter.size()));
	outputStr.push_back("");
	outputStr.push_back("■■■■■■■■ ID 出力 ■■■■■■■■");

	for (auto& data : uuidCounter) {
		outputStr.push_back(data.first + ":" + std::to_string(data.second));
	}

	outputStr.push_back("■■■■■■■■ ID 出力完了  ■■■■■■■■");
	outputStr.push_back("");
	outputStr.push_back("■■■■■■■■ 重複 ID 出力  ■■■■■■■■");

	for (auto& data : uuidCounter) {
		if (data.second <= 1)
			continue;
		outputStr.push_back(data.first + ":" + std::to_string(data.second));
	}

	outputStr.push_back("■■■■■■■■ 重複 ID 出力完了  ■■■■■■■■");

	// 出力
	for (auto& data : outputStr) {
		std::cout << data << std::endl;
	}

	// ログの保存
	data_save::save("Pixiv User ID Check.log", outputStr);

	return std::system("PAUSE");
}

