#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

class personalityQuiz {
private:
// Introverted(I) or extraverted(E)
	char mind;
// Intuitive(N) or Observant(S)
	char energy;
// Thinking(T) or Feeling(F)
	char nature;
// Judging(J) vs Prospecting(P)
	char tactics;
// Assertive(A) vs Turbulent(T)
	char identity;
public:
	personalityQuiz() {
		mind = NULL;
		energy = NULL;
		nature = NULL;
		tactics = NULL;
		identity = NULL;
	}
	void setMind() {
		string question;
		int answer = 0, introvertCount = 0, extravertCount = 0;
		ifstream mindFile("mind.txt");
		for (int i = 0; i < 5; i++) {
			getline(mindFile, question);
			cout <<  endl << question << endl;
			cout << "Enter: ";
			cin >> answer;

			if (answer >= 1 && answer <= 3) {
				introvertCount++;
			}
			else {
				extravertCount++;
			}
		}
		if (introvertCount > extravertCount) {
			mind = 'I';
		}
		else {
			mind = 'E';
		}
	}
	void setEnergy() {
		string question;
		int answer = 0, intuitiveCount = 0, observantCount = 0;
		ifstream energyFile("energy.txt");
		for (int i = 0; i < 5; i++) {
			getline(energyFile, question);
			cout << endl << question << endl;
			cout << "Enter: ";
			cin >> answer;

			if (answer >= 1 && answer <= 3) {
				observantCount++;
			}
			else {
				intuitiveCount++;
			}
		}
		if (observantCount > intuitiveCount) {
			energy = 'S';
		}
		else {
			energy = 'T';
		}
	}

	void setNature() {
		string question;
		int answer = 0, thinkingCount = 0, feelingCount = 0;
		ifstream natureFile("nature.txt");
		for (int i = 0; i < 5; i++) {
			getline(natureFile, question);
			cout << endl << question << endl;
			cout << "Enter: ";
			cin >> answer;

			if (answer > 1 && answer <= 3) {
				thinkingCount++;
			}
			else {
				feelingCount++;
			}
		}
		if (thinkingCount > feelingCount) {
			nature = 'T';
		}
		else {
			nature = 'F';
		}
	}
	void setTactics() {
		string question;
		int answer = 0, prospectingCount = 0, judgingCount = 0;
		ifstream tacticsFile("tactics.txt");
		for (int i = 0; i < 5; i++) {
			getline(tacticsFile, question);
			cout << endl << question << endl;
			cout << "Enter: ";
			cin >> answer;

			if (answer >= 1 && answer <= 3) {
				judgingCount++;
			}
			else {
				prospectingCount++;
			}
		}
		if (prospectingCount > judgingCount) {
			tactics = 'P';
		}
		else {
			tactics = 'J';
		}
	}

	void setIdentity() {
		string question;
		int answer = 0, assertiveCount = 0, turbulentCount = 0;
		ifstream identityFile("identity.txt");
		for (int i = 0; i < 5; i++) {
			getline(identityFile, question);
			cout << endl << question << endl;
			cout << "Enter: ";
			cin >> answer;

			if (answer >= 1 && answer <= 3) {
				turbulentCount++;
			}
			else {
				assertiveCount++;
			}
		}
		if (turbulentCount > assertiveCount) {
			identity = 'T';
		}
		else {
			identity = 'A';
		}
	}

	void setPersonality() {
		setMind();
		setEnergy();
		setNature();
		setTactics();
		setIdentity();
	}


	void displayPersonality() const {
		cout << mind << energy << nature << tactics << "-" << identity << endl;
	}
};


class user {
private:
	string name;
	int birthDay;
	int birthMonth;
	int birthYear;
	int age;
	string zodiacSign;
	string email;
	personalityQuiz* personality;

};










int main(void) {
	system("Color F0");
	personalityQuiz pOne;
	pOne.setPersonality();
	pOne.displayPersonality();
	return 0;
}