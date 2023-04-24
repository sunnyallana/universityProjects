#include "coreClasses.h"
#include "globalFunctions.h"

// Driver code
int main(void) {
	try {
		// Reads User Count From The Files On Execution
		readUserCountFromFile();
		// To change color of the console's background and font
		system("Color F0");
		admin Admin("Administrator", "admin", "123");
		// Makes a pointer to user's class and assign it an array of size 100
		user* User = new user[100];
		// Reads Users' details from the file and populates the array on execution
		populateArray(User);
		int userChoice;
		while (true) {
			cout << "                          ___________________________________________________________________" << endl;
			cout << "                         |                                                                   |" << endl;
			cout << "                         |                     WELCOME TO THE APPLICATION                    |" << endl;
			cout << "                         |___________________________________________________________________|" << endl;
			cout << "                               _______________________________________________________" << endl;
			cout << "                              |                                                       |" << endl;
			cout << "                              |                     LOGIN OR SIGNUP                   |" << endl;
			cout << "                              |_______________________________________________________|" << endl;
			cout << "\n                   Please select an option:" << endl;
			cout << "                   1) Login" << endl;
			cout << "                   2) Signup" << endl;
			cout << "                   3) Exit" << endl << endl;
			cout << "                   Option: ";
			cin >> userChoice;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << endl << "Invalid input. Please try again." << endl;
				system("cls");
				continue;
			}
			switch (userChoice) {
			case 1:
				login(Admin, User);
				break;
			case 2:
				signup(User);
				break;
			case 3:
				// Write user count to file on exit
				writeUserCountToFile();
				cout << "Thank You For Using The System" << endl;
				exit(0);
			default:
				cout << "Invalid choice. Please try again." << endl;
				Sleep(1000);
				system("cls");
				break;
			}
		}
		delete[] User;
	}
	catch (const exception& exceptionMessage) {
		cerr << exceptionMessage.what() << endl;
	}
	return 0;
}