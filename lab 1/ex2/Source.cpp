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
	std::ifstream file("karatkevich.txt");
	if (!file.is_open())
		std::cout << "File not found\n";
	std::string temp;
	std::vector<std::string> vec;
	while (file >> temp)
	{
		vec.push_back(temp);
	}
	std::ofstream  file_out("Text_utf8.txt");
	if (!file_out.is_open())
		std::cout << "File not found\n";
	int temp_long = 0;
	int quantity_long = 0;
	for (auto it : vec)
	{
		if (it.length() > temp_long)
		{
			temp_long = it.length();
		}
	}
	file_out << "Long words: ";
	for (auto it : vec)
	{
		if (it.length() == temp_long)
		{
			++quantity_long;
			file_out << it << "\n";
		}
	}
	file_out << "Quantity: " << quantity_long << "   Length: " << temp_long << "\n\n";




	int temp_short = temp_long;
	int quantity_short = 0;
	for (auto it : vec)
	{
		if (it.length() < temp_short)
		{
			temp_short = it.length();
		}
	}
	file_out << "Short words: ";
	for (auto it : vec)
	{
		if (it.length() == temp_short)
		{
			++quantity_short;
			file_out << it << "   ";
		}
	}
	file_out << "\nQuantity: " << quantity_short << "   Length: " << temp_short << "\n";




	int length = 0;
	for (auto it : vec)
		length += it.length();

	file_out << "\nAverage length words: " << length / vec.size() << "\n";

	return 0;
}
