#include "coreClasses.h"
#include "globalFunctions.h"

// function prototypes
void readUserCountFromFile();
void populateArray(user* User);
void login(admin& Admin, user* User);
void signUp(user* User);

int main() {
	try {
		readUserCountFromFile();
		system("Color F0");
		admin Admin("Sunny", "admin", "123");
		user* User = new user[100];
		populateArray(User);

		while (true) {
			cout << "______________________________________________LoginIn or SignUp_______________________________________\n\n1) Login\n2) SignUp" << endl;
			int userChoice;
			cout << "Enter Choice: ";
			cin >> userChoice;

			while (cin.fail()) {
				cin.clear();
				cin.ignore(); 
				cout << "Invalid input. Please try again: ";
				cin >> userChoice;
			}
			switch (userChoice) {
			case 1:
				login(Admin, User);
				break;
			case 2:
				signUp(User);
				break;
			default:
				throw "Invalid Choice";
				break;
			}
		}
		delete[] User;
	}
	catch (const char* arisedException) {
		cout << "Error: " << arisedException << endl;
		Sleep(2000);
		system("cls");
		main();
	}
	return 0;
}