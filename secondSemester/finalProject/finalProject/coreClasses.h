// All preprocessing Directives Required In This Program
#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <stdexcept>
using namespace std;

// Necessary Declarations And Prototypes
static int userCount = 0;
bool isValidDate(int day, int month, int year);
inline void writeUserCountToFile();
// Class to assess user's mind, energy, nature, tactics, and identity
class personalityQuiz {
public:
	char mind;
	char energy;
	char nature;
	char tactics;
	char identity;
	personalityQuiz() {
		mind = '0';
		energy = '0';
		nature = '0';
		tactics = '0';
		identity = '0';
	}
	personalityQuiz(char receiveMind, char receiveEnergy, char receiveNature, char receiveTactics, char receiveIdentity) {
		mind = receiveMind;
		energy = receiveEnergy;
		nature = receiveNature;
		tactics = receiveTactics;
		identity = receiveIdentity;
	}
// Method to assess mind of a person
	void computeMind() {
		string question;
		int answer = 0, introvertCount = 0, extravertCount = 0;
		ifstream mindFile("mind.txt");
		if (!mindFile.is_open()) {
			cout << "Error: Failed to open mind.txt file." << endl;
			return;
		}
		try {
			for (int i = 0; i < 5; i++) {
				getline(mindFile, question);
				cout << endl << question << endl;
				do {
					cout << "Enter: ";
					if (!(cin >> answer)) {
						throw runtime_error("Error: Invalid input.");
					}
					cin.ignore();
					if (answer < 1 || answer > 5) {
						cout << "Invalid input. Please enter a value between 1 and 5." << endl;
					}
				} while (answer < 1 || answer > 5);
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
		catch (const exception& ex) {
			cerr << ex.what() << endl;
			return;
		}
		mindFile.close();
	}
// Method to assess energy of a person
	void computeEnergy() {
		string question;
		int answer = 0, intuitiveCount = 0, observantCount = 0;
		ifstream energyFile("energy.txt");
		try {
			for (int i = 0; i < 5; i++) {
				getline(energyFile, question);
				cout << endl << question << endl;
				do {
					cout << "Enter: ";
					if (!(cin >> answer)) {
						throw runtime_error("Error: Invalid input.");
					}
					cin.ignore();
					if (answer < 1 || answer > 5) {
						cout << "Invalid input. Please enter a value between 1 and 5." << endl;
					}
				} while (answer < 1 || answer > 5);
				if (answer >= 1 && answer <= 3) {
					observantCount++;
				}
				else {
					intuitiveCount++;
				}
			}

			if (observantCount > intuitiveCount) {
				this->energy = 'S';
			}
			else {
				this->energy = 'N';
			}
		}
		catch (const exception& ex) {
			cerr << ex.what() << endl;
			return;
		}
		energyFile.close();
	}
// Method to assess nature of a person
	void computeNature() {
		string question;
		int answer = 0, thinkingCount = 0, feelingCount = 0;
		ifstream natureFile("nature.txt");
		try {
			for (int i = 0; i < 5; i++) {
				getline(natureFile, question);
				cout << endl << question << endl;
				do {
					cout << "Enter: ";
					if (!(cin >> answer)) {
						throw runtime_error("Error: Invalid input.");
					}
					cin.ignore();
					if (answer < 1 || answer > 5) {
						cout << "Invalid input. Please enter a value between 1 and 5." << endl;
					}
				} while (answer < 1 || answer > 5);
				if (answer >= 1 && answer <= 3) {
					thinkingCount++;
				}
				else {
					feelingCount++;
				}
			}
			if (thinkingCount > feelingCount) {
				this->nature = 'T';
			}
			else {
				this->nature = 'F';
			}
		}
		catch (const exception& ex) {
			cerr << ex.what() << endl;
			return;
		}
		natureFile.close();
	}
// Method to assess tactics of a person
	void computeTactics() {
		string question;
		int answer = 0, prospectingCount = 0, judgingCount = 0;
		ifstream tacticsFile("tactics.txt");
		try {
			for (int i = 0; i < 5; i++) {
				getline(tacticsFile, question);
				cout << endl << question << endl;
				do {
					cout << "Enter: ";
					if (!(cin >> answer)) {
						throw runtime_error("Error: Invalid input.");
					}
					cin.ignore();
					if (answer < 1 || answer > 5) {
						cout << "Invalid input. Please enter a value between 1 and 5." << endl;
					}
				} while (answer < 1 || answer > 5);
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
		catch (const exception& ex) {
			cerr << ex.what() << endl;
			return;
		}
		tacticsFile.close();
	}
// Method to assess identity of a person
	void computeIdentity() {
		string question;
		int answer = 0, assertiveCount = 0, turbulentCount = 0;
		ifstream identityFile("identity.txt");
		try {
			for (int i = 0; i < 5; i++) {
				getline(identityFile, question);
				cout << endl << question << endl;
				do {
					cout << "Enter: ";
					if (!(cin >> answer)) {
						throw runtime_error("Error: Invalid input.");
					}
					cin.ignore();
					if (answer < 1 || answer > 5) {
						cout << "Invalid input. Please enter a value between 1 and 5." << endl;
					}
				} while (answer < 1 || answer > 5);
				if (answer >= 1 && answer <= 3) {
					turbulentCount++;
				}
				else {
					assertiveCount++;
				}
			}
			if (turbulentCount > assertiveCount) {
				this->identity = 'T';
			}
			else {
				this->identity = 'A';
			}
		}
		catch (const exception& ex) {
			cerr << ex.what() << endl;
			return;
		}
		identityFile.close();
	}

	void setPersonality() {
		system("cls");
		cout << "\t\t\t\t\tUnlock the Secrets of Your Personality\n\t\t\t\t-------------------------------------------------------" << endl;
		computeMind(); system("cls");
		cout << "\t\t\t\t\tUnlock the Secrets of Your Personality\n\t\t\t\t-------------------------------------------------------" << endl;
		computeEnergy(); system("cls");
		cout << "\t\t\t\t\tUnlock the Secrets of Your Personality\n\t\t\t\t-------------------------------------------------------" << endl;
		computeNature(); system("cls");
		cout << "\t\t\t\t\tUnlock the Secrets of Your Personality\n\t\t\t\t-------------------------------------------------------" << endl;
		computeTactics(); system("cls");
		cout << "\t\t\t\t\tUnlock the Secrets of Your Personality\n\t\t\t\t-------------------------------------------------------" << endl;
		computeIdentity(); system("cls");
	}

	void setMind( char receiveMind) { this->mind = receiveMind; }
	void setEnergy( char receiveEnergy) { this->energy = receiveEnergy; }
	void setNature( char receiveNature) { this->nature = receiveNature; }
	void setTactics( char receiveTactics) { this->tactics = receiveTactics; }
	void setIdentity( char receiveIdentity) { this->identity = receiveIdentity; }

	char getMind() const { return this->mind; }
	char getEnergy() const { return this->energy; }
	char getNature() const { return this->nature; }
	char getTactics() const { return this->tactics; }
	char getIdentity() const { return this->identity; }

	void displayPersonality() const {
		if ((mind == '0') || (energy == '0') || (nature == '0') || (tactics == '0') || (identity == '0')) {
			cout << "Not Set" << endl;
			return;
		}
		else {
			cout << getMind() << getEnergy() << getNature() << getTactics() << "-" << getIdentity() << endl;
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
	friend class personalityQuiz;
	// Constructor Overloading
	person() {
		name = "";
		dayOfBirth = 0;
		monthOfBirth = 0;
		yearOfBirth = 0;
		age = 0;
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
	virtual ~person() {}
	virtual void displayDetails() const = 0;

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
	personalityQuiz personality;
public:
	friend class admin;
	friend int main();
	friend void writeToUserFile(user* User);
	friend class personalityQuiz;
	friend void populateArray(user* User);

	user() {
		zodiacSign = "";
		status = false;
	}

	user(const string receiveName, const int receiveDayOfBirth, const int receiveMonthOfBirth, const int receiveYearOfBirth, const string receiveUsername, const string receivePassword,
		const bool receiveStatus = false)
		: person(receiveName, receiveDayOfBirth, receiveMonthOfBirth, receiveYearOfBirth, receiveUsername, receivePassword)
	{
		calculateAge(receiveDayOfBirth, receiveMonthOfBirth, receiveYearOfBirth);
		calculateZodiacSign(receiveDayOfBirth, receiveMonthOfBirth);
		status = receiveStatus;
	}
	~user() {}

	void setStatus(const bool& receiveStatus) { status = receiveStatus; }
	inline bool getStatus() const { return status; }

	void takePersonalityTest() {
		this->personality.setPersonality();
	}
	void calculateAge(int, int, int);
	void calculateZodiacSign(int, int);
	bool createUser(string, string, string, int, int, int, bool);
// Used by User
	void displayDetails() const {
		cout << "Name: " << name << endl;
		cout << "Birth Day: " << dayOfBirth << "/" << monthOfBirth << "/" << yearOfBirth << endl;
		cout << "Age: " << age << endl;
		cout << "Zodiac Sign: " << zodiacSign << endl;
		cout << "Personality Type: ";  personality.displayPersonality(); cout << endl;
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
	cout << "Enter your Name: ";
	cin.ignore();
	getline(cin, userObject.name);
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
	// In case the user chooses to Login right after Signup, it would mean that populateArray is not called to calculate Age And Zodiac Sign. That is why calling those functions here
	userObject.status = false;
	userObject.calculateAge(userObject.dayOfBirth, userObject.monthOfBirth, userObject.yearOfBirth);
	userObject.calculateZodiacSign(userObject.dayOfBirth, userObject.monthOfBirth);
	// Function that appends attributes of the newly created user to the file
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
		fout << personality.getMind() << endl;
		fout << personality.getEnergy() << endl;
		fout << personality.getNature() << endl;
		fout << personality.getTactics() << endl;
		fout << personality.getIdentity() << endl;
		fout.close();
		return true;
	}
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
// Prototypes of functionalities that the admin has
	void deleteUser(user* User);
	void displayInactiveUsers(user* User);
	void changeStatusAll(user* User);
	void changeStatusSpecific(user* User);
	void editUser(user* User);
	void editOrDelete(user* User);
};


// Method to delete a particular user
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
	writeToUserFile(User);
	outfile.close();
}
// Method to edit user's details
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
		cout << "Current Information For user '" << User[indexToEdit].username << "':" << endl;
		cout << "1. Name: " << User[indexToEdit].name << endl;
		cout << "2. Password: " << User[indexToEdit].password << endl;
		cout << "3. Date of birth: " << User[indexToEdit].dayOfBirth << "/" << User[indexToEdit].monthOfBirth << "/" << User[indexToEdit].yearOfBirth << endl;

		int choice;
		do {
			cout << "Enter The Number Of The Attribute You Would Like To Edit [Or 0 to Cancel]: ";
			cin >> choice;
			cin.ignore();

			switch (choice) {
			case 0:
				return;
			case 1: {
				string name;
				cout << "Enter A New Name [Or Press Enter To Keep The Current Value]: ";
				getline(cin, name);
				if (!name.empty()) {
					User[indexToEdit].name = name;
					cout << "Name Updated Successfully!" << endl;
					writeToUserFile(User);
				}
				else {
					cout << "Name Not Updated." << endl;
				}
				break;
			}
			case 2: {
				string password;
				cout << "Enter a new password [Or Press Enter To Keep The Current Value]: ";
				getline(cin, password);
				if (!password.empty()) {
					User[indexToEdit].password = password;
					cout << "Password updated successfully!" << endl;
					writeToUserFile(User);
				}
				else {
					cout << "Password not updated." << endl;
				}
				break;
			}
			case 3: {
				int day, month, year;
				cout << "Enter a new date of birth (DD MM YYYY): ";
				cin >> day >> month >> year;
				cin.ignore();

				if (day <= 0 || day > 31) {
					cout << "Error: Invalid day entered." << endl;
					break;
				}
				if (month <= 0 || month > 12) {
					cout << "Error: Invalid month entered." << endl;
					break;
				}
				if (year <= 0) {
					cout << "Error: Invalid year entered." << endl;
					break;
				}
				User[indexToEdit].dayOfBirth = day;
				User[indexToEdit].monthOfBirth = month;
				User[indexToEdit].yearOfBirth = year;
				cout << "Date of birth updated successfully!" << endl;
				writeToUserFile(User);
				break;
			}
			default:
				cout << "Error: Invalid choice entered. Please try again." << endl;
			}
		} while (choice != 0);
	}
	catch (const char* errorMessage) {
		cout << "Error: " << errorMessage << endl;
	}
}
// Method to display details of all inactive users
void admin::displayInactiveUsers(user* User) {
	for (int i = 0; i < userCount; i++) {
		if (!User[i].status) {
			cout << User[i] << endl;
		}
	}
}
// Method to collectively change status of users to either false or true
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
		writeToUserFile(User);
		outfile.close();
	}
	catch (const char* msg) {
		cerr << "Error: " << msg << endl;
	}
}
// Method to change status of a specific user
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
		writeToUserFile(User);
		outfile.close();
	}
	catch (const char* msg) {
		cerr << "Error: " << msg << endl;
	}
}

// Method that allows user to either edit or delete a user object
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