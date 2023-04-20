#include "coreClasses.h"
#include "globalFunctions.h"

int main(void) {
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
		switch (userChoice) {
		case 1:
			login(Admin, User);
			break;
		case 2:
			signUp(User);
			break;
		default:
			cout << "Invalid choice." << endl;
			returnToLoginPage();
			break;
		}
	}
	delete[] User;
	return 0;
}


