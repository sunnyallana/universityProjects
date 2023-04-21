#pragma once
int main(void);
void adminMenu(admin& adminObject, user* userObject);


inline void readUserCountFromFile() {
	ifstream file("usercount.txt");
	if (file.is_open()) {
		file >> userCount;
		file.close();
	}
}

inline void writeUserCountToFile() {
	ofstream file("usercount.txt");
	if (file.is_open()) {
		file << userCount;
		file.close();
	}
}

void login(admin& Admin, user* User) {
	string tempUsername, tempPassword;
	cout << "Enter Username: "; cin >> tempUsername;
	cout << "Enter Password: ";
	char ch = _getch();
	while (ch != '\r') {
		if (ch != '\b') { tempPassword.push_back(ch); cout << "*"; }
		else if (!tempPassword.empty()) { tempPassword.pop_back(); cout << "\b \b"; }
		ch = _getch();
	}
	cout << endl;
	if (Admin.getUsername() == tempUsername && Admin.getPassword() == tempPassword) {
		cout << "Admin Session" << endl;
		adminMenu(Admin, User);
	}

	else {
		bool found = false;
		for (int i = 0; i < userCount; i++) {
			if (User[i].verifyUser(tempUsername, tempPassword) == 1) {
				if (!User[i].getStatus()) {
					cout << "Your account is inactive. Please contact the admin to reactivate your account." << endl;
					found = true;
					break;
				}
				cout << "User Session" << endl;
				User[i].displayDetails(); // Just to test execution
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Login Failed" << endl;
		}
	}
	returnToLoginPage();
}


void signUp(user* User) {
	string newUsername;
	bool isUsernameTaken = true;

	// Get username from user and check if it already exists
	while (isUsernameTaken) {
		cout << "Enter Username: ";
		cin >> newUsername;

		// Check if username already exists
		isUsernameTaken = false;
		for (int i = 0; i < userCount; i++) {
			if (User[i].getUsername() == newUsername) {
				isUsernameTaken = true;
				cout << "Username is already taken. Please enter a different username." << endl;
				break;
			}
		}
	}

	// Register user
	if (userCount < 100) {
		User[userCount].setUsername(newUsername); // Set the username
		cin >> User[userCount]; // Get other user details
		userCount++;
		writeUserCountToFile();
		cout << "Registration successful." << endl;
	}
	else {
		cout << "User limit reached." << endl;
	}
	returnToLoginPage();
}



void returnToLoginPage() {
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
		main();
	}
	else if (returnChoice == "no") {
		cout << "\nStaying on the Same Page" << endl;
	}
	else {
		cout << "\nInvalid Choice" << endl;
	}
}

void populateArray(user* User) {
	ifstream infile("users.txt");
	if (!infile.is_open()) {
		cout << "Error: Failed to open input file." << endl;
		return;
	}
	for (int i = 0; i < userCount; i++) {
		getline(infile, User[i].username);
		getline(infile, User[i].password);
		getline(infile, User[i].name);
		infile >> User[i].dayOfBirth;
		infile >> User[i].monthOfBirth;
		infile >> User[i].yearOfBirth;
		infile >> User[i].status;
		infile.ignore();
		User[i] = user(User[i].name, User[i].dayOfBirth, User[i].monthOfBirth, User[i].yearOfBirth, User[i].username, User[i].password, User[i].status);
	}
	infile.close();
}



void adminMenu(admin& adminObject, user* userObject) {
	int adminMenuChoice = 0;
	while (adminMenuChoice != 7) {
		try {
			cout << "______________________________________________ADMIN SESSION_____________________________________" << endl;
			cout << endl << "Welcome " << adminObject.getName() << endl;
			cout << "What operation would you like to perform ? " << endl;
			cout << "1) Display Count Of Users\n2) Display All Users\n3) Display Only Inactive Users\n4) Change Status Of A Specific Account\n5) Change Status Of All Accounts\n6) Edit Or Delete User's Information\n7) Logout\n\n Enter Choice: ";
			cin >> adminMenuChoice;

			if (cin.fail()) {
				cin.clear();
				while (cin.get() != '\n') {
					continue;
				}
				throw runtime_error("Invalid input. Please enter a number between 1 and 7.");
			}

			if (adminMenuChoice < 1 || adminMenuChoice > 7) {
				throw out_of_range("Invalid choice. Please enter a number between 1 and 7.");
			}

			switch (adminMenuChoice) {
				case 1: {
					cout << "Number of users: " << userCount << endl;
					break;
				}
				case 2: {
					adminObject.displayDetails(userObject);
					break;
				}
				case 3: {
					adminObject.displayInactiveUsers(userObject);
					break;
				}
				case 4: {
					adminObject.changeStatusSpecific(userObject);
					break;
				}
				case 5: {
					adminObject.changeStatusAll(userObject);
					break;
				}
				case 6: {
					adminObject.editOrDelete(userObject);
					break;
				}
				case 7: {
					returnToLoginPage();
					break;
				}
				default: {
					throw runtime_error("Invalid choice. Please enter a number between 1 and 7.");
				}
			}
		}
		catch (const runtime_error& e) {
			cerr << e.what() << endl;
		}
		catch (const out_of_range& e) {
			cerr << e.what() << endl;
		}
		catch (const exception& e) {
			cerr << "Error: " << e.what() << endl;
			cin.clear();
			while (cin.get() != '\n') {
				continue;
			}
		}
		catch (...) {
			cerr << "An unknown error occurred." << endl;
			cin.clear();
			while (cin.get() != '\n') {
				continue;
			}
		}
	}
}

bool isValidDate(int day, int month, int year) {
	if (day < 1 || day > 31) {
		return false;
	}
	if (month < 1 || month > 12) {
		return false;
	}
	if (year < 1900 || year > 2100) {
		return false;
	}
	int daysInMonth;
	if (month == 2) {
		// Check for leap year
		daysInMonth = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) ? 29 : 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		daysInMonth = 30;
	}
	else {
		daysInMonth = 31;
	}
	return day <= daysInMonth;
}
