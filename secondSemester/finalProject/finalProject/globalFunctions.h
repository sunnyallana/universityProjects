#pragma once
int main(void);

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
		Admin.displayDetails(User);
		Admin.deleteUser(User);
		writeUserCountToFile();
		// Perform admin actions
	}








	else {
		bool found = false;
		for (int i = 0; i < userCount; i++) {
			if (User[i].verifyUser(tempUsername, tempPassword) == 1) {
				cout << "User Session" << endl;
				cout << User[i] << endl; // Just to test execution
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
	if (userCount < 100) {
		cin >> User[userCount];
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
		infile.ignore();
		User[i] = user(User[i].name, User[i].dayOfBirth, User[i].monthOfBirth, User[i].yearOfBirth, User[i].username, User[i].password);
	}
	infile.close();
}