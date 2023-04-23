#include "coreClasses.h"
#include "globalFunctions.h"

// Driver code
int main(void) {
	try {
		// Reads User Count From The Files On Execution
		readUserCountFromFile();
		system("Color F0");
		admin Admin("Sunny", "admin", "123");
		// Makes a pointer to user's class and assign it an array of size 100
		user* User = new user[100];
		populateArray(User);
		while (true) {
			cout << "______________________________________________LoginIn or SignUp_______________________________________\n\n1) Login\n2) SignUp\n3) Exit" << endl;
			int userChoice;
			cout << "Enter Choice: ";
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