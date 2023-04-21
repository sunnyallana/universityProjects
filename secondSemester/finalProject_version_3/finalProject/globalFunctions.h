#pragma once
int main(void);
void adminMenu(admin& adminObject, user* userObject);
void clearScreenInFiveSeconds();

// Function to initialize count of user when the program is executed
inline void readUserCountFromFile() {
	ifstream file("usercount.txt");
	if (file.is_open()) {
		file >> userCount;
		file.close();
	}
}
// Program to increament/decreament number of users in the file
inline void writeUserCountToFile() {
	ofstream file("usercount.txt");
	if (file.is_open()) {
		file << userCount;
		file.close();
	}
}
// Function that controls the login process
void login(admin& Admin, user* User) {
	system("cls");
	cout << "______________________________________________LOGIN_______________________________________\n" << endl;
	string tempUsername, tempPassword;
	cout << "Enter Username: "; cin >> tempUsername;
	cout << "Enter Password: ";
// To hide the password using astericks
	char ch = _getch();
	while (ch != '\r') {
// Push back method pushes the character "ch" at the end of the string "tempPassword"
		if (ch != '\b') { tempPassword.push_back(ch); cout << "*"; }
		else if (!tempPassword.empty()) { tempPassword.pop_back(); cout << "\b \b"; }
		ch = _getch();
	}
	cout << endl;
	if (Admin.getUsername() == tempUsername && Admin.getPassword() == tempPassword) {
		system("cls");
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
// Functions that controls the sign up process. Exceptions handled. Check Overloaded Operator ">>'s" definition in coreClasses.h for more reference
void signUp(user* User) {
	system("cls");
	cout << "______________________________________________SIGN UP_______________________________________\n" << endl;
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

// Function that calls main recursively
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
// Function that reads all user's/users' data from the file and initialize the user array on execution
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
// Function that controls flow of admin operations
void adminMenu(admin& adminObject, user* userObject) {
	int adminMenuChoice = 0;
	while (adminMenuChoice != 7) {
		menuAdmin:
		try {
			cout << "______________________________________________ADMIN SESSION_____________________________________" << endl;
			cout << endl << "Welcome " << adminObject.getName() << endl;
			cout << "What operation would you like to perform ? " << endl;
			cout << "1) Display Count Of Users\n2) Display All Users\n3) Display Only Inactive Users\n4) Change Status Of A Specific Account\n5) Change Status Of All Accounts\n6) Edit Or Delete User's Information\n7) Logout\n\nEnter Choice: ";
			cin >> adminMenuChoice;
			// Exception handling for when user enters anything other than an integer as an input for adminMenuChoice
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
					clearScreenInFiveSeconds();
					break;
				}
				case 2: {
					adminObject.displayDetails(userObject);
					clearScreenInFiveSeconds();
					break;
				}
				case 3: {
					adminObject.displayInactiveUsers(userObject);
					clearScreenInFiveSeconds();
					break;
				}
				case 4: {
					adminObject.changeStatusSpecific(userObject);
					clearScreenInFiveSeconds();
					break;
				}
				case 5: {
					adminObject.changeStatusAll(userObject);
					clearScreenInFiveSeconds();
					break;
				}
				case 6: {
					adminObject.editOrDelete(userObject);
					clearScreenInFiveSeconds();
					break;
				}
				case 7: {
					returnToLoginPage();
					clearScreenInFiveSeconds();
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
// Function that checks if the user has entered valid date in signup process
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

// A function to clean the screen and make execution neat
void clearScreenInFiveSeconds() {
	for (int i = 5; i > 0; i--) {
		cout << "Clearning Screen In " << i << " Seconds" << endl;
 		Sleep(1000);
	}
	system("cls");
}
