#pragma once
// Function to initialize count of user when the program is executed
void readUserCountFromFile() {
	ifstream file("usersData/usercount.txt");
	if (file.is_open()) {
		file >> userCount;
		file.close();
	}
}
// Program to increament/decreament number of users in the file
void writeUserCountToFile() {
	ofstream file("usersData/usercount.txt");
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
	// Check for leap year. If it is a leap year, then february would have 29 days, otherwise 28
		daysInMonth = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) ? 29 : 28;
	}
	// April, June, September, and November have 30 days
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		daysInMonth = 30;
	}
	// Other months excluding February have 31 days
	else {
		daysInMonth = 31;
	}
	return day <= daysInMonth;
}
// A function to clean the screen and make execution neat
void clearScreen() {
	cout << endl << "Press Any Key To Clear Screen" << endl;
	char c = _getche();
	system("cls");
}
// A function to write to user file once a change is made
void writeToUserFile(user* User) {
	try {
// In case the file does not open
		ofstream outfile("usersData/users.txt");
		if (!outfile.is_open()) {
			throw runtime_error("Error: File for storing User's data does not exist. Creating.....");
		}
// Writes user's each attribute on a new line in the file 
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
			outfile << User[i].personality.character.getStrength() << endl;
			outfile << User[i].personality.character.getAgility() << endl;
			outfile << User[i].personality.character.getIntelligence() << endl;
			outfile << User[i].personality.character.getFortitude() << endl;
			outfile << User[i].personality.character.getCharisma() << endl;
		}
		outfile.close();
		writeUserCountToFile();
	}
	catch (const exception& exceptionMessage) {
		cerr << exceptionMessage.what() << endl;
	}
}
// Function that controls the flow of admin's operations
void adminMenu(admin& adminObject, user* userObject) {
	int adminMenuChoice = 0;
	while (adminMenuChoice != 7) {
		try {
			cout << "                      ___________________________________________________________________________" << endl;
			cout << "                     |                                                                           |" << endl;
			cout << "                     |                               ADMIN SESSION                               |" << endl;
			cout << "                     |___________________________________________________________________________|" << endl;
			cout << "                                                                                                   " << endl;
			cout << "                                                 Welcome, " << adminObject.getName() << "!" << endl;
			cout << "                            _______________________________________________________________       " << endl;
			cout << "                           |                                                               |        " << endl;
			cout << "                           |          What operation would you like to perform ?           |        " << endl;
			cout << "                           |_______________________________________________________________|        " << endl;
			cout << "                                              " << endl;
			cout << "         1) Display Count Of Users" << endl;
			cout << "         2) Display All Users" << endl;
			cout << "         3) Display Only Inactive Users" << endl;
			cout << "         4) Change Status Of A Specific Account" << endl;
			cout << "         5) Change Status Of All Accounts" << endl;
			cout << "         6) Edit Or Delete User's Information" << endl;
			cout << "         7) Logout Of Your Account" << endl;
			cout << "                                              " << endl;
			cout << "         Enter Choice: ";
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
				system("cls");
				cout << "                      ___________________________________________________________________________" << endl;
				cout << "                     |                                                                           |" << endl;
				cout << "                     |                               ADMIN SESSION                               |" << endl;
				cout << "                     |___________________________________________________________________________|" << endl << endl;
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
	while (userMenuChoice != 4) {
		try {
			cout << "                          ___________________________________________________________________" << endl;
			cout << "                         |                                                                   |" << endl;
			cout << "                         |                           USER SESSION                            |" << endl;
			cout << "                         |___________________________________________________________________|" << endl;
			cout << "                                            " << endl;
			cout << "                                                    Welcome, " << userObject[indexUser].getName() << "!" << endl;
			cout << "                              ____________________________________________________________" << endl;
			cout << "                             |                                                            |" << endl;
			cout << "                             |          What operation would you like to perform ?        |" << endl;
			cout << "                             |____________________________________________________________|" << endl;
			cout << "                                            " << endl;
			cout << "           1) Display Your Details" << endl;
			cout << "           2) Set Your Personality And Fictional Character" << endl;
			cout << "           3) Know About Your Zodiac Sign" << endl;
			cout << "           4) Logout Of Your Account" << endl;
			cout << "                                            " << endl;
			cout << "           Enter Choice: ";

			cin >> userMenuChoice;
			cin.ignore();

			// Exception handling for when user enters anything other than an integer as an input for userMenuChoice
			if (cin.fail()) {
				cin.clear();
				while (cin.get() != '\n') {
					continue;
				}
				throw runtime_error("Invalid input. Please enter a number between 1 and 4.");
			}

			if (userMenuChoice < 1 || userMenuChoice > 4) {
				throw out_of_range("Invalid choice. Please enter a number between 1 and 4.");
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
					userObject[indexUser].displayZodiacDetails();
					clearScreen();
				}
				case 4: {
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
	cout << "                               _______________________________________________________" << endl;
	cout << "                              |                                                       |" << endl;
	cout << "                              |                         SIGNUP                        |" << endl;
	cout << "                              |_______________________________________________________|" << endl;
	cout << "\n                   Please enter your details:" << endl << endl;;
	// Check if user limit has been reached
	if (userCount >= 100) {
		cout << "User limit reached." << endl;
		return;
	}

	// Get new username from user and check if it already exists
	string newUsername;
	bool isUsernameTaken;
	do {
		cout << "                     Enter Username: ";
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
	system("cls");
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
	cout << "                               _______________________________________________________" << endl;
	cout << "                              |                                                       |" << endl;
	cout << "                              |                         LOGIN                         |" << endl;
	cout << "                              |_______________________________________________________|" << endl;
	cout << "\n                   Please enter your credentials:" << endl << endl;;
	cout << "                     Enter your Username: ";
	cin >> tempUsername;
	cout << "                     Enter your Password: ";

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
				if (User[i].getStatus() == false) {
					cout << "Your account is inactive. Please contact the admin to reactivate your account." << endl;
					clearScreen();
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
// This function is responsible for populating the user array at the execution of the program
void populateArray(user* User) {
	ifstream infile("usersData/users.txt");
	if (!infile.is_open()) {
		cout << "Error: Failed to open input file." << endl;
		return;
	}
	char mind = '0', energy = '0', nature = '0', tactics = '0', identity = '0';
	int strength = 0, agility = 0, intelligence = 0, fortitude = 0, charisma = 0;
	for (int i = 0; i < userCount; i++) {
		getline(infile, User[i].username);
		getline(infile, User[i].password);
		getline(infile, User[i].name);
		infile >> User[i].dayOfBirth;
		infile >> User[i].monthOfBirth;
		infile >> User[i].yearOfBirth;
		infile >> User[i].status;
		infile >> mind >> energy >> nature >> tactics >> identity; // read the personality traits as characters
		infile >> strength >> agility >> intelligence >> fortitude >> charisma;
		infile.ignore(1, '\n');
		User[i] = user(User[i].name, User[i].dayOfBirth, User[i].monthOfBirth, User[i].yearOfBirth, User[i].username, User[i].password, User[i].status);
		User[i].personality = personalityQuiz(mind, energy, nature, tactics, identity);
		User[i].personality.character.setStrength(strength); User[i].personality.character.setAgility(agility); User[i].personality.character.setIntelligence(intelligence); User[i].personality.character.setFortitude(fortitude); User[i].personality.character.setCharisma(charisma);
		User[i].personality.character.calculateCharacter();
	}
	infile.close();
}