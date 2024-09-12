#include <iostream>
#include <string>
#include <vector>

using namespace std;

//struct hangman{


//};

class word {
public:
	char letter;
	std::string firstword;
	bool charExists;
	word(char Letter, std::string Firstword) : letter(Letter), firstword(Firstword) {}
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
		while(emptyCopyOfWord!= charArray) {
		for (int i = 0; i < (charArray.size() - 1); i++) {
			if (charArray[i] == letter) {
				charExists = true;
				emptyCopyOfWord[i] = letter;
				cout << "You guessed the word in the " << i << " place " << "correct."<< endl;
				i = 0;
				break;
			}
		}
		if (charExists) {
			cout << "Guess another letter" << endl;
			cin >> letter;
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
	string Firstword;

	cin >> Letter;
	cin >> Firstword;

	word word1(Letter, Firstword);
	word1.checkLetter();

	return 0;
}
