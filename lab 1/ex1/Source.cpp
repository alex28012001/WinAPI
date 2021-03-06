#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<codecvt>
#include<fstream>
#include<string>
#include<vector>
int main()
{
	std::locale loc(std::locale::classic(), new
		std::codecvt_utf8<wchar_t>);
	setlocale(0, "");
	std::ifstream file("Text.txt");
	if (!file.is_open())
		std::cout << "File not found\n";
	std::string temp;
	std::vector<std::string> vec;
	while (file >> temp)
	{
		size_t len = mbstowcs(NULL, temp.c_str(), 0) + 1;
		wchar_t* str2 = new wchar_t[len];
		int count = mbstowcs(str2, temp.c_str(), len);
		delete[] str2;
		vec.push_back(temp);
	}
	std::ofstream file_out("Text_unicode.txt");
	if (!file_out.is_open())
		std::cout << "File not found\n";
	for (auto it : vec)
	{
		file_out << it << " ";
	}
	file.close();
	file_out.close();
	return 0;
}
