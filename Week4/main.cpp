#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>
#include <map>
#include <string>
#include <functional>

int main() {
	/* Opdracht 1 */
	std::ifstream my_text("text.txt");
	char c;
	std::vector<char> my_vector;

	while (my_text.get(c)) {
		my_vector.push_back(c);
	}
	my_text.close();

	/* Opdracht 2 */
	std::cout << "Amount of characters: " << my_vector.size() << std::endl;

	/* Opdracht 3 */
	std::cout << "Amount of lines: " << count(my_vector.begin(), my_vector.end(), '\n') << std::endl;

	/* Opdracht 4 */
	std::cout << "Amount of alphabetical characters: " << count_if(my_vector.begin(), my_vector.end(), [](char & c) { return isalpha(c); }) << std::endl;

	/* Opdracht 5 */
	for_each(my_vector.begin(), my_vector.end(), [](char & c) { if (c >= 'A' && c <= 'Z') { c += 32; }});

	/* Opdracht 6 */
	std::array<std::array<int, 2>, 26> count_array = { {0, 0} };
	for_each(my_vector.begin(), my_vector.end(), [&count_array](char & c) -> void {
		if (isalpha(c)) { 
			if (count_array[c - 'a'][0] != 0) {
				count_array[c - 'a'][1] ++;
			}
			else {
				count_array[c - 'a'] = { c, 1 };
			}
		}});

	/* Opdracht 7 */
	std::sort(count_array.begin(), count_array.end(), [](std::array<int, 2> & lhs, std::array<int, 2> & rhs) {
		if (lhs[0] != rhs[0]) {
			return lhs[0] < rhs[0];
		}
		return lhs[1] < rhs[1];
	});

	std::cout << "\nSorted by key: \n";

	for (unsigned int i = 0; i < count_array.size(); i++) {
		std::cout << (char)count_array[i][0] << ": " << count_array[i][1] << std::endl;
	}

	std::cout << "\nSorted by value: \n";

	std::sort(count_array.begin(), count_array.end(), [](std::array<int, 2> & lhs, std::array<int, 2> & rhs) {
		if (lhs[1] != rhs[1]) {
			return lhs[1] < rhs[1];
		}
		return lhs[0] < rhs[0];
	});

	for (unsigned int i = 0; i < count_array.size(); i++) {
		std::cout << (char)count_array[i][0] << ": " << count_array[i][1] << std::endl;
	}

	/* Opdracht 8 */
	std::map<std::string, int> word_count;
	std::string word = "";

	//std::ifstream my_text2("text.txt");
	//while (my_text2 >> word) {
	//	if (word_count[word]) {
	//		word_count[word]++;
	//	}
	//	else {
	//		word_count[word] = 1;
	//	}
	//}
	//my_text2.close();

	for_each(my_vector.begin(), my_vector.end(), [&word_count, &word](char & c) -> void {
		if (c == ' ' || c == '\n') {
			if (word != "") {
				if (word_count[word]) {
					word_count[word] ++;
				}
				else {
					word_count[word] = 1;
				}
				word = "";
			}
		}
		else if(isalpha(c)) {
			word += c;
		}});
	
	std::multimap<int, std::string, std::greater<int>> most_common;
	std::transform(word_count.begin(), word_count.end(), std::inserter(most_common, most_common.begin()), [](auto & p) { return std::pair<int, std::string>(p.second, p.first); });
	int amount_of_words = 10;
	std::cout << std::endl;
	for (auto element : most_common) {
		if (amount_of_words <= 0) {
			break;
		}
		std::cout << element.second << ": " << element.first << std::endl;
		amount_of_words--;
	}
	return 0;
}