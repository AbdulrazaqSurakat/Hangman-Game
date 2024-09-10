#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;


class TrafficManager {
public:
	string currentLight;
	bool intersection;
	int redDuration = 60;
	int yellowDuration = 60;
	int greenDuration = 60;
	TrafficManager(string CurrentLight, bool Intersection) :currentLight(CurrentLight), intersection(Intersection) {}

	void currentTrafficLight() {
		if (currentLight == "Red") {
			
			auto sixty_seconds = 60s;
			this_thread::sleep_for(sixty_seconds);
			cout << "Yellow" << endl;
			auto three_seconds = 3s;
			this_thread::sleep_for(three_seconds);
			cout << "Green" << endl;

			this_thread::sleep_for(sixty_seconds);
		}
		else if (currentLight == "Yellow") {
			
			auto three_seconds = 3s;
			this_thread::sleep_for(three_seconds);
			cout << "Green" << endl;
			auto sixty_seconds = 60s;
			this_thread::sleep_for(sixty_seconds);
			cout << "Red" << endl;

			this_thread::sleep_for(sixty_seconds);
		}
		else if (currentLight == "Green") {
			
			auto sixty_seconds = 60s;
			this_thread::sleep_for(sixty_seconds);
			cout << "Red" << endl;

			this_thread::sleep_for(sixty_seconds);
			cout << "Yellow" << endl;
			auto three_seconds = 3s;
			this_thread::sleep_for(three_seconds);
		}
	}
};

int main() {
	cout << "What is the current user input" << endl;
	string currentLight;
	bool intersection;
	cin >> currentLight;
	cin >> intersection;

	TrafficManager TrafficManager1(currentLight, intersection);

	TrafficManager1.currentTrafficLight();

	return 0;
}
