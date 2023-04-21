#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <stdexcept>
using namespace std;

// Necessary Declarations
static int userCount = 0;
void returnToLoginPage();
bool isValidDate(int day, int month, int year);
inline void writeUserCountToFile();

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
			if (answer >= 1 && answer <= 3) { introvertCount++; }
			else { extravertCount++; }
		}

		if (introvertCount > extravertCount) { mind = 'I'; }
		else { mind = 'E'; }
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
		if ((mind != 'I' && mind != 'E') || (energy != 'N' && energy != 'S') || (nature != 'T' && nature != 'F') || (tactics != 'J' && tactics != 'P') || (identity != 'A' && identity != 'T')) {
			cout << "Not Set" << endl;
			return;
		}
		else {
			cout << mind << energy << nature << tactics << "-" << identity << endl;
		}
	}
};

class person {
protected:
	string name;
	int dayOfBirth;
	int monthOfBirth;
	int yearOfBirth;
	int age;
	string username;
	string password;
public:
	// Constructor Overloading
	person() {
		name = "";
		dayOfBirth = NULL;
		monthOfBirth = NULL;
		yearOfBirth = NULL;
		age = NULL;
		username = "";
		password = "";
	}
	person(string receiveName, string receiveAdminId, string receivePassword) {
		name = receiveName;
		username = receiveAdminId;
		password = receivePassword;
	}
	person(const string receiveName, const int receiveDayOfBirth, const int receiveMonthOfBirth, const int receiveYearOfBirth, const string receiveUsername, const string receivePassword) {
		name = receiveName;
		username = receiveUsername;
		password = receivePassword;
		dayOfBirth = receiveDayOfBirth;
		monthOfBirth = receiveMonthOfBirth;
		yearOfBirth = receiveYearOfBirth;
	}
	virtual void displayDetails() const = 0;

	// Setters and getters used in verifyUser() function
	void setName(const string& receiveName) { name = receiveName; }
	void setDayOfBirth(const int& receiveDayOfBirth) { dayOfBirth = receiveDayOfBirth; }
	void setMonthOfBirth(const int& receiveMonthOfBirth) { monthOfBirth = receiveMonthOfBirth; }
	void setYearOfBirth(const int& receiveYearOfBirth) { yearOfBirth = receiveYearOfBirth; }
	void setUsername(const string& receiveUserName) { username = receiveUserName; }
	void setPassword(const string& receivePassword) { password = receivePassword; }


	inline string getName() const { return name; }
	inline int getDayOfBirth() const { return dayOfBirth; }
	inline int getMonthOfBirth() const { return monthOfBirth; }
	inline int getYearOfBirth() const { return yearOfBirth; }
	inline string getUsername() const { return username; }
	inline string getPassword() const { return password; }

};

class user : public person {
private:
	bool status;
	string zodiacSign;
	personalityQuiz* personality;
public:
	friend class admin;
	friend void populateArray(user* User);

	user() {
		zodiacSign = "";
		personality = new personalityQuiz();
		status = true;
	}
	user(const string receiveName, const int receiveDayOfBirth, const int receiveMonthOfBirth, const int receiveYearOfBirth, const string receiveUsername, const string receivePassword, const bool receiveStatus)
		: person(receiveName, receiveDayOfBirth, receiveMonthOfBirth, receiveYearOfBirth, receiveUsername, receivePassword) {
		calculateAge(receiveDayOfBirth, receiveMonthOfBirth, receiveYearOfBirth);
		calculateZodiacSign(receiveDayOfBirth, receiveMonthOfBirth);
		personality = new personalityQuiz();
		status = receiveStatus;
	}
	~user() {
		delete personality;
	}

	void setStatus(const bool& receiveStatus) { status = receiveStatus; }
	inline bool getStatus() const { return status; }

	void takePersonalityTest() const {
		personality->setPersonality();
	}
	void calculateAge(int, int, int);
	void calculateZodiacSign(int, int);
	bool createUser(string, string, string, int, int, int, bool);
	bool verifyUser(string, string);
// Used by User
	void displayDetails() const {
		cout << "Name: " << name << endl;
		cout << "Birth Day: " << dayOfBirth << "/" << monthOfBirth << "/" << yearOfBirth << endl;
		cout << "Age: " << age << endl;
		cout << "Zodiac Sign: " << zodiacSign << endl;
		cout << "Personality Type: ";  personality->displayPersonality(); cout << endl;
	}
	friend ostream& operator <<(ostream& ostreamObject, const user& userObject);
	friend istream& operator >>(istream& istreamObject, user& userObject);
};

// Used by Admin
ostream& operator <<(ostream& ostreamObject, const user& userObject) {
	ostreamObject << "Name: " << userObject.name << endl;
	ostreamObject << "Username: " << userObject.username << endl;
	ostreamObject << "Birth Day: " << userObject.dayOfBirth << "/" << userObject.monthOfBirth << "/" << userObject.yearOfBirth << endl;
	ostreamObject << "Age: " << userObject.age << endl;
	ostreamObject << "Zodiac Sign: " << userObject.zodiacSign << endl;
	ostreamObject << "Status: " << (userObject.status ? "Active" : "Inactive") << endl;
	return ostreamObject;
}
istream& operator >>(istream& istreamObject, user& userObject) {
	cout << "Enter Password (at least 4 characters, must contain at least one uppercase letter, one lowercase letter, one digit, and one special character): ";
	while (true) {
		char ch = _getch();
		if (ch == '\r') {
			break;
		}
		if (ch == '\b') {
			if (!userObject.password.empty()) {
				userObject.password.pop_back();
				cout << "\b \b";
			}
		}
		else {
			userObject.password.push_back(ch);
			cout << "*";
		}
	}
	cout << endl;
	if (userObject.password.length() < 4) {
		cout << "Password must be at least 4 characters long. Please try again." << endl;
		userObject.password.clear();
		istreamObject >> userObject;
		return istreamObject;
	}
	bool hasUppercase = false;
	bool hasLowercase = false;
	bool hasDigit = false;
	bool hasSpecial = false;
	for (char c : userObject.password) {
		if (isupper(c)) {
			hasUppercase = true;
		}
		else if (islower(c)) {
			hasLowercase = true;
		}
		else if (isdigit(c)) {
			hasDigit = true;
		}
		else if (ispunct(c)) {
			hasSpecial = true;
		}
	}
	if (!hasUppercase || !hasLowercase || !hasDigit || !hasSpecial) {
		cout << "Password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character. Please try again." << endl;
		userObject.password.clear();
		istreamObject >> userObject;
		return istreamObject;
	}

	// Exception handling for birthday input
	try {
		cout << "Enter your Birthday [dd mm yyyy]: ";
		istreamObject >> userObject.dayOfBirth >> userObject.monthOfBirth >> userObject.yearOfBirth;
		if (!isValidDate(userObject.dayOfBirth, userObject.monthOfBirth, userObject.yearOfBirth)) {
			throw invalid_argument("Invalid date");
		}
	}
	catch (const invalid_argument& e) {
		cout << "Invalid birthday entered. Please try again." << endl;
		userObject.dayOfBirth = 0;
		userObject.monthOfBirth = 0;
		userObject.yearOfBirth = 0;
		userObject.password.clear();
		istreamObject.clear();
		istreamObject.ignore();
		istreamObject >> userObject;
		return istreamObject;
	}

	cout << "Enter your Name: ";
	cin.ignore();
	getline(cin, userObject.name);
	userObject.createUser(userObject.username, userObject.password, userObject.name, userObject.dayOfBirth, userObject.monthOfBirth, userObject.yearOfBirth, false);
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

bool user::createUser(string receiveUsername, string receivePassword, string receiveName, int receiveDayOfBirth, int receiveMonthOfBirth, int receiveYearOfBirth, bool receiveStatus) {
	ofstream fout("users.txt", ios_base::app);
	if (fout.is_open()) {
		fout << receiveUsername << endl;
		fout << receivePassword << endl;
		fout << receiveName << endl;
		fout << receiveDayOfBirth << endl;
		fout << receiveMonthOfBirth << endl;
		fout << receiveYearOfBirth << endl;
		fout << receiveStatus << endl;
		fout.close();
		return true;
	}
	return false;
}

bool user::verifyUser(string username, string password) {
	ifstream fin("users.txt");
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

class admin : public person {
private:
public:
	admin(string receiveName, string receiveAdminId, string receivePassword)
		: person(receiveName, receiveAdminId, receivePassword) {}

	inline string getUsername() const { return username; }
	inline string getPassword() const { return password; }
	void displayDetails() const {}

	void displayDetails(user* userObject) {
		for (int i = 0; i < userCount; i++) {
			cout << userObject[i] << endl;
		}
	}

	void deleteUser(user* User);
	void displayInactiveUsers(user* User);
	void changeStatusAll(user* User);
	void changeStatusSpecific(user* User);
	void editUser(user* User);
	void editOrDelete(user* User);
};



void admin:: deleteUser(user* User) {
	string usernameToDelete;
	cout << "Enter the username of the user you want to delete: ";
	cin >> usernameToDelete;

	int indexToDelete = -1;
	for (int i = 0; i < userCount; i++) {
		if (User[i].username == usernameToDelete) {
			indexToDelete = i;
			break;
		}
	}
	if (indexToDelete == -1) {
		cout << "Error: User not found." << endl;
		return;
	}
	for (int i = indexToDelete; i < userCount - 1; i++) {
		User[i] = User[i + 1];
	}
	userCount--;
	ofstream outfile("users.txt");
	if (!outfile.is_open()) {
		cout << "Error: Failed to open output file." << endl;
		return;
	}
	for (int i = 0; i < userCount; i++) {
		outfile << User[i].username << endl;
		outfile << User[i].password << endl;
		outfile << User[i].name << endl;
		outfile << User[i].dayOfBirth << endl;
		outfile << User[i].monthOfBirth << endl;
		outfile << User[i].yearOfBirth << endl;
		outfile << User[i].status << endl;
	}
	outfile.close();
	writeUserCountToFile();
}

void admin::displayInactiveUsers(user* User) {
	for (int i = 0; i < userCount; i++) {
		if (!User[i].status) {
			cout << User[i] << endl;
		}
	}
}

void admin::changeStatusAll(user* User) {
	bool newStatus;
	cout << "Enter the new status (1 for active, 0 for inactive): ";
	cin >> newStatus;

	try {
		if (cin.fail()) {
			throw "Invalid input. Please enter a boolean value (1 or 0).";
		}

		for (int i = 0; i < userCount; i++) {
			User[i].status = newStatus;
		}

		ofstream outfile("users.txt");
		if (!outfile.is_open()) {
			throw "Failed to open output file.";
		}

		for (int i = 0; i < userCount; i++) {
			outfile << User[i].username << endl;
			outfile << User[i].password << endl;
			outfile << User[i].name << endl;
			outfile << User[i].dayOfBirth << endl;
			outfile << User[i].monthOfBirth << endl;
			outfile << User[i].yearOfBirth << endl;
			outfile << User[i].status << endl;
		}

		outfile.close();
	}
	catch (const char* msg) {
		cerr << "Error: " << msg << endl;
	}
}

void admin::changeStatusSpecific(user* User) {
	string usernameToChange;
	cout << "Enter the username of the user you want to change the status of: ";
	cin >> usernameToChange;

	bool newStatus;
	cout << "Enter the new status (1 for active, 0 for inactive): ";
	cin >> newStatus;
	try {
		if (cin.fail()) {
			throw "Invalid input. Please enter a boolean value (1 or 0).";
		}
		int indexToChange = -1;
		for (int i = 0; i < userCount; i++) {
			if (User[i].username == usernameToChange) {
				indexToChange = i;
				break;
			}
		}
		if (indexToChange == -1) {
			throw "User not found.";
		}
		User[indexToChange].status = newStatus;

		ofstream outfile("users.txt");
		if (!outfile.is_open()) {
			throw "Failed to open output file.";
		}
		for (int i = 0; i < userCount; i++) {
			outfile << User[i].username << endl;
			outfile << User[i].password << endl;
			outfile << User[i].name << endl;
			outfile << User[i].dayOfBirth << endl;
			outfile << User[i].monthOfBirth << endl;
			outfile << User[i].yearOfBirth << endl;
			outfile << User[i].status << endl;
		}
		outfile.close();
	}
	catch (const char* msg) {
		cerr << "Error: " << msg << endl;
	}
}

void admin::editUser(user* User) {
	string usernameToEdit;
	cout << "Enter the username of the user you want to edit: ";
	cin >> usernameToEdit;

	int indexToEdit = -1;
	for (int i = 0; i < userCount; i++) {
		if (User[i].username == usernameToEdit) {
			indexToEdit = i;
			break;
		}
	}
	if (indexToEdit == -1) {
		cout << "Error: User not found." << endl;
		return;
	}

	try {
		// Allow the user to edit the user's information
		cout << "Enter new information for the user (or press enter to keep the current value):" << endl;
		cout << "Name: ";
		string name;
		getline(cin >> ws, name); // getline used to handle spaces in input
		if (!name.empty()) {
			User[indexToEdit].name = name;
		}

		cout << "Password: ";
		string password;
		getline(cin >> ws, password);
		if (!password.empty()) {
			User[indexToEdit].password = password;
		}

		cout << "Date of birth (DD MM YYYY): ";
		int day, month, year;
		cin >> day >> month >> year;
		if (day <= 0 || day > 31) {
			throw "Invalid day entered";
		}
		if (month <= 0 || month > 12) {
			throw "Invalid month entered";
		}
		if (year <= 0) {
			throw "Invalid year entered";
		}
		User[indexToEdit].dayOfBirth = day;
		User[indexToEdit].monthOfBirth = month;
		User[indexToEdit].yearOfBirth = year;

		// Save the updated user information to file
		ofstream outfile("users.txt");
		if (!outfile.is_open()) {
			throw "Failed to open output file";
		}
		for (int i = 0; i < userCount; i++) {
			outfile << User[i].username << endl;
			outfile << User[i].password << endl;
			outfile << User[i].name << endl;
			outfile << User[i].dayOfBirth << endl;
			outfile << User[i].monthOfBirth << endl;
			outfile << User[i].yearOfBirth << endl;
			outfile << User[i].status << endl;
		}
		outfile.close();

		cout << "User information updated successfully!" << endl;
	}
	catch (const char* errorMessage) {
		cout << "Error: " << errorMessage << endl;
	}
}

void admin::editOrDelete(user* User) {
	try {
		int choice;
		cout << "Enter 1 to edit user, 2 to delete user: ";
		cin >> choice;

		switch (choice) {
		case 1:
			editUser(User);
			break;
		case 2:
			deleteUser(User);
			break;
		default:
			throw "Invalid choice.";
		}
	}
	catch (const char* msg) {
		cerr << "Error: " << msg << endl;
	}
	catch (...) {
		cerr << "Error: Unknown exception." << endl;
	}
}