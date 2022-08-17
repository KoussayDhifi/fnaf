#include <iostream>
#include <string>
using namespace std;


int main () {
	int night = 1;
	int answer;
	bool start = true;
	bool win,lost = false;

	while (!(win || lost)) {
		if (start) {
			cout << "Welcome to: \n Five Nights at freddy's \n";
			cout << "1-Start Game(Night " << night << ")\n";
			cout << "2-Quit Game \n";
			cin >> answer;
			if (answer == 1) {
				start = false;

			}else {
				break;
			}
		}else {
			cout << "1-Check Right Door \n 2-Check left Door \n 3-Check Camera";
			cin >> answer;
			switch (answer) {
				case 1:

					break;
				case 2:

					break;
				case 3:

					break;
			}
		}
	}
}