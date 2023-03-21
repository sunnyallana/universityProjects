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
			cout << endl << question << endl;
			cout << endl << "Enter: ";
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
			cout << endl << "Enter: ";
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
			cout << endl << "Enter: ";
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
			cout << endl << "Enter: ";
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
			cout << endl << "Enter: ";
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
		cout << "\t\t\t\t\tUnlock the Secrets of Your Personality\n\t\t\t\t-------------------------------------------------------" << endl;
		setMind();		system("cls");
		cout << "\t\t\t\t\tUnlock the Secrets of Your Personality\n\t\t\t\t-------------------------------------------------------" << endl;
		setEnergy();	system("cls");
		cout << "\t\t\t\t\tUnlock the Secrets of Your Personality\n\t\t\t\t-------------------------------------------------------" << endl;
		setNature();	system("cls");
		cout << "\t\t\t\t\tUnlock the Secrets of Your Personality\n\t\t\t\t-------------------------------------------------------" << endl;
		setTactics();	system("cls");
		cout << "\t\t\t\t\tUnlock the Secrets of Your Personality\n\t\t\t\t-------------------------------------------------------" << endl;
		setIdentity();	system("cls");
	}

	void displayPersonality() const {
		if (mind == NULL || energy == NULL || nature == NULL || tactics == NULL || identity == NULL) {
			cout << "Not Set" << endl;
			return;
		}
		else {
			cout << mind << energy << nature << tactics << "-" << identity << endl;
		}
	}
};


class user {
private:
	string name;
	int dayOfBirth;
	int monthOfBirth;
	int yearOfBirth;
	int age;
	string zodiacSign;
	string userId;
	string password;
	personalityQuiz* personality;
public:
	user(const string receiveName, const int receiveDayOfBirth, const int receiveMonthOfBirth, const int receiveYearOfBirth, const string receiveUserId, const string receivePassword) {
		name = receiveName;
		dayOfBirth = receiveDayOfBirth;
		monthOfBirth = receiveMonthOfBirth;
		yearOfBirth = receiveYearOfBirth;
		calculateAge(receiveDayOfBirth, receiveMonthOfBirth, receiveYearOfBirth);
		calculateZodiacSign(receiveDayOfBirth, receiveMonthOfBirth);
		userId = receiveUserId;
		password = receivePassword;
		personality = new personalityQuiz;
	}
	~user() {
		delete[] personality;
	}

	void takePersonalityTest() const {
		personality->setPersonality();
	}
	
	void displayUser() const {
		cout << "Name: " << name << endl;
		cout << "Birth Day: " << dayOfBirth << "/" << monthOfBirth << "/" << yearOfBirth << endl;
		cout << "Age: " << age << endl;
		cout << "Zodiac Sign: " << zodiacSign << endl;
		cout << "Personality Type: "; personality->displayPersonality(); cout << endl;
	}

	void calculateAge(int, int, int);
	void calculateZodiacSign(int, int);


};


void user::calculateAge(int dayOfBirth, int monthOfBirth, int yearOfBirth) {
	int ageValue;
	// Current time
	time_t now = time(0);
	// Pointer to structure "tm" consisting of date/time related information. Syntax found from C++ documentaion
	tm ltm;
	localtime_s(&ltm, &now);
	// To find the year of birth that may need revision based on month and day
	ageValue = (1900 + ltm.tm_year) - yearOfBirth;
	// Updating the ageValue if it requires any updation
	if ((monthOfBirth > 1 + ltm.tm_mon) || ((monthOfBirth == 1 + ltm.tm_mon) && (dayOfBirth > ltm.tm_mday))) {
		ageValue--;
	}
	age = ageValue;
}
void user::calculateZodiacSign(int day, int month) {
	// Self reminder to make sure that valid day and month reach here. Exception handling required.....
	if ((day >= 20 && month == 1) || (day <= 18 && month == 2))
	{
		zodiacSign = "Aquarius";
	}
	else if ((day >= 19 && month == 2) || (day <= 20 && month == 3))
	{
		zodiacSign = "Pisces";
	}
	else if ((day >= 21 && month == 3) || (day <= 19 && month == 4))
	{
		zodiacSign = "Aries";
	}
	else if ((day >= 20 && month == 4) || (day <= 20 && month == 5))
	{
		zodiacSign = "Taurus";
	}
	else if ((day >= 21 && month == 5) || (day <= 20 && month == 6))
	{
		zodiacSign = "Gemini";
	}
	else if ((day >= 21 && month == 6) || (day <= 22 && month == 7))
	{
		zodiacSign = "Cancer";
	}
	else if ((day >= 23 && month == 7) || (day <= 22 && month == 8))
	{
		zodiacSign = "Leo";
	}
	else if ((day >= 23 && month == 8) || (day <= 22 && month == 9))
	{
		zodiacSign = "Virgo";
	}
	else if ((day >= 23 && month == 9) || (day <= 22 && month == 10))
	{
		zodiacSign = "Libra";
	}
	else if ((day >= 23 && month == 10) || (day <= 21 && month == 11))
	{
		zodiacSign = "Scorpio";
	}
	else if ((day >= 22 && month == 11) || (day <= 21 && month == 12))
	{
		zodiacSign = "Sagittarius";
	}
	else if ((day >= 22 && month == 12) || (day <= 19 && month == 1))
	{
		zodiacSign = "Capricorn";
	}
}








int main(void) {
	system("Color F0");
	user uOne("Sunny", 15, 9, 2003, "12", "su");
	uOne.takePersonalityTest();
	uOne.displayUser();
	return 0;
}