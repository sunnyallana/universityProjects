#pragma once
// Function to initialize count of user when the program is executed
void readUserCountFromFile() {
	ifstream file("usercount.txt");
	if (file.is_open()) {
		file >> userCount;
		file.close();
	}
}
// Program to increament/decreament number of users in the file
void writeUserCountToFile() {
	ofstream file("usercount.txt");
	if (file.is_open()) {
		file << userCount;
		file.close();
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
void clearScreen() {
	cout << "Press Any Key To Clear Screen" << endl;
	char c = _getche();
	system("cls");
}
// A function to write to user file once a change is made
void writeToUserFile(user* User) {
	try {
		ofstream outfile("users.txt");
		if (!outfile.is_open()) {
			throw runtime_error("Error: Failed to open output file.");
		}
		for (int i = 0; i < userCount; i++) {
			outfile << User[i].username << endl;
			outfile << User[i].password << endl;
			outfile << User[i].name << endl;
			outfile << User[i].dayOfBirth << endl;
			outfile << User[i].monthOfBirth << endl;
			outfile << User[i].yearOfBirth << endl;
			outfile << User[i].status << endl;
			outfile << User[i].personality.getMind() << endl;
			outfile << User[i].personality.getEnergy() << endl;
			outfile << User[i].personality.getNature() << endl;
			outfile << User[i].personality.getTactics() << endl;
			outfile << User[i].personality.getIdentity() << endl;
		}
		outfile.close();
		writeUserCountToFile();
	}
	catch (const exception& ex) {
		cerr << ex.what() << endl;
	}
}
// Function that controls the flow of admin's operations
void adminMenu(admin& adminObject, user* userObject) {
	int adminMenuChoice = 0;
	while (adminMenuChoice != 7) {
		try {
			cout << "______________________________________________ADMIN SESSION_____________________________________" << endl;
			cout << endl << "Welcome " << adminObject.getName() << endl;
			cout << "What operation would you like to perform ? " << endl;
			cout << "1) Display Count Of Users\n2) Display All Users\n3) Display Only Inactive Users\n4) Change Status Of A Specific Account\n5) Change Status Of All Accounts\n6) Edit Or Delete User's Information\n7) Logout\n\nEnter Choice: ";
			cin >> adminMenuChoice;
			cin.ignore();
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
				clearScreen();
				break;
			}
			case 2: {
				adminObject.displayDetails(userObject);
				clearScreen();
				break;
			}
			case 3: {
				adminObject.displayInactiveUsers(userObject);
				clearScreen();
				break;
			}
			case 4: {
				adminObject.changeStatusSpecific(userObject);
				clearScreen();
				break;
			}
			case 5: {
				adminObject.changeStatusAll(userObject);
				clearScreen();
				break;
			}
			case 6: {
				adminObject.editOrDelete(userObject);
				clearScreen();
				break;
			}
			case 7: {
				system("cls");
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
			// Could use cin.ignore() here as well
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
// Function that controls the flow of user's operations
void userMenu(user* userObject, int indexUser) {
	int userMenuChoice = 0;
	while (userMenuChoice != 3) {
		try {
			cout << "______________________________________________USER SESSION_____________________________________" << endl;
			cout << endl << "Welcome " << userObject[indexUser].getName() << endl;
			cout << "What operation would you like to perform ? " << endl;
			cout << "1) Display Details\n2) Set Personality\n3) Logout And Save Details\n\nEnter Choice: ";
			cin >> userMenuChoice;
			cin.ignore();

			// Exception handling for when user enters anything other than an integer as an input for userMenuChoice
			if (cin.fail()) {
				cin.clear();
				while (cin.get() != '\n') {
					continue;
				}
				throw runtime_error("Invalid input. Please enter a number between 1 and 3.");
			}

			if (userMenuChoice < 1 || userMenuChoice > 3) {
				throw out_of_range("Invalid choice. Please enter a number between 1 and 3.");
			}

			switch (userMenuChoice) {
				case 1: {
					userObject[indexUser].displayDetails();
					clearScreen();
					break;
				}
				case 2: {
					userObject[indexUser].takePersonalityTest();
					writeToUserFile(userObject);
					clearScreen();
					break;
				}
				case 3: {
					system("cls");
					break;
				}
				default: {
					throw runtime_error("Invalid choice. Please enter a number between 1 and 4.");
					break;
				}
			}
		}
		catch (const runtime_error& errorMessage) {
			cerr << errorMessage.what() << endl;
		}
		catch (const out_of_range& errorMessage) {
			cerr << errorMessage.what() << endl;
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

void signup(user* User) {
	system("cls");
	cout << "______________________________________________SIGN UP_______________________________________\n" << endl;
	// Check if user limit has been reached
	if (userCount >= 100) {
		cout << "User limit reached." << endl;
		return;
	}

	// Get new username from user and check if it already exists
	string newUsername;
	bool isUsernameTaken;
	do {
		cout << "Enter Username: ";
		cin >> newUsername;
		isUsernameTaken = false;
		for (int i = 0; i < userCount; i++) {
			if (User[i].getUsername() == newUsername) {
				cout << "Username already exists. Please try again." << endl;
				isUsernameTaken = true;
				break;
			}
		}
	} while (isUsernameTaken);

	// Create a new user object and set the username
	user newUser;
	newUser.setUsername(newUsername);

	// Get other user details
	cin >> newUser;

	// Add the new user to the user array and increment the user count
	User[userCount++] = newUser;

	// Write the updated user count to the file
	writeUserCountToFile();

	cout << "Signup successful." << endl;
}


int authorizedUser = -1;
bool verifyUser(user* User, string username, string password) {
	for (int i = 0; i < userCount; i++) {
		if (User[i].getUsername() == username) {
			if (User[i].getPassword() == password) {
				authorizedUser = i;
				return true;
			}
		}
	}
	return false;
}

void login(admin& Admin, user* User) {
	string tempUsername, tempPassword;
	char ch;

	system("cls");
	cout << "______________________________________________LOGIN_______________________________________\n" << endl;
	cout << "Enter Username: ";
	cin >> tempUsername;
	cout << "Enter Password: ";

	// To hide the password using asterisks
	ch = _getch();
	while (ch != '\r') {
		if (ch != '\b') { tempPassword.push_back(ch); cout << "*"; }
		else if (!tempPassword.empty()) { tempPassword.pop_back(); cout << "\b \b"; }
		ch = _getch();
	}
	cout << endl;


	// Check if admin is logging in
	if (Admin.getUsername() == tempUsername && Admin.getPassword() == tempPassword) {
		system("cls");
		adminMenu(Admin, User);
	}
	else {
		for (int i = 0; i < userCount; i++) {
			if (verifyUser(User, tempUsername, tempPassword)) {
				if (User[i].getStatus() == 0) {
					cout << "Your account is inactive. Please contact the admin to reactivate your account." << endl;
					return;
				}
				else {
					system("cls");
					userMenu(User, authorizedUser);
					break;
				}
			}
		}
	}
}

void populateArray(user* User) {
	ifstream infile("users.txt");
	if (!infile.is_open()) {
		cout << "Error: Failed to open input file." << endl;
		return;
	}
	char mind = '0', energy = '0', nature = '0', tactics = '0', identity = '0';
	for (int i = 0; i < userCount; i++) {
		getline(infile, User[i].username);
		getline(infile, User[i].password);
		getline(infile, User[i].name);
		infile >> User[i].dayOfBirth;
		infile >> User[i].monthOfBirth;
		infile >> User[i].yearOfBirth;
		infile >> User[i].status;
		infile >> mind >> energy >> nature >> tactics >> identity; // read the personality traits as characters
		infile.ignore(1, '\n');
		User[i] = user(User[i].name, User[i].dayOfBirth, User[i].monthOfBirth, User[i].yearOfBirth, User[i].username, User[i].password, User[i].status);
		User[i].personality = personalityQuiz(mind, energy, nature, tactics, identity);
	}
	infile.close();
}
