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

// Finctional Character Class
class fictionalCharacter {
private:
	int strength;
	int agility;
	int intelligence;
	int fortitude;
	int charisma;
	string type;
public:
	friend class personalityQuiz;
	fictionalCharacter() {
		strength = 0;
		agility = 0;
		intelligence = 0;
		fortitude = 0;
		charisma = 0;
		type = "Not Set";
	}

	fictionalCharacter(const int receiveStrength, const  int receiveAgility, const int receiveIntelligence, const int receiveFortitude, const int receiveCharisma, const string receiveType) {
		strength = receiveStrength;
		agility = receiveAgility;
		intelligence = receiveIntelligence;
		fortitude = receiveFortitude;
		charisma = receiveCharisma;
		type = receiveType;
	}

	int getStrength() const { return strength; }
	int getAgility() const { return agility; }
	int getIntelligence() const { return intelligence; }
	int getFortitude() const { return fortitude; }
	int getCharisma() const { return charisma; }
	string getType() const { return type; }

	void setStrength(const int receiveStrength) { strength = receiveStrength; }
	void setAgility(const int receiveAgility) { agility = receiveAgility; }
	void setIntelligence(const int receiveIntelligence) { intelligence = receiveIntelligence; }
	void setFortitude(const int receiveFortitude) { fortitude = receiveFortitude; }
	void setCharisma(const int receiveCharisma) { charisma = receiveCharisma; }
	void setType(const string receiveType) { type = receiveType; }

	void calculateCharacter() {
		if ((strength > agility) && (strength > intelligence) && (strength > fortitude)) {
			if (intelligence < agility && intelligence < fortitude) {type = "Barbarian";}
			else if (agility > intelligence && agility > fortitude) {type = "Swordsman";}
			else if (fortitude > agility && fortitude > intelligence) {type = "Wrestler";}
			else if (charisma > 10) {type = "Knight";}
			else {type = "Raider";}
		}
		else if (agility > strength && agility > intelligence && agility > fortitude){
			if (intelligence > strength && intelligence > fortitude) {type = "Speedster";}
			else if (strength > intelligence && strength > fortitude) {type = "Street Fighter";}
			else if (fortitude > strength && fortitude > intelligence) {type = "Horseman";}
			else if (charisma > 10) {type = "Bandit";}
			else {type = "Goblin";}
		}
		else if (intelligence > strength && intelligence > agility && intelligence > fortitude) {
			if (fortitude > strength && fortitude > agility){type = "Builder";}
			else if (strength > fortitude && strength > agility){type = "Robo Fighter";}
			else if (agility > strength && agility > fortitude){type = "Android";}
			else if (charisma > 10){type = "Alchemist";}
			else{type = "Witch";}
		}
		else{
			if (strength > intelligence && strength > agility){type = "Giant";}
			else if (intelligence > strength && intelligence > agility){type = "Cyborg";}
			else if (intelligence < strength && intelligence < agility){type = "Golem";}
			else if (charisma > 10){type = "Vampire";}
			else{type = "Mutant";}
		}
	}
	void displayCharacter() const {
		cout << "\nStrength: " << strength << endl;
		cout << "Agility: " << agility << endl;
		cout << "Intelligence: " << intelligence << endl;
		cout << "Fortitude: " << fortitude << endl;
		cout << "Charisma: " << charisma << endl;
	}
};

// Class to assess user's mind, energy, nature, tactics, and identity
class personalityQuiz {
public:
	char mind; // Introvet/Extravert
	char energy;// Intuitive/Sensing
	char nature; // Thinking/Feeling
	char tactics; // Prospecting/Judging
	char identity; // Turbulent/Assertive

	fictionalCharacter character;

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
		ifstream mindFile("personality/personalityQuestions/mind.txt");

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
						cout << "Invalid input. Please enter a number between 1 and 5." << endl;
						cin.clear();
						cin.ignore();
						continue;
					}
					cin.ignore();
					if (answer < 1 || answer > 5) {
						cout << "Invalid input. Please enter a number between 1 and 5." << endl;
					}
				} while (answer < 1 || answer > 5);
				if (answer >= 1 && answer <= 3) {
					introvertCount++;
				}
				else {
					extravertCount++;
				}

				if (answer == 1) {
					character.intelligence = character.intelligence - 1;
					character.charisma = character.charisma - 2;
				}
				else if (answer == 2)
				{
					character.charisma = character.charisma - 1;
				}
				else if (answer == 3)
				{
					character.intelligence = character.intelligence + 1;
				}
				else if (answer == 4)
				{
					character.intelligence = character.intelligence + 2;
					character.charisma = character.charisma + 1;
				}
				else if (answer == 5)
				{
					character.intelligence = character.intelligence + 3;
					character.charisma = character.charisma + 2;
					character.fortitude = character.fortitude + 1;
				}
			}

			if (introvertCount > extravertCount) {
				this->mind = 'I';
				character.intelligence = character.intelligence + 5;
				character.charisma = character.charisma - 3;
			}
			else {
				this->mind = 'E';
				character.fortitude = character.fortitude + 5;
				character.charisma = character.charisma + 3;
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
		ifstream energyFile("personality/personalityQuestions/energy.txt");
		try {
			for (int i = 0; i < 5; i++) {
				getline(energyFile, question);
				cout << endl << question << endl;
				do {
					cout << "Enter: ";
					if (!(cin >> answer)) {
						cout << "Invalid input. Please enter a number between 1 and 5." << endl;
						cin.clear();
						cin.ignore();
						continue;
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

				if (answer == 1) {
					character.intelligence = character.intelligence - 2;
					character.fortitude = character.fortitude - 1;
					character.charisma = character.charisma - 2;
				}
				else if (answer == 2)
				{
					character.intelligence = character.intelligence - 1;
				}
				else if (answer == 3)
				{
					character.intelligence = character.intelligence + 1;
				}
				else if (answer == 4)
				{
					character.intelligence = character.intelligence + 2;
					character.fortitude = character.fortitude + 1;
				}
				else if (answer == 5)
				{
					character.intelligence = character.intelligence + 3;
					character.charisma = character.charisma + 1;
					character.fortitude = character.fortitude + 2;
				}
			}

			if (observantCount > intuitiveCount) {
				this->energy = 'S';
				character.intelligence = character.intelligence + 5;
			}
			else {
				this->energy = 'N';
				character.fortitude = character.fortitude + 3;
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
		ifstream natureFile("personality/personalityQuestions/nature.txt");
		try {
			for (int i = 0; i < 5; i++) {
				getline(natureFile, question);
				cout << endl << question << endl;
				do {
					cout << "Enter: ";
					if (!(cin >> answer)) {
						cout << "Invalid input. Please enter a number between 1 and 5." << endl;
						cin.clear();
						cin.ignore();
						continue;
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

				if (answer == 1) {
					character.intelligence = character.intelligence - 2;
					character.strength = character.strength + 3;
				}
				else if (answer == 2)
				{
					character.strength = character.strength + 2;
					character.intelligence = character.intelligence - 1;
				}
				else if (answer == 3)
				{
					character.strength = character.strength + 1;
					character.fortitude = character.fortitude + 1;
				}
				else if (answer == 4)
				{
					character.intelligence = character.intelligence + 1;
					character.fortitude = character.fortitude + 1;
				}
				else if (answer == 5)
				{
					character.strength = character.strength - 1;
					character.intelligence = character.intelligence + 2;
					character.fortitude = character.fortitude + 2;
				}
			}

			if (thinkingCount > feelingCount) {
				this->nature = 'T';
				character.strength = character.strength - 3;
				character.intelligence = character.intelligence + 3;
				character.fortitude = character.fortitude + 2;
			}
			else {
				this->nature = 'F';
				character.strength = character.strength + 5;
				character.intelligence = character.intelligence - 3;
				character.fortitude = character.fortitude + 1;
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
		ifstream tacticsFile("personality/personalityQuestions/tactics.txt");
		try {
			for (int i = 0; i < 5; i++) {
				getline(tacticsFile, question);
				cout << endl << question << endl;
				do {
					cout << "Enter: ";
					if (!(cin >> answer)) {
						cout << "Invalid input. Please enter a number between 1 and 5." << endl;
						cin.clear();
						cin.ignore();
						continue;
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

				if (answer == 1) {
					character.agility = character.agility - 2;
					character.strength = character.strength - 2;
					character.fortitude = character.fortitude + 2;
				}
				else if (answer == 2)
				{
					character.strength = character.strength - 1;
					character.agility = character.agility - 1;
					character.fortitude = character.fortitude + 1;
				}
				else if (answer == 3)
				{
					character.strength = character.strength + 1;
					character.agility = character.agility + 1;
					character.fortitude = character.fortitude + 1;
				}
				else if (answer == 4)
				{
					character.strength = character.strength + 2;
					character.agility = character.agility + 2;
					character.fortitude = character.fortitude + 1;
				}
				else if (answer == 5)
				{
					character.strength = character.strength + 3;
					character.agility = character.agility + 3;
					character.fortitude = character.fortitude + 2;
				}
			}

			if (prospectingCount > judgingCount) {
				this->tactics = 'P';
				character.strength = character.strength + 5;
				character.agility = character.agility + 5;
				character.fortitude = character.fortitude - 3;
			}
			else {
				this->tactics = 'J';
				character.strength = character.strength - 5;
				character.agility = character.agility - 5;
				character.fortitude = character.fortitude + 3;
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
		ifstream identityFile("personality/personalityQuestions/identity.txt");
		try {
			for (int i = 0; i < 5; i++) {
				getline(identityFile, question);
				cout << endl << question << endl;
				do {
					cout << "Enter: ";
					if (!(cin >> answer)) {
						cout << "Invalid input. Please enter a number between 1 and 5." << endl;
						cin.clear();
						cin.ignore();
						continue;
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

				if (answer == 1) {
					character.strength = character.strength - 2;
					character.agility = character.agility - 2;
					character.intelligence = character.intelligence + 2;
					character.fortitude = character.fortitude + 2;
					character.charisma = character.charisma - 2;

				}
				else if (answer == 2)
				{
					character.strength = character.strength - 1;
					character.agility = character.agility - 1;
					character.intelligence = character.intelligence + 1;
					character.fortitude = character.fortitude + 1;
					character.charisma = character.charisma - 1;
				}
				else if (answer == 3)
				{
					character.strength = character.strength + 1;
					character.agility = character.agility + 1;
					character.charisma = character.charisma + 1;
				}
				else if (answer == 4)
				{
					character.strength = character.strength + 2;
					character.agility = character.agility + 2;
					character.intelligence = character.intelligence - 1;
					character.fortitude = character.fortitude - 1;
					character.charisma = character.charisma + 2;
				}
				else if (answer == 5)
				{
					character.strength = character.strength + 3;
					character.agility = character.agility + 3;
					character.intelligence = character.intelligence - 2;
					character.fortitude = character.fortitude - 2;
					character.charisma = character.charisma + 3;
				}
			}

			if (turbulentCount > assertiveCount) {
				this->identity = 'T';
				character.strength = character.strength - 5;
				character.agility = character.agility - 3;
				character.intelligence = character.intelligence + 5;
				character.fortitude = character.fortitude + 2;
				character.charisma = character.charisma - 2;
			}
			else {
				this->identity = 'A';
				character.strength = character.strength + 5;
				character.agility = character.agility + 3;
				character.intelligence = character.intelligence - 5;
				character.fortitude = character.fortitude - 2;
				character.charisma = character.charisma + 2;
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
		character.calculateCharacter();
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
			cout << getMind() << getEnergy() << getNature() << getTactics() << "-" << getIdentity();
		}
	}
	void displayCharacterType() const {
		cout << character.type;
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
	// Setter functions to set values of either of person/user/admin outside of their class
	void setName(const string& receiveName) { name = receiveName; }
	void setDayOfBirth(const int& receiveDayOfBirth) { dayOfBirth = receiveDayOfBirth; }
	void setMonthOfBirth(const int& receiveMonthOfBirth) { monthOfBirth = receiveMonthOfBirth; }
	void setYearOfBirth(const int& receiveYearOfBirth) { yearOfBirth = receiveYearOfBirth; }
	void setUsername(const string& receiveUserName) { username = receiveUserName; }
	void setPassword(const string& receivePassword) { password = receivePassword; }
	// Getter functions to access values of either of person/user/admin outside of their class
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
// Used in populateArray to initialize and calculate values of attributes of existing users at the start of the program
	user(const string receiveName, const int receiveDayOfBirth, const int receiveMonthOfBirth, const int receiveYearOfBirth, const string receiveUsername, const string receivePassword,const bool receiveStatus)
		: person(receiveName, receiveDayOfBirth, receiveMonthOfBirth, receiveYearOfBirth, receiveUsername, receivePassword)
	{
		calculateAge(receiveDayOfBirth, receiveMonthOfBirth, receiveYearOfBirth);
		calculateZodiacSign(receiveDayOfBirth, receiveMonthOfBirth);
		status = receiveStatus;
	}
	~user() {}

	void setStatus(const bool& receiveStatus) { status = receiveStatus; }
	bool getStatus() const { return status; }

	void takePersonalityTest() {
		this->personality.setPersonality();
	}
	void calculateAge(int, int, int);
	void calculateZodiacSign(int, int);
	bool createUser(string, string, string, int, int, int, bool);
// To display user's details to the user
	void displayDetails() const {
		system("cls");
		cout << "                          ___________________________________________________________________" << endl;
		cout << "                         |                                                                   |" << endl;
		cout << "                         |                            USER SESSION                           |" << endl;
		cout << "                         |___________________________________________________________________|" << endl;
		cout << endl;
		cout << "\t\t\t\t     ==============================================" << endl;
		cout << "\t\t\t\t                      USER PROFILE" << endl;
		cout << "\t\t\t\t     ==============================================" << endl;
		cout << "\t\t\t\t      Name: " << name << endl;
		cout << "\t\t\t\t      Username: " << username << endl;
		cout << "\t\t\t\t      Password: " << password << endl;
		cout << "\t\t\t\t     ----------------------------------------------" << endl;
		cout << "\t\t\t\t      | Date of Birth: " << dayOfBirth << "/" << monthOfBirth << "/" << yearOfBirth << endl;
		cout << "\t\t\t\t      | Age: " << age << endl;
		cout << "\t\t\t\t      | Zodiac Sign: " << zodiacSign << endl;
		cout << "\t\t\t\t      | Personality Type: "; personality.displayPersonality() ; cout << endl;
		cout << "\t\t\t\t      | Character Type: "; personality.displayCharacterType(); cout << endl;
		cout << "\t\t\t\t     ----------------------------------------------" << endl;
		cout << "\t\t\t\t      Status: " << (status ? "Active" : "Inactive") << endl;
		cout << "\t\t\t\t     ==============================================" << endl;
	}
	friend ostream& operator <<(ostream& ostreamObject, const user& userObject);
	friend istream& operator >>(istream& istreamObject, user& userObject);

	void displayZodiacDetails() const;
	void displayPersonalityDetails() const;

};

 // To display user's details to the admin
ostream& operator <<(ostream& ostreamObject, const user& userObject) {
	ostreamObject << endl;
	ostreamObject << "\t\t\t\t     ==============================================" << endl;
	ostreamObject << "\t\t\t\t                      USER PROFILE" << endl;
	ostreamObject << "\t\t\t\t     ==============================================" << endl;
	ostreamObject << "\t\t\t\t      Name: " << userObject.name << endl;
	ostreamObject << "\t\t\t\t      Username: " << userObject.username << endl;
	ostreamObject << "\t\t\t\t      Password: " << userObject.password << endl;
	ostreamObject << "\t\t\t\t     ----------------------------------------------" << endl;
	ostreamObject << "\t\t\t\t      | Date of Birth: " << userObject.dayOfBirth << "/" << userObject.monthOfBirth << "/" << userObject.yearOfBirth << endl;
	ostreamObject << "\t\t\t\t      | Age: " << userObject.age << endl;
	ostreamObject << "\t\t\t\t      | Zodiac Sign: " << userObject.zodiacSign << endl;
	ostreamObject << "\t\t\t\t      | Personality Type: "; userObject.personality.displayPersonality(); ostreamObject << endl;
	ostreamObject << "\t\t\t\t      | Character Type: "; userObject.personality.displayCharacterType(); ostreamObject << endl;
	ostreamObject << "\t\t\t\t     ----------------------------------------------" << endl;
	ostreamObject << "\t\t\t\t      Status: " << (userObject.status ? "Active" : "Inactive") << endl;
	ostreamObject << "\t\t\t\t     ==============================================" << endl;
	return ostreamObject;
}
// To take user's details as an input
istream& operator >>(istream& istreamObject, user& userObject) {
	cout << "                     Enter Password [at least 4 characters, must contain at least one uppercase letter, one lowercase letter, one digit, and one special character]: ";
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
// Password validation check
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
	// To make sure that the entered password passes all validation checks. If invalid input is entered, input would be taken again recursively
	if (!hasUppercase || !hasLowercase || !hasDigit || !hasSpecial) {
		cout << "Password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character. Please try again." << endl;
		userObject.password.clear();
		istreamObject >> userObject;
		return istreamObject;
	}
	cout << "                     Enter your Name: ";
	cin.ignore();
	getline(cin, userObject.name);
	// A try block to make sure that user enters correct date of birth
	try {
		cout << "                     Enter your Birthday [dd mm yyyy]: ";
		istreamObject >> userObject.dayOfBirth >> userObject.monthOfBirth >> userObject.yearOfBirth;
		cin.ignore();
		if (!isValidDate(userObject.dayOfBirth, userObject.monthOfBirth, userObject.yearOfBirth)) {
			throw invalid_argument("Invalid date");
		}
	}
	// If invalid date is entered, its value would be set to zero, password would be clearned, and ">>" operator would be called recursively
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
// Method to calculate zodiac sign of the calling user
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
void user::displayZodiacDetails() const {
	system("cls");
	string fileName = "zodiacDetails/";
	fileName += (zodiacSign == "Aries") ? "aries.txt" :
		(zodiacSign == "Taurus") ? "taurus.txt" :
		(zodiacSign == "Gemini") ? "gemini.txt" :
		(zodiacSign == "Cancer") ? "cancer.txt" :
		(zodiacSign == "Leo") ? "leo.txt" :
		(zodiacSign == "Virgo") ? "virgo.txt" :
		(zodiacSign == "Libra") ? "libra.txt" :
		(zodiacSign == "Scorpio") ? "scorpio.txt" :
		(zodiacSign == "Sagittarius") ? "sagittarius.txt" :
		(zodiacSign == "Capricorn") ? "capricorn.txt" :
		(zodiacSign == "Aquarius") ? "aquarius.txt" :
		(zodiacSign == "Pisces") ? "pisces.txt" : "";
	if (fileName.empty()) {
		cout << "Invalid zodiac sign." << endl;
		return;
	}
	ifstream file(fileName);
	if (!file) {
		cout << "Error opening file." << endl;
		return;
	}
	string lineOne, lineTwo, lineThree, lineFour;
	cout << "                          ___________________________________________________________________" << endl;
	cout << "                         |                                                                   |" << endl;
	cout << "                         |          INTERESTING INFORMATION ABOUT YOUR ZODIAC SIGN           |" << endl;
	cout << "                         |___________________________________________________________________|\n\n" << endl;
	getline(file, lineOne);
	getline(file, lineTwo);
	getline(file, lineThree);
	getline(file, lineFour);
	cout << "\n            _______________________________________________________________________________________________" << endl;
	cout << endl;
	cout << "             " << lineOne << endl;
	cout << "             " << lineTwo << endl;
	cout << "             " << lineThree << endl;
	cout << "             " << lineFour << endl;
	cout << "            _______________________________________________________________________________________________" << endl;
	file.close();
}

void user::displayPersonalityDetails() const {
	if ((personality.mind == '0') || (personality.energy == '0') || (personality.nature == '0') || (personality.tactics == '0') || (personality.identity == '0')) {
		cout << "Not Set" << endl;
		return;
	}
	else {
		system("cls");
		string lineOne, lineTwo, lineThree, lineFour, lineFive;

		if (personality.mind == 'I') {
			ifstream introvertFile("personality/personalityDetails/introvert.txt");
			if (introvertFile.is_open()) {
				getline(introvertFile, lineOne);
				introvertFile.close();
			}
		}
		else if (personality.mind == 'E') {
			ifstream extravertFile("personality/personalityDetails/extravert.txt");
			if (extravertFile.is_open()) {
				getline(extravertFile, lineOne);
				extravertFile.close();
			}
		}

		if (personality.energy == 'N') {
			ifstream intuitionFile("personality/personalityDetails/intuition.txt");
			if (intuitionFile.is_open()) {
				getline(intuitionFile, lineTwo);
				intuitionFile.close();
			}
		}
		else if (personality.energy == 'S') {
			ifstream observantFile("personality/personalityDetails/observant.txt");
			if (observantFile.is_open()) {
				getline(observantFile, lineTwo);
				observantFile.close();
			}
		}

		if (personality.nature == 'F') {
			ifstream feelingFile("personality/personalityDetails/feeling.txt");
			if (feelingFile.is_open()) {
				getline(feelingFile, lineThree);
				feelingFile.close();
			}
		}
		else if (personality.nature == 'T') {
			ifstream thinkingFile("personality/personalityDetails/thinking.txt");
			if (thinkingFile.is_open()) {
				getline(thinkingFile, lineThree);
				thinkingFile.close();
			}
		}

		if (personality.tactics == 'J') {
			ifstream judgingFile("personality/personalityDetails/judging.txt");
			if (judgingFile.is_open()) {
				getline(judgingFile, lineFour);
				judgingFile.close();
			}
		}
		else if (personality.tactics == 'P') {
			ifstream prospectingFile("personality/personalityDetails/prospecting.txt");
			if (prospectingFile.is_open()) {
				getline(prospectingFile, lineFour);
				prospectingFile.close();
			}
		}

		if (personality.identity == 'A') {
			ifstream assertiveFile("personality/personalityDetails/assertive.txt");
			if (assertiveFile.is_open()) {
				getline(assertiveFile, lineFive);
				assertiveFile.close();
			}
		}
		else if (personality.identity == 'T') {
			ifstream turbulentFile("personality/personalityDetails/turbulent.txt");
			if (turbulentFile.is_open()) {
				getline(turbulentFile, lineFive);
				turbulentFile.close();
			}
		}

		// Display the lines read from the file
		cout << "                          ___________________________________________________________________" << endl;
		cout << "                         |                                                                   |" << endl;
		cout << "                         |                  INFORMATION ABOUT YOUR PERSONALITY               |" << endl;
		cout << "                         |___________________________________________________________________|\n\n\n" << endl;
		cout << "     __________________________________________________________________________________________________________________" << endl;
		cout << endl;
		cout << "      Mind: " << lineOne << endl;
		cout << "      Nature: " << lineTwo << endl;
		cout << "      Energy: " << lineThree << endl;
		cout << "      Tactics: " << lineFour << endl;
		cout << "      Identity: " << lineFive << endl;
		cout << "     __________________________________________________________________________________________________________________" << endl;
	}
}


// Method that appends user's details to the file
bool user::createUser(string receiveUsername = "Not Saved: Error", string receivePassword = "Not Saved: Error", string receiveName = "Not Saved: Error", int receiveDayOfBirth = 0, int receiveMonthOfBirth = 0, int receiveYearOfBirth = 0, bool receiveStatus = false) {
	ofstream fout("usersData/users.txt", ios_base::app);
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
		fout << personality.character.getStrength() << endl;
		fout << personality.character.getAgility() << endl;
		fout << personality.character.getIntelligence() << endl;
		fout << personality.character.getFortitude() << endl;
		fout << personality.character.getCharisma() << endl;
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
	cout << "                          ___________________________________________________________________" << endl;
	cout << "                         |                                                                   |" << endl;
	cout << "                         |          ENTER THE NEW STATUS [ACTIVE(1) |  INACTIVE(0)]          |" << endl;
	cout << "                         |___________________________________________________________________|\n\n" << endl;
	cout << "ENTER: ";
	cin >> newStatus;

	try {
		if (cin.fail()) {
			throw "Invalid input. Please enter a boolean value (1 or 0).";
		}

		for (int i = 0; i < userCount; i++) {
			User[i].status = newStatus;
		}

		ofstream outfile("usersData/users.txt");
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
	cout << "Enter Username of the concerned User: ";
	cin >> usernameToChange;

	bool newStatus;
	cout << "                          ___________________________________________________________________" << endl;
	cout << "                         |                                                                   |" << endl;
	cout << "                         |          ENTER THE NEW STATUS [ACTIVE(1) |  INACTIVE(0)]          |" << endl;
	cout << "                         |___________________________________________________________________|\n\n" << endl;
	cout << "ENTER: ";
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
		ofstream outfile("usersData/users.txt");
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