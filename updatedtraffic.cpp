#include <iostream>
#include <string>
#include <chrono>
#include <future>
#include <thread>

using namespace std;
void loop1() {
	string currentLight1="Red";
	while (true) {
		auto thrity_seconds = 30s;
		auto three_seconds = 3s;
		cout << currentLight1 << "                 ";
		this_thread::sleep_for(thrity_seconds);
		currentLight1 = "Green";
		cout << currentLight1 << "                 ";
		this_thread::sleep_for(thrity_seconds);
		currentLight1 = "Yellow";
		cout << currentLight1 << "                 ";
		this_thread::sleep_for(three_seconds);

	}
}
void loop2() {
	while (true) {
		string currentLight2="Green";
		auto thrity_seconds = 30s;
		auto three_seconds = 3s;
		cout << currentLight2 << "                 ";
		this_thread::sleep_for(thrity_seconds);
		currentLight2 = "Yellow";
		cout << currentLight2 << "                 ";
		this_thread::sleep_for(three_seconds);
		currentLight2 = "Red";
		cout << currentLight2 << "                 ";
		this_thread::sleep_for(thrity_seconds);
	}
}

class TrafficManager {
public:
	string currentLight1;
	string currentLight2;
	bool intersection;
	TrafficManager(string CurrentLight, bool Intersection) :currentLight1(CurrentLight), intersection(Intersection) {}
	
	void trafficforIntersection() {

		if (intersection && currentLight1 == "Red") {
			cout << "Traffic Light 1/ Traffic Light 2" << endl;
			std::thread t1(loop1);
			std::thread t2(loop2);
			// Wait for threads to finish
			t1.join();
			t2.join();
		}
		if (intersection == true && currentLight1 == "Yellow") {
				cout << "Traffic Light 1    Traffic Light 2    /n" << endl;
				std::thread t1(loop1);
				std::thread t2(loop2);
				// Wait for threads to finish
				t1.join();
				t2.join();
		}
		if (intersection == true && currentLight1 == "Green") {
			cout << "Traffic Light 1    Traffic Light 2    /n" << endl;
			std::thread t1(loop1);
			std::thread t2(loop2);
			// Wait for threads to finish
			t1.join();
			t2.join();
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
