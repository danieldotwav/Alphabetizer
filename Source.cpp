#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 26;

void sortByAlgorithm(string& s);
void sortByHash(string& s);

int main() {
	string letters;
	string lettersSorted;

	cout << "Welcome\n\n";

	cout << "Please enter a string of letters to be alphabetized\n";
	cout << "Note: do not use spaces between letters\n";
	cout << "Letters: ";

	cin >> letters;
	cout << endl;

	sortByAlgorithm(letters);

	cout << "Sorted Letters (Using built-in sort): ";
	cout << letters;
	cout << "\n\nTime Complexity: O(n * log n), where n is the length of the string\n\n";
	cout << "Note: Notice how uppercase letters are not sorted properly\n";
	cout << "This is because the built-in sorting algorithm works by comparing the ascii values ";
	cout << "associated with each character and uppercase letters have relatively lower values than ";
	cout << "their lowercase equivalents\n\n";

	cout << "Enter another string of letters to be alphabetized\n";
	cout << "Letters: ";
	cin >> letters;
	cout << endl;
	
	cout << "Sorted Letters (Using hash): ";
	sortByHash(letters);
	cout << "\n\nTime Complexity: O(n), where n is the length of the string\n\n";
	cout << "Note: Notice how uppercase letters are ignored\n";

	return 0;
}
void sortByAlgorithm(string& s) {
	sort(s.begin(), s.end());
}

void sortByHash(string& s) {
	// Purpose: This hash array simply keeps track of the occurances of a given letter.
	//			Initialize it to zero to avoid unwanted address values in unused indexes.
	int count[MAX] = { 0 };

	// Traverse string and increment character count
	// Subtract the ASCII code of the character 'a' from the ASCII code of the current character to determine
	// its position in the count array (since the lowercase letters are contiguous in the ASCII table.
	for (int i{ 0 }; i < s.length(); i++) {
		count[s[i] - 'a']++;
	}

	// Traverse the hash array and print each letter sequentially the number of times it appeared in the original string.
	// Cast the result of the expression ('a' + i) to a char datatype using (char)(expression)
	for (int i{ 0 }; i < MAX; i++) {
		for (int j{ 0 }; j < count[i]; j++) {
			cout << (char)('a' + i);
		}
	}

}
