#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;


void returnToLoginPage();


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
			if (answer >= 1 && answer <= 3) {introvertCount++;}
			else {extravertCount++;}
		}

		if (introvertCount > extravertCount) {mind = 'I';}
		else {mind = 'E';}
		mindFile.close();
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
		energyFile.close();
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
		natureFile.close();
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
		tacticsFile.close();
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
		identityFile.close();
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


class admin {
private:
	string name;
	string username;
	string password;
	static int countUser;
public:
	admin() {
		name = "";
		username = "";
		password = "";
	}
	admin(string receiveName, string receiveAdminId, string receivePassword) {
		name = receiveName;
	    username = receiveAdminId;
		password = receivePassword;
	}

	string getUsername() const { return username; }
	string getPassword() const { return password; }
	static int getCountUser() {return countUser;}
	static void increamentCountUser() {countUser++;}
};
int admin::countUser = 0;




class user {
private:
	string name;
	int dayOfBirth;
	int monthOfBirth;
	int yearOfBirth;
	int age;
	string zodiacSign;
	string username;
	string password;
	personalityQuiz* personality;
public:
	user() {
		name = "";
		dayOfBirth = NULL;
		monthOfBirth = NULL;
		yearOfBirth = NULL;
		age = NULL;
		zodiacSign = "";
		username = "";
		password = "";
		personality = new personalityQuiz;
		admin::increamentCountUser();
	}
// Useless at the moment
	user(const string receiveName, const int receiveDayOfBirth, const int receiveMonthOfBirth, const int receiveYearOfBirth, const string receiveUsername, const string receivePassword) {
		name = receiveName;
		dayOfBirth = receiveDayOfBirth;
		monthOfBirth = receiveMonthOfBirth;
		yearOfBirth = receiveYearOfBirth;
		calculateAge(receiveDayOfBirth, receiveMonthOfBirth, receiveYearOfBirth);
		calculateZodiacSign(receiveDayOfBirth, receiveMonthOfBirth);
		username = receiveUsername;
		password = receivePassword;
		personality = new personalityQuiz;
		admin::increamentCountUser();
	}
	~user() {
		delete[] personality;
	}

	void setName(const string& receiveName) { name = receiveName; }
	void setDayOfBirth(const int& receiveDayOfBirth) { dayOfBirth = receiveDayOfBirth; }
	void setMonthOfBirth(const int& receiveMonthOfBirth) { monthOfBirth = receiveMonthOfBirth; }
	void setYearOfBirth(const int& receiveYearOfBirth) { yearOfBirth = receiveYearOfBirth; }
	void setUsername(const string& receiveUserName) { username = receiveUserName; }
	void setPassword(const string& receivePassword) { password = receivePassword; }

	string getName() const { return name; }
	int getDayOfBirth() const { return dayOfBirth; }
	int getMonthOfBirth() const { return monthOfBirth; }
	int getYearOfBirth() const { return yearOfBirth; }
	string getUsername() const { return username; }
	string getPassword() const { return password; }


	void takePersonalityTest() const {
		personality->setPersonality();
	}
	
	void calculateAge(int, int, int);
	void calculateZodiacSign(int, int);
	bool createUser(string, string, string, int, int, int);
	bool verifyUser(string, string);


	friend ostream& operator <<(ostream& ostreamObject, const user& userObject);
	friend istream& operator >>(istream& istreamObject, user& userObject);
};

// Operator overloading for personality display
ostream& operator <<(ostream& ostreamObject, const user& userObject) {
	ostreamObject << "Name: " << userObject.name << endl;
	ostreamObject << "Birth Day: " << userObject.dayOfBirth << "/" << userObject.monthOfBirth << "/" << userObject.yearOfBirth << endl;
	ostreamObject << "Age: " << userObject.age << endl;
	ostreamObject << "Zodiac Sign: " << userObject.zodiacSign << endl;
	ostreamObject << "Personality Type: "; userObject.personality->displayPersonality(); ostreamObject << endl;
	return ostreamObject;
}
istream& operator >>(istream& istreamObject, user& userObject) {
	cout << "Enter Username: "; istreamObject >> userObject.username;
	cout << "Enter Password: ";
	char ch = _getch();
	while (ch != '\r') {
		if (ch != '\b') { (userObject.password).push_back(ch); cout << "*"; }
		else if (!(userObject.password).empty()) { (userObject.password).pop_back(); cout << "\b \b"; }
		ch = _getch();
	}
	cout << endl;
	cout << "Enter your Name: "; cin.ignore();  getline(cin, userObject.name);
	cout << "Enter your Birthday [dd mm yyyy]: "; istreamObject >> userObject.dayOfBirth >> userObject.monthOfBirth >> userObject.yearOfBirth;
	userObject.createUser(userObject.username, userObject.password, userObject.name, userObject.dayOfBirth, userObject.monthOfBirth, userObject.yearOfBirth);
	cout << "User has successfully been created. You may login now....." << endl;
	return istreamObject;
}


void user::calculateAge(int dayOfBirth, int monthOfBirth, int yearOfBirth) {
	int ageValue;
	// Current time
	time_t now = time(0);
	// Pointer of structure tm consisting of date/time related information. Syntax found from C++ documentaion
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
	zodiacSign = (day >= 20 && month == 1) || (day <= 18 && month == 2) ? "Aquarius" :
		(day >= 19 && month == 2) || (day <= 20 && month == 3) ? "Pisces" :
		(day >= 21 && month == 3) || (day <= 19 && month == 4) ? "Aries" :
		(day >= 20 && month == 4) || (day <= 20 && month == 5) ? "Taurus" :
		(day >= 21 && month == 5) || (day <= 20 && month == 6) ? "Gemini" :
		(day >= 21 && month == 6) || (day <= 22 && month == 7) ? "Cancer" :
		(day >= 23 && month == 7) || (day <= 22 && month == 8) ? "Leo" :
		(day >= 23 && month == 8) || (day <= 22 && month == 9) ? "Virgo" :
		(day >= 23 && month == 9) || (day <= 22 && month == 10) ? "Libra" :
		(day >= 23 && month == 10) || (day <= 21 && month == 11) ? "Scorpio" :
		(day >= 22 && month == 11) || (day <= 21 && month == 12) ? "Sagittarius" :
		(day >= 22 && month == 12) || (day <= 19 && month == 1) ? "Capricorn" :
		"Invalid date";
}

bool user::createUser(string receiveUsername, string receivePassword, string receiveName, int receiveDayOfBirth, int receiveMonthOfBirth, int receiveYearOfBirth) {
	ofstream fout("users.bin", ios_base::app);
	if (fout.is_open()) {
		fout << receiveUsername << endl;
		fout << receivePassword << endl;
		fout << receiveName << endl;
		fout << receiveDayOfBirth << endl;
		fout << receiveMonthOfBirth << endl;
		fout << receiveYearOfBirth << endl;
		fout.close();
		return true;
	}
	return false;
}

bool user::verifyUser(string username, string password) {
	ifstream fin("users.bin");
	string lineStr; int lineInt;
	while (getline(fin, lineStr)) {
		if (lineStr == username) {
			setUsername(username);
			getline(fin, lineStr);
			if (lineStr == password) {
				setPassword(password);
				getline(fin, lineStr); setName(lineStr);
				fin >> lineInt; setDayOfBirth(lineInt);
				fin >> lineInt; setMonthOfBirth(lineInt);
				fin >> lineInt; setYearOfBirth(lineInt);
				calculateAge(getDayOfBirth(), getMonthOfBirth(), getYearOfBirth());
				calculateZodiacSign(getDayOfBirth(), getMonthOfBirth());
				fin.close();
				return true;
			}
		}
	}
	fin.close();
	return false;
}

int main(void) {
	system("Color F0");
	admin Admin("Sunny", "sunny", "4149");
	user User;

	cout << "______________________________________________LoginIn or SignUp_______________________________________\n\n1) Login\n2) SignUp" << endl;
	int userChoice;
// Exception handling for invalid user choice
	do {
		cout << "Enter Choice: ";
		cin >> userChoice;
	} while (userChoice < 1 || userChoice > 2);
	if (userChoice == 1) {
		string tempUsername, tempPassword;
		cout << "Enter Username: "; cin >> tempUsername;
		cout << "Enter Password: ";
		char ch = _getch();
		while (ch != '\r'){
			if (ch != '\b'){tempPassword.push_back(ch);cout << "*";}
			else if (!tempPassword.empty()){tempPassword.pop_back();cout << "\b \b";}
			ch = _getch();
		}
		cout << endl;
		if (Admin.getUsername() == tempUsername && Admin.getPassword() == tempPassword) {
			cout << "Admin Session" << endl;
		}







		else if (User.verifyUser(tempUsername, tempPassword) == 1) {
			cout << "User Session" << endl;
			cout << User << endl; // Just to test execution
		}
		else {
			cout << "Login Failed" << endl;
			returnToLoginPage();
		}
	}
	else if (userChoice == 2) {
		cin >> User;
		returnToLoginPage();
	}
	else {
		cout << "Invalid Choice." << endl;
		returnToLoginPage();
	}

	return 0;
}

void returnToLoginPage()  {
	string returnChoice;
	cout << "Would you like to return to the Login Page [Yes | No] ?:  ";
	cin >> returnChoice;
	// Convert input to lowercase
	for (int i = 0; i < returnChoice.length(); i++) {
		returnChoice[i] = tolower(returnChoice[i]);
	}
	if (returnChoice == "yes") {
		cout << "\nRedirecting to the Login Page....." << endl;
		Sleep(1000);
		system("cls");
		// Calling main recursively to return to the login page
		main();
	}
	else if (returnChoice == "no") {
		cout << "\nStaying on the Same Page" << endl;
	}
	else {
		cout << "\nInvalid Choice" << endl;
	}
}
