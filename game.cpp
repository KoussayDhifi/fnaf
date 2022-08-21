#include <iostream>
#include <string>
using namespace std;

class Animat {

	public:
		Animat (string name, double rage, int noj) {
			name = name;
			rage = rage;
			noj = noj;
			if (rage<2.5) {
				position = 1;

			}else if (rage>=2.5 && rage<3.5) {
				position = 2;
			}else {
				position = 3;
			}
		}

		int getPos () {
			if (rage<2.5) {
				position = 1;

			}else if (rage>=2.5 && rage<3.5) {
				position = 2;
			}else {
				position = 3;
			}

			return position;
		}

		int getNoj () {
			return noj;

		}

		int getA () {
			return A_noj;
		}


		string getName () {
			return name;
		}


		void IncRage(double r) {
			rage = rage+r;
		}

		void IncNoj (int k) {
			A_noj += k;
		}



	private:
		string name;
		double rage;
		int noj;
		int position;
		int A_noj = 0;
};


int main () {
	//Declaring Animatronics
	Animat chicka ("Chicka", 1.5, 3);

	Animat bonnie ("Bonnie", 1, 2);

	//Main variables
	int answer;
	int night = 1;
	int power = 100;
	int time = 1;
	bool left_door = true;
	bool right_door = true;
	bool win = false;
	bool lost = false;

	//Game Loop
	while (!(win || lost)) {
		//Menu
		cout << "Five Night's at Bonnie&&Chicka: \n ";
		cout << "1- Play Game (Night 1) \n";
		cout << "2-Quit Game \n";
		cin >> answer;

		switch (answer) {
			case 2:
				win = true;
				break;
			case 1:
				//Game
				while (! (win || lost))
				{
				cout << "Night: " << night << endl;
				cout << "Time: " << time << "AM" << endl;
				cout << "Power: " << power << "%" << endl;

				cout << "1-Check Camera 1 \n";
				cout << "2-Check Camera 2 \n";
				if (right_door) {
					cout << "3-Close Right Door \n";

				}else if (! right_door) {
					cout << "3-Open Right Door \n";
				}
				if (left_door) {
					cout << "4-Close Left Door \n";

				}else if (! left_door) {
					cout << "4-Open Left Door \n";
				}

				cout << "5-Check Right door \n";
				cout << "6-Check left Door \n";
				cout << "7-Do nothing \n";
				cin >> answer;

				//Answers
				switch (answer) {
					case 1:
						if (chicka.getPos() == 1) {
							cout << "Chicka is on Camer 1 (Far) \n";
						}else {
							cout << "Chicka is not on camera 1 \n";
						}
						if (bonnie.getPos() == 1) {
							cout << "Bonnie is on camera 1 (Far) \n";
						}else {
							cout << "Bonnie is not on camera 1 \n";
						}
						power -= 5;
						break;
					case 2 :
						if (chicka.getPos() == 2) {
							cout << "Chicka is on Camer 2 (Far) \n";
						}else {
							cout << "Chicka is not on camera 2 \n";
						}
						if (bonnie.getPos() == 2) {
							cout << "Bonnie is on camera 2 (Far) \n";
						}else {
							cout << "Bonnie is not on camera 2 \n";
						}
						power -= 5;
						break;

					case 3:
						if (right_door) {
							right_door = false;
						}else {
							right_door = true;
						}
						break;
					case 4:
						if (left_door) {
							left_door = false;
						}else {
							left_door = true;
						}
						break;

					case 5:
						if (chicka.getPos() == 3) {
							cout << "Chicka is on the right door (Super Close) \n";
						}else {
							cout << "No one is here \n";
						}
						break;
					case 6:
						if (bonnie.getPos() == 3) {
							cout << "Bonnie is on the left door \n";
						}else {
							cout << "No one is here \n";
						}
						break;
					case 7:
						cout << "You've done nothing \n";
						break;


					} //End of switch statement

					if (chicka.getPos() == 3) {
						if (right_door) {
							chicka.IncNoj(1);
						}else {
							chicka.IncNoj(-1);
							chicka.IncRage(-0.5);
						}
					}else {
						chicka.IncRage(0.75);
					}
					if (bonnie.getPos() == 3)
					{
						if (left_door) {
							bonnie.IncNoj(1);
						}else {
							bonnie.IncNoj(-1);
							bonnie.IncRage(-0.25);
						}
					}else {
						bonnie.IncRage(0.5);
					}

					if (chicka.getA() == chicka.getNoj()) {
						cout << "Chicka Jumped and killed ya... \n";
						lost = true;
					}
					if (bonnie.getA() == bonnie.getNoj()) {
						cout << "Bonnie Killed ya... \n";
						lost = true;
					}

					

				}
				break;

		}
	}

}