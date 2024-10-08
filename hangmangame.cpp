#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;


class word {
public:
	char letter;
	std::string firstword;
	bool charExists;
	word(char Letter, std::string Firstword) : letter(Letter), firstword(Firstword) {}

	bool isCharacterRepeating(const std::string& word, char character) {
		int count = 0; // To count occurrences of the character

		for (char ch : word) {
			if (ch == character) {
				count++;
				if (count > 1) {
					return true; // Character appears more than once
				}
			}
		}

		return false; // Character does not repeat
	}

	void checkLetter() {
		// Create a dynamic array with size based on firstword.size()
		vector<char> charArray(firstword.size() + 1); // +1 for the null terminator
		// Copy characters from firstword to charArray
		copy(firstword.begin(), firstword.end(), charArray.begin());
		// Add null terminator
		charArray[firstword.size()] = '\0';
		vector<char> emptyCopyOfWord(firstword.size() + 1);
		emptyCopyOfWord[firstword.size()] = '\0';
		// Print the char array
		//std::cout << "Char array: " << charArray.data() << std::endl;
		int letterPositiontracker = 0;
		while (emptyCopyOfWord != charArray) {
			int count = 0;
			for (int i = 0; i < (charArray.size() - 1); i++) {

				if (charArray[i] == letter || isCharacterRepeating(firstword, letter)) {
					charExists = true;
					int skipindex = i;
					if (charExists && !isCharacterRepeating(firstword, letter)) {
						emptyCopyOfWord[i] = letter;
						cout << "You guessed the word in the " << i << " place " << "correct." << endl;
						i = 0;
						break;
					}

					else if (charExists && count < 3) {
						emptyCopyOfWord[i] = letter;
						count = count + 1;
					}
					else { 
						for (int i = 0; i < (charArray.size() - 1); i++) {
							if (charArray[i] == emptyCopyOfWord[i]) {
								cout << "You guessed the word in the " << i << " place " << "correct." << endl;
							}
						}
						break; }
				}
		}
		if (emptyCopyOfWord != charArray) {
			if (charExists) {
				cout << "Guess another letter" << endl;
				cin >> letter;
			}
			
		}
	}
		for (char c : emptyCopyOfWord) {
			std::cout << c << " ";
		}
		std::cout << " Congrats, you guessed the word correctly\n";
		std::cout << "  -----\n";
		std::cout << "  |   |\n";
		std::cout << "  O   |\n";
		std::cout << " /|\\  |\n";
		std::cout << " / \\  |\n";
		std::cout << "      |\n";
		std::cout << "---------\n";
	}
};

int main() {
	char Letter;
	bool repeatingLetter;
	string Firstword;
	cout << "Please enter the letter" << endl;
	cin >> Letter;
	cout << "Please enter the Firstword" << endl;
	cin >> Firstword;
	word word1(Letter, Firstword);
	word1.checkLetter();
	return 0;
}
