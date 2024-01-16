#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>


#include <cstring>

void clean(std::string& str) {
	while (std::find(str.rbegin(), str.rend(), '-') == str.rbegin()) {
		if (str.empty())break;
		str.erase(--str.end());
	}
	
	while (std::find(str.begin(), str.end(), '-') == str.begin()) {
		if (str.empty())break;
		str.erase(str.begin());
	}
	/*while (std::find(str.rbegin(), str.rend(), '\'') == str.rbegin()) {
		if (str.size())break;
		str.erase(--str.end());
	}*/
	for (auto& i : std::string("0123456789();:\\,.?!\"")) {
		while (std::find(str.begin(), str.end(),i) != str.end()) {
			auto it = std::find(str.begin(), str.end(), i);
			str.erase(it);
		}
	}
	for (auto& ch : str)
	{
		ch = ::tolower(ch);
	}
	//str = ::tolower(str.c_str());

}

int main()
{
	std::vector<std::string> dic;
	
    std::ifstream book("Harry.txt");
	if (!book.is_open())
	{
		std::cerr << "error\n";
	}
	else {
		while (!book.eof()) {
			std::string tmp;
			book >> tmp;
			clean(tmp);
			dic.push_back(tmp);
		}
	}
	book.close();

	std::set<std::string> dictionary_set(dic.begin(), dic.end());
	for (int i = 0; i < dic.size(); i++)
	{
		std::cout << dic[i] << ", " << "\n";
	}
	return 0;
}