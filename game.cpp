#include <iostream>
#include <string>
using namespace std;


class Animatronic {
	public:
		Animatronic (string nameS, double rageA) {
			name = nameS;
			rage = rageA;
		}

		string getName() {
			return name;
		}

		double getRage() {
			return rage;

		}

		void incRage(double r) {
			rage = rage+r;
		}

		string getPlace() {
			if (((rage*2)/7)>=1) {
				if (name == "Chicka") {
					return "Chicka is on the Right Door \n \n";
				}else if (name == "Bonnie") {
					return "Bonnie is on the Left Door \n \n";
				}else if (name == "Freddy") {
					return "Freddy is Close \n \n";
				}
			}else if (((rage*2)/7)<1 && ((rage*2)/7) > 0.5) {
				if (name == "Chicka") {
					return "Chicka is in the Kitchen \n \n";
				}else if (name == "Bonnie") {
					return "Bonnie is in the Staff Room \n \n";
				}else if (name == "Freddy") {
					return "Freddy is in the party place \n \n";
				}
			}else {
				if (name == "Chicka") {
					return "Chicka is in the theatre \n \n";
				}else if (name == "Bonnie") {
					return "Bonnie is in the theatre \n \n";
				}else if (name == "Freddy") {
					return "Freddy is in the theatre \n \n";
				}
			}
		}

	private:
		string name;
		double rage;
};





int main () {
	int night = 1;
	int answer;
	bool start = true;
	bool win,lost = false;
	Animatronic freddy("Freddy",1);
	Animatronic Chicka ("Chicka",1.5);
	Animatronic Bonnie ("Bonnie",1.5);


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
			cout << "1-Check Right Door \n 2-Check left Door \n 3-Check Camera \n 4-Close right Door \n 5-Close Left Door \n";
			cin >> answer;
			switch (answer) {
				case 1:
					if (Chicka.getPlace() == "Chicka is on the Right Door \n \n") {
						cout << "Chicka is on the Right Door... \n";

					}
					break;
				case 2:

					break;
				case 3:
					cout << Chicka.getPlace() << endl;
					cout << Chicka.getRage() << endl;
					break;

				case 4:
					if (Chicka.getPlace() == "Chicka is on the Right Door") {
						Chicka.incRage(-0.5);

					}else {
						Chicka.incRage(0.5);
					}
					break;

				case 5:
					break;
			}
		}
	}
}