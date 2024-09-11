#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

// Function for stooping the light for 60 seconds
void runLongTask() {                 
	this_thread::sleep_for(60s);  // Sleep for 60 seconds
}

// Function for stooping the light for 3 seconds
void runShortTask() {
	this_thread::sleep_for(3s);  // Sleep for 3 seconds
}

class TrafficManager {
public:
	string currentLight1;
	string currentLight2;
	bool intersection;
	TrafficManager(string CurrentLight, bool Intersection) :currentLight1(CurrentLight), intersection(Intersection) {}
	
	void trafficforIntersection() {
		thread longTaskThread(runLongTask);
		thread shortTaskThread(runShortTask);

		if (intersection && currentLight1 == "Red") {
			while (true) {
				currentLight1 = "Red";
				currentLight2 = "Green";		
				cout << "Traffic Light 1    Traffic Light 2    /n" << endl;
				auto sixty_seconds = 60s;
				auto three_seconds = 3s;
				cout << currentLight1<<"                 ";
				runLongTask();
				cout << currentLight2 << endl;
				runLongTask();

				currentLight2 = "Yellow";
				currentLight1 = "Green";
				cout << currentLight1 << "                 ";
				runLongTask();
				cout << currentLight2 << endl;
				runShortTask();

				currentLight2 = "Green";
				currentLight1 = "Yellow";
				
				cout << "Green" << endl;
				this_thread::sleep_for(three_seconds);
				break;
			}
		}
		if (intersection == true && currentLight1 == "Yellow") {
			while (true) {
			auto three_seconds = 3s;
			auto sixty_seconds = 60s;
			this_thread::sleep_for(three_seconds);
			currentLight2 == "Green";
			cout << "Green" << endl;
			this_thread::sleep_for(sixty_seconds);
		}
		}
		 if (intersection == true && currentLight1 == "Green") {
			 while (true) {
			auto three_seconds = 3s;
			auto sixty_seconds = 60s;
			this_thread::sleep_for(three_seconds);
			currentLight2 == "Red";
			cout << "Red" << endl;
			this_thread::sleep_for(sixty_seconds);
		}
		}
	}

	void singleTrafficLight() {
		while (true) {
			if (currentLight1 == "Red") {
				auto sixty_seconds = 60s;
				this_thread::sleep_for(sixty_seconds);
				cout << "Yellow" << endl;
				auto three_seconds = 3s;
				this_thread::sleep_for(three_seconds);
				cout << "Green" << endl;
				this_thread::sleep_for(sixty_seconds);
			}
		}
		while (true) {
			if (currentLight1 == "Yellow") {
				auto three_seconds = 3s;
				this_thread::sleep_for(three_seconds);
				cout << "Green" << endl;
				auto sixty_seconds = 60s;
				this_thread::sleep_for(sixty_seconds);
				cout << "Red" << endl;
				this_thread::sleep_for(sixty_seconds);
			}
		}
		while (true) {
		if (currentLight1 == "Green") {
			auto sixty_seconds = 60s;
			this_thread::sleep_for(sixty_seconds);
			cout << "Red" << endl;
			this_thread::sleep_for(sixty_seconds);
			cout << "Yellow" << endl;
			auto three_seconds = 3s;
			this_thread::sleep_for(three_seconds);
		}
		}
	}
};

int main() {
	cout << "What is the current user input" << endl;
	string currentLight;
	bool intersection;
	string userInput;
	cin >> currentLight;
	cin >> userInput;

	if (userInput == "yes") {
		intersection = true;
	}
	if (intersection) {
		TrafficManager TrafficManager1(currentLight, intersection);
		TrafficManager1.trafficforIntersection();
	}
	return 0;
}
