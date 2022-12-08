/* Author: Sunny Shaban 22K-4149
	Programming Fundamentals' Lab Final Project
	Variables throughout the code have been declared using camelCase and comments have been encapsulated for better comprehension of the code
*/

// Preprocessing Directives

// For basic input/output functions and file handling
#include <stdio.h>
// To use strcpy function in deleteInformation(stptr)
#include <string.h>
// To use exit() function
#include <stdlib.h>
// To use sleep function while recursively calling main
#include <windows.h>
// To counter memory holes/leakage due to usage of structures
#pragma pack(1)


// Defining Keys for Snake Game
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77


// Prototyping Core functions
void stressTest();
void addInformation();
void viewInformation();
void editInformation();
void deleteInformation();
void searchInformation();
void readFile();
void writeFile();
void returnMain();
void userLogin();
void readAppointments();
void writeAppointments();
void bookAppointments();
void viewAppointments();

// Snake Game functions
void snakeGame();
void loadSnakeGame();
void delayLengthSnakeGame(long double);
void moveSnakeGame();
void randomFoodSnakeGame();
void instructionsSnakeGame();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void bendSnakeGame();
void borderSnakeGame();
void downMovementSnakeGame();
void leftMovementSnakeGame();
void upMovementSnakeGame();
void rightMovementSnakeGame();
void exitSnakeGame();
int scoreSnakeGame();

// Defining a structure consisting of all relevant client's detail
struct clientData{
	char clientName[30];
	int clientAge;
	char clientDisorder[40]; 
	char clientPersonalityType[30]; 	
	char clientTreatmentPlan[100]; 	
	char clientLastVisit[30];
	char clientNextAppointment[30]; 	
	long long int clientMobileNumber;
	};
	
// Defining a structure consisting of users' credentials
struct userCredentials{
    char userId[10];
    char userKey[10];
}*credentialsPtr;

// Defining a structure that stores intricacies pertaining to Appointments
struct appointments{
	char appointmentName[20];
	long long int appointmentMobile;
	char appointmentVisit[30];	
}appointmentAll[50];


// Snake Game structure
struct coordinate{
    int x;
    int y;
    int direction;
};
typedef struct coordinate coordinate;
coordinate head, bend[500],food,body[30];

// Global variables for Snake Game
int length, bend_no, len, life;
char key;


// Declaring some global variables that are meant for use in multiple core functions
int numberData = 0, totalData = 0, numberAppointment = 0;
// Identifier to perform relevant operations after login
int throughLogin = 0;
// Defining main and declaring necessary variables
int main(void){
// To change the background and foreground color
	system("color F0");
// Printing title
	printf("\n-----------------------------------------PSYCHOLOGICAL CLINIC MANAGEMENT SYSTEM-----------------------------------------\n");
// Pointer for structures
	struct clientData allClients[100];
    struct  clientData* stptr = allClients;
// Reading from file or creating a new one if it does not exist
	readFile(stptr);
// Calling Login System
	userLogin();
	if(throughLogin == 1){
// Defining userChoice for use in switch case statements
	int userChoice;
	system("cls");
	printf("\n------------------------------------------------------ADMIN ACCESS------------------------------------------------------\n");
// Asking for user choice and executing the relevant function using switch case statement
	printf("\nWhat action would you like to perform ?: ");
	printf("\n\n1) Perceived Stress scale"
	"\n2) Add Client's Information"
	"\n3) View Client's Information"
	"\n4) Edit Client's Information"
	"\n5) Delete Client's Information"
	"\n6) Search"
	"\n7) View Appointments"
	"\n8) Exit\n\nChoice (In Number): ");
	scanf("%d", &userChoice);
	fflush(stdin);
	switch(userChoice){
		case 1:
			system("cls");
			stressTest();
// Using recursion to call main again after execution of personalityTest to make it user friendly
			returnMain();
			break;
		case 2:
			system("cls");
			addInformation(stptr);
// Using recursion to call main again after execution of addInformation to make it user friendly
			returnMain();
			break;
		case 3:
			system("cls");
			viewInformation(stptr);
// Using recursion to call main again after execution of viewInformation to make it user friendly
			returnMain();
			break;
		case 4:
			system("cls");
			editInformation(stptr);
// Using recursion to call main again after execution of editInformation to make it user friendly
			returnMain();
			break;
		case 5:
			system("cls");
			deleteInformation(stptr);
// Using recursion to call main again after execution of deleteInformation to make it user friendly
			returnMain();
			break;
		case 6:
			system("cls");
			searchInformation(stptr);
// Using recursion to call main again after execution of searchInformation to make it user friendly
			returnMain();
			break;
		case 7:
			system("cls");
			viewAppointments();
// Using recursion to call main again after execution of viewAppointments to make it user friendly
			returnMain();
			break;
		case 8:
			writeFile(stptr);
			system("cls");
			printf("Have a nice day!");
			exit(0);
			break;
		default: 
			printf("Invalid choice");
			exit(1);
			break;
	}
}
	else if(throughLogin == 2){
		int varChoice;
		printf("\n-----------------------------------------------------USER ACCESS-----------------------------------------------------\n\n");
		printf("\n\n1) Compute your stress Level\n"
		"2) Book Appointment\n"
		"3) Exit\n\n");
		printf("Choice: ");
		scanf("%d", &varChoice);
		switch(varChoice){
			case 1:
				system("cls");
				stressTest();
				break;
			case 2:
				system("cls");
				bookAppointments();
				break;
			case 3:
				printf("Have a nice day!");
				exit(0);
				break;
			deafult:
				printf("\nInvalid Choice");
				exit(1);
		}
	}
// To return control to OS
return 0;
}
// Defining functions for the purpose of modularity and reusability

// Responsible for logging in if credentials are correct
void userLogin(){
    FILE *lsPtr;
    char tempUsername[10], tempKey[10];int loginChoice; char c;
	int flag = 0;
    credentialsPtr=(struct userCredentials*)malloc(sizeof(struct userCredentials));
    printf("\n\n\n1. Login Through An Existing Account\n2. Create New account\n\n\n");
    printf("Enter Choice: ");
    scanf("%d", &loginChoice);
    //system("cls");
    switch(loginChoice){
        case 1:
            if ((lsPtr=fopen("loginSystem.dat", "r+")) == NULL){
                if ((lsPtr=fopen("loginSystem.dat", "w+")) == NULL){
                    printf ("Could not open file\n");
                    exit(1);
                }
            }
            fflush(stdin);
            printf("\nUsername: ");
            gets(tempUsername);
            printf("Password: ");
            gets(tempKey);
            fflush(stdin);
            if(strcmp(tempUsername, "sunnyallana")==0 && strcmp(tempKey, "sunny123") == 0){
            	throughLogin = 1;
			}
			
            else{
            while (fread (credentialsPtr, sizeof(struct userCredentials), 1, lsPtr) == 1){
                if(strcmp ( credentialsPtr->userId, tempUsername) == 0 && strcmp ( credentialsPtr->userKey, tempKey) == 0) {
                    printf ("\nLogin successful.....\n"); 
					flag = 1;
					throughLogin = 2;
					sleep(3);
                }
            }
            if(flag == 0){
            	printf("\nLogin Unsuccessful due to incorrect Username or Password. Exiting.....\n");
            	exit(1);
			}
			}
            break;
            
        case 2:
                if ((lsPtr=fopen("loginSystem.dat", "a+")) == NULL) {
                    if ((lsPtr=fopen("loginSystem.dat", "w+")) == NULL) {
                        printf ("Could not open file\n");
                        exit (1);
                    }
                }
                fflush(stdin);
                printf("\nChoose A Username: ");
                gets(credentialsPtr->userId);
                printf("Choose A Password: ");
                gets(credentialsPtr->userKey);
                fflush(stdin);
                fwrite (credentialsPtr, sizeof(struct userCredentials), 1, lsPtr);
              
            break;
            
            
    	default:
    		printf("Invalid Choice");
    }
    
    free(credentialsPtr);//free allocated memory
    fclose(lsPtr);
}

// This function is responsible for computing the type of personality a client has
void stressTest(){
	int stressScore[5]={0}, totalScore = 0;
	int i, stressRank;
	char question[150];
	FILE *qptr = fopen("questionnaire.txt", "r");
	if (qptr == 0){
		printf("Missing Resources!\nExiting.....\n");
		exit(1);
	}
	printf("\n------------------------------------------------RANKS AND THEIR MEANING------------------------------------------------\n\n"
	"0) Never\n"
	"1) Almost Never\n"
	"2) Sometimes\n"
	"3) Fairly Often\n"
	"4) Very Often\n\n"
	"\n----------------------------------ANSWER THE FOLLOWING QUESTIONS USING THE RANKS ABOVE----------------------------------\n\n\n"
	);
	
	for(i = 0; i < 10; i++){
		fgets(question, 150, qptr);
		puts(question);
		printf("Rank: ");
		scanf("%d", &stressRank);
		if(stressRank < 0 || stressRank > 4){
			printf("Invalid Rank!\nReturning to Main Menu\n");
			returnMain();
			
		}
		else if ((i == 3 || i ==4 || i == 6 || i == 7) && stressRank == 0){
			stressScore[0] += 4;
		}
		else if((i == 3 || i ==4 || i == 6 || i == 7) && stressRank == 1){
			stressScore[1] += 3;
		}
		else if((i == 3 || i ==4 || i == 6 || i == 7) && stressRank == 2){
			stressScore[2] += 2;
		}
		else if((i == 3 || i ==4 || i == 6 || i == 7) && stressRank == 3){
			stressScore[3] += 1;
		}
		else if((i == 3 || i ==4 || i == 6 || i == 7) && stressRank == 4){
			stressScore[4] += 0;
		}
		else if(stressRank == 0){
			stressScore[0] += 0;
		}
		else if(stressRank == 1){
			stressScore[1] += 1;
		}
		else if(stressRank == 2){
			stressScore[2] += 2;
		}
		else if(stressRank == 3){
			stressScore[3] += 3;
		}
		else if(stressRank == 4){
			stressScore[4] += 4;
		}
		puts("");
	}
	for(i = 0; i < 5; i ++){
		totalScore += stressScore[i];
	}
	printf("\n------------------------------------------------EVALUATION------------------------------------------------\n\n");
	if( totalScore >= 0 && totalScore <= 13){
		printf("Low Stress\n");
	}
	else if( totalScore >= 14 && totalScore <= 26){
		printf("\n\t\t\t\t\t\tModerate Stress\n");
		sleep(3);
		system("cls");
// Provide user a choice to play a game if he/she has moderate or high stress
		snakeGame();
	}
	else if( totalScore >= 27 && totalScore <= 40){
		printf("\n\t\t\t\t\t\tHigh perceived Stress\n");
		sleep(3);
		system("cls");
		snakeGame();
	}	
}
// This function is responsible for adding new client's information
void addInformation(struct  clientData* const stptr){
	int i, numberIterations;
	printf("Number of clients whose data is currently present in the database: %d", numberData);
	printf("\n\nHow many clients' data do you want to enter ?: ");
	scanf("%d", &numberIterations);
	totalData = numberIterations + numberData; 
	
	for(i = numberData; i < totalData; i++){
        printf("\n");
        fflush(stdin);
        printf("Enter Client's name: ");
        gets((stptr+i)->clientName);
        fflush(stdin);
        printf("Enter Client's age: ");
        scanf("%d", &(stptr+i)->clientAge);
        fflush(stdin);
        printf("Enter the Disorder Client is diagnosed with: ");
        gets((stptr+i)->clientDisorder);
        fflush(stdin);
        printf("Enter Personality type: ");
        gets((stptr+i)->clientPersonalityType);
        fflush(stdin);
        printf("Enter Treatment plan: ");
        gets((stptr+i)->clientTreatmentPlan);
        fflush(stdin);
        printf("Enter Date of last visit [DD/MM/YYYY] and Time [HH:MM] A.M./P.M. with space: ");
        gets((stptr+i)->clientLastVisit);
        fflush(stdin);
        printf("Enter Date of next appointment [DD/MM/YYYY] and Time [HH:MM] A.M./P.M. with space: ");
        gets((stptr+i)->clientNextAppointment);
        fflush(stdin);
        printf("Enter Client's Mobile number: ");
        scanf("%lld", &(stptr+i)->clientMobileNumber);
        fflush(stdin);
        printf("\n");
        numberData ++;
    }
    writeFile(stptr);
}
// This function is responsible for demonstrating all stored data
void viewInformation(const struct  clientData* const stptr){
	int i;
    for(i = 0; i < numberData; i++)
    {
        printf("\nClient's Serial Number: %d\n", i);
        printf("Client's Name: ");
        puts((stptr+i)->clientName);
        printf("Client's age: %d",(stptr+i)->clientAge);
        printf("\nDisorder diagnosed with: ");
        puts((stptr+i)->clientDisorder);
		printf("Client's Personality Type: ");
		puts((stptr+i)->clientPersonalityType);
		printf("Client's Treatment Plan: ");
		puts((stptr+i)->clientTreatmentPlan);
		printf("Last Visit: ");
		puts((stptr+i)->clientLastVisit);
		printf("Next Visit: ");
		puts((stptr+i)->clientNextAppointment);
		printf("Mobile Number: %lld", (stptr+i)->clientMobileNumber);
        printf("\n\n");
    }
}
// This function is responsible for editing a particular client's detials
void editInformation(struct  clientData* const stptr){
	int editChoice, editSerial;
	printf("\n----------------------------------------------------EDIT INFORMATION----------------------------------------------------");
	printf("\n\nEnter the client's serial number: ");
	scanf("%d", &editSerial);
	printf("\nWhat do you want to edit ?: \n");
	printf("1) Client's name\n2) Client's age\n3) Disorder diagnosed with\n4) Client's Personality Type\n5) Client's Treatment Plan\n6) Client's Last Visit\n7) Client's Next Appointment\n\nChoice (In Number): ");
	scanf("%d", &editChoice);
	if(editSerial < numberData){
		switch(editChoice){
			case 1:
				fflush(stdin);
				printf("Change Name to: ");
				gets((stptr+editSerial)->clientName);
				printf("\nName updated\n\n");
				break;
		
			case 2:
				fflush(stdin);
				printf("Change Age to: ");
				scanf("%d", &(stptr+editSerial)->clientAge);
				printf("\nAge updated\n\n");
				break;
			
			case 3:
				fflush(stdin);
				printf("Change Disorder Diagnosed with to: ");
				gets((stptr+editSerial)->clientDisorder);
				printf("\nDisorder diagnosed with updated\n\n");
				break;
			
			case 4:
				fflush(stdin);
				printf("Change Personality Type to: ");
				gets((stptr+editSerial)->clientPersonalityType);
				printf("\nPersonality Type updated\n\n");
				break;
		
			case 5:
				fflush(stdin);
				printf("Change Treatment Plan to: ");
				gets((stptr+editSerial)->clientTreatmentPlan);
				printf("\nTreatment Plan updated\n\n");
				break;
				
			case 6:
				fflush(stdin);
				printf("Change Last Visit to: ");
				gets((stptr+editSerial)->clientLastVisit);
				printf("\nLast Visit updated\n\n");
				break;
				
			case 7:
				fflush(stdin);
				printf("Change Next Appointment to: ");
				gets((stptr+editSerial)->clientNextAppointment);
				printf("\nNext Appointment updated\n\n");
				break;
				
			default :
				printf("\nInvalid Choice. Exiting.....\n\n");	
				exit(1);	
		}
		writeFile(stptr);
	}
	
	else{
		printf("Invalid Serial Number\n");
		returnMain();
		
	}
}
// This function is responsible for deleting a particular client's data
void deleteInformation(struct  clientData* const stptr){
	int deleteSerial;
	printf("\n--------------------------------------------------DELETE INFORMATION--------------------------------------------------\n\n");
	printf("Enter the serial number of the client whose record who want to delete: ");
	scanf("%d", &deleteSerial);
	while(deleteSerial < numberData){
		    strcpy((stptr+deleteSerial)->clientName,(stptr+deleteSerial+1)->clientName);
		    (stptr+deleteSerial)->clientAge = (stptr+deleteSerial+1)->clientAge;
            strcpy((stptr+deleteSerial)->clientDisorder, (stptr+deleteSerial+1)->clientDisorder);
            strcpy((stptr+deleteSerial)->clientPersonalityType, (stptr+deleteSerial+1)->clientPersonalityType);
            strcpy((stptr+deleteSerial)->clientTreatmentPlan, (stptr+deleteSerial+1)->clientTreatmentPlan);
            strcpy((stptr+deleteSerial)->clientLastVisit, (stptr+deleteSerial+1)->clientLastVisit);
            strcpy((stptr+deleteSerial)->clientNextAppointment, (stptr+deleteSerial+1)->clientNextAppointment);
            (stptr+deleteSerial)->clientMobileNumber = (stptr+deleteSerial+1)->clientMobileNumber;
            deleteSerial ++;
            }
            numberData--;
            printf("\nRecord deleted successfully.....\n\n");
            writeFile(stptr);
}
// This function is responsible for searching relevant client's using partial details
void searchInformation(const struct  clientData* const stptr){
	int i, searchChoice, searchAge;
	long long int searchMobile;
	char searchName[20], searchDisorder[20], searchPersonality[20], searchTreatment[50], searchLastVisit[30], searchNextAppointment[30];
	printf("Choose the medium using which you want to search for the relevant client: \n");
	printf("1) Search using Client's Name\n"
	"2) Search using Client's Age\n"
	"3) Search using Client's Disorder\n"
	"4) Search using Client's Personality Type\n"
	"5) Search using Client's Treatment Plan\n"
	"6) Search using Client's last visit\n"
	"7) Search using Client's next appointment\n"
	"8) Search using Client's Mobile number\n\n");
	printf("Enter Choice: ");
	scanf("%d", &searchChoice);
	
	switch(searchChoice){
		case 1:
			printf("Enter Client's Name: ");
			scanf("%s", &searchName);
			printf("\n----------------------------------------------------RELEVANT RECORDS----------------------------------------------------\n");
			for(i = 0; i < numberData; i++){
				if(strcmp(searchName, (stptr+i)->clientName) == 0){
					printf("\nClient's Serial Number: %d\n", i);
			        printf("Client's Name: ");
			        puts((stptr+i)->clientName);
			        printf("Client's age: %d", (stptr+i)->clientAge);
			        printf("\nDisorder diagnosed with: ");
			        puts((stptr+i)->clientDisorder);
					printf("Client's Personality Type: ");
					puts((stptr+i)->clientPersonalityType);
					printf("Client's Treatment Plan: ");
					puts((stptr+i)->clientTreatmentPlan);
					printf("Last Visit: ");
					puts((stptr+i)->clientLastVisit);
					printf("Next Visit: ");
					puts((stptr+i)->clientNextAppointment);
					printf("Mobile Number: %lld", (stptr+i)->clientMobileNumber);
			        printf("\n\n");
				}
			}
			break;
			
		case 2:
				printf("Enter Client's Age: ");
				scanf("%d", &searchAge);
				printf("\n----------------------------------------------------RELEVANT RECORDS----------------------------------------------------\n");
				for(i = 0; i < numberData; i++){
					if(searchAge == (stptr+i)->clientAge){
						printf("\nClient's Serial Number: %d\n", i);
				        printf("Client's Name: ");
				        puts((stptr+i)->clientName);
				        printf("Client's age: %d", (stptr+i)->clientAge);
				        printf("\nDisorder diagnosed with: ");
				        puts((stptr+i)->clientDisorder);
						printf("Client's Personality Type: ");
						puts((stptr+i)->clientPersonalityType);
						printf("Client's Treatment Plan: ");
						puts((stptr+i)->clientTreatmentPlan);
						printf("Last Visit: ");
						puts((stptr+i)->clientLastVisit);
						printf("Next Visit: ");
						puts((stptr+i)->clientNextAppointment);
						printf("Mobile Number: %lld", (stptr+i)->clientMobileNumber);
				        printf("\n\n");
				}
			}
			break;
			
		case 3:
			printf("Enter Client's Disorder: ");
			scanf("%s", &searchDisorder);
			printf("\n----------------------------------------------------RELEVANT RECORDS----------------------------------------------------\n");
			for(i = 0; i < numberData; i++){
				if(strcmp(searchDisorder, (stptr+i)->clientDisorder) == 0){
					printf("\nClient's Serial Number: %d\n", i);
			        printf("Client's Name: ");
			        puts((stptr+i)->clientName);
			        printf("Client's age: %d", (stptr+i)->clientAge);
			        printf("\nDisorder diagnosed with: ");
			        puts((stptr+i)->clientDisorder);
					printf("Client's Personality Type: ");
					puts((stptr+i)->clientPersonalityType);
					printf("Client's Treatment Plan: ");
					puts((stptr+i)->clientTreatmentPlan);
					printf("Last Visit: ");
					puts((stptr+i)->clientLastVisit);
					printf("Next Visit: ");
					puts((stptr+i)->clientNextAppointment);
					printf("Mobile Number: %lld", (stptr+i)->clientMobileNumber);
			        printf("\n\n");
				}
			}
			break;
			
		case 4:
			printf("Enter Client's Personality Type: ");
			scanf("%s", &searchPersonality);
			printf("\n----------------------------------------------------RELEVANT RECORDS----------------------------------------------------\n");
			for(i = 0; i < numberData; i++){
				if(strcmp(searchPersonality, (stptr+i)->clientPersonalityType) == 0){
					printf("\nClient's Serial Number: %d\n", i);
			        printf("Client's Name: ");
			        puts((stptr+i)->clientName);
			        printf("Client's age: %d", (stptr+i)->clientAge);
			        printf("\nDisorder diagnosed with: ");
			        puts((stptr+i)->clientDisorder);
					printf("Client's Personality Type: ");
					puts((stptr+i)->clientPersonalityType);
					printf("Client's Treatment Plan: ");
					puts((stptr+i)->clientTreatmentPlan);
					printf("Last Visit: ");
					puts((stptr+i)->clientLastVisit);
					printf("Next Visit: ");
					puts((stptr+i)->clientNextAppointment);
					printf("Mobile Number: %lld", (stptr+i)->clientMobileNumber);
			        printf("\n\n");
				}
			}
			break;
			
		case 5:
			printf("Enter Client's Treatment Plan: ");
			scanf("%s", &searchTreatment);
			printf("\n----------------------------------------------------RELEVANT RECORDS----------------------------------------------------\n");
			for(i = 0; i < numberData; i++){
				if(strcmp(searchTreatment, (stptr+i)->clientTreatmentPlan) == 0){
					printf("\nClient's Serial Number: %d\n", i);
			        printf("Client's Name: ");
			        puts((stptr+i)->clientName);
			        printf("Client's age: %d", (stptr+i)->clientAge);
			        printf("\nDisorder diagnosed with: ");
			        puts((stptr+i)->clientDisorder);
					printf("Client's Personality Type: ");
					puts((stptr+i)->clientPersonalityType);
					printf("Client's Treatment Plan: ");
					puts((stptr+i)->clientTreatmentPlan);
					printf("Last Visit: ");
					puts((stptr+i)->clientLastVisit);
					printf("Next Visit: ");
					puts((stptr+i)->clientNextAppointment);
					printf("Mobile Number: %lld", (stptr+i)->clientMobileNumber);
			        printf("\n\n");
				}
			}
			break;
			
		case 6:
			printf("Enter Client's Last Visit: ");
			scanf("%s", &searchLastVisit);
			printf("\n----------------------------------------------------RELEVANT RECORDS----------------------------------------------------\n");
			for(i = 0; i < numberData; i++){
				if(strcmp(searchLastVisit, (stptr+i)->clientLastVisit) == 0){
					printf("\nClient's Serial Number: %d\n", i);
			        printf("Client's Name: ");
			        puts((stptr+i)->clientName);
			        printf("Client's age: %d", (stptr+i)->clientAge);
			        printf("\nDisorder diagnosed with: ");
			        puts((stptr+i)->clientDisorder);
					printf("Client's Personality Type: ");
					puts((stptr+i)->clientPersonalityType);
					printf("Client's Treatment Plan: ");
					puts((stptr+i)->clientTreatmentPlan);
					printf("Last Visit: ");
					puts((stptr+i)->clientLastVisit);
					printf("Next Visit: ");
					puts((stptr+i)->clientNextAppointment);
					printf("Mobile Number: %lld", (stptr+i)->clientMobileNumber);
			        printf("\n\n");
				}
			}
			break;
			
		case 7:
			printf("Enter Client's Next appointment: ");
			scanf("%s", &searchNextAppointment);
			printf("\n----------------------------------------------------RELEVANT RECORDS----------------------------------------------------\n");
			for(i = 0; i < numberData; i++){
				if(strcmp(searchNextAppointment, (stptr+i)->clientNextAppointment) == 0){
					printf("\nClient's Serial Number: %d\n", i);
			        printf("Client's Name: ");
			        puts((stptr+i)->clientName);
			        printf("Client's age: %d", (stptr+i)->clientAge);
			        printf("\nDisorder diagnosed with: ");
			        puts((stptr+i)->clientDisorder);
					printf("Client's Personality Type: ");
					puts((stptr+i)->clientPersonalityType);
					printf("Client's Treatment Plan: ");
					puts((stptr+i)->clientTreatmentPlan);
					printf("Last Visit: ");
					puts((stptr+i)->clientLastVisit);
					printf("Next Visit: ");
					puts((stptr+i)->clientNextAppointment);
					printf("Mobile Number: %lld", (stptr+i)->clientMobileNumber);
			        printf("\n\n");
				}
			}
			break;
			
		case 8:
			printf("Enter Client's Mobile Number: ");
			scanf("%lld", &searchMobile);
			printf("\n----------------------------------------------------RELEVANT RECORDS----------------------------------------------------\n");
			for(i = 0; i < numberData; i++){
				if(searchMobile == (stptr+i)->clientMobileNumber){
					printf("\nClient's Serial Number: %d\n", i);
			        printf("Client's Name: ");
			        puts((stptr+i)->clientName);
			        printf("Client's age: %d", (stptr+i)->clientAge);
			        printf("\nDisorder diagnosed with: ");
			        puts((stptr+i)->clientDisorder);
					printf("Client's Personality Type: ");
					puts((stptr+i)->clientPersonalityType);
					printf("Client's Treatment Plan: ");
					puts((stptr+i)->clientTreatmentPlan);
					printf("Last Visit: ");
					puts((stptr+i)->clientLastVisit);
					printf("Next Visit: ");
					puts((stptr+i)->clientNextAppointment);
					printf("Mobile Number: %lld", (stptr+i)->clientMobileNumber);
			        printf("\n\n");
			}
		}
		break;
		
		default:
			printf("Invalid output");			
	}	
}
// This function controls the entire snake game
void snakeGame(){
	int choiceGame;
	printf("\n------------------------------------------------------SNAKE GAME------------------------------------------------------\n");
	printf("\n\nWould you like to play a fun game: \n\n"
	"1) Yes\n"
	"2) No\n");
	printf("\n\nEnter Choice in number: ");
	scanf("%d", &choiceGame);
	printf("\n\n");
	if(choiceGame == 1){
		char key;
	    instructionsSnakeGame();
	    system("cls");
	    loadSnakeGame();
	    length=5;
	    head.x=25;
	    head.y=20;
	    head.direction=RIGHT;
	    borderSnakeGame();
	    randomFoodSnakeGame(); //to generate food coordinates initially
	    life=3; //number of extra lives
	    bend[0]=head;
	    moveSnakeGame();
		returnMain(); //initialing initial bend coordinate
	}
	else if(choiceGame == 2){
		returnMain();
	}
	else{
		returnMain();
	}
}

void moveSnakeGame(){
    int a,i;
    do{
        randomFoodSnakeGame();
        fflush(stdin);
        len=0;
        for(i=0; i<30; i++){
            body[i].x=0;
            body[i].y=0;
            if(i==length)
                break;
        }
        delayLengthSnakeGame(length);
        borderSnakeGame();
        if(head.direction==RIGHT)
            rightMovementSnakeGame();
        else if(head.direction==LEFT)
            leftMovementSnakeGame();
        else if(head.direction==DOWN)
            downMovementSnakeGame();
        else if(head.direction==UP)
            upMovementSnakeGame();
        exitSnakeGame();
    }
    while(!kbhit());
    a=getch();
    if(a==27){
        system("cls");
        exit(0);
    }
    key=getch();
    if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN)){
        bend_no++;
        bend[bend_no]=head;
        head.direction=key;
        if(key==UP)
            head.y--;
        if(key==DOWN)
            head.y++;
        if(key==RIGHT)
            head.x++;
        if(key==LEFT)
            head.x--;
        moveSnakeGame();
    }
    else if(key==27)
    {
        system("cls");
        exit(0);
    }
    else
    {
        printf("\a");
        moveSnakeGame();
    }
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}
void loadSnakeGame()
{
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("LOADING.....");
    gotoxy(30,15);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); //to display the character slowly
        printf("%c",177);
    }
    sleep(1);
}
void downMovementSnakeGame()
{
    int i;
    for(i=0; i<=(head.y-bend[bend_no].y)&&len<length; i++)
    {
        GotoXY(head.x,head.y-i);
        {
            if(len==0)
                printf("v");
            else
                printf("*");
        }
        body[len].x=head.x;
        body[len].y=head.y-i;
        len++;
    }
    bendSnakeGame();
    if(!kbhit())
        head.y++;
}
void delayLengthSnakeGame(long double k)
{
    scoreSnakeGame();
    long double i;
    for(i=0; i<=(10000000); i++);
}
void exitSnakeGame()
{
    int i,check=0;
    for(i=4; i<length; i++) //starts with 4 because it needs minimum 4 element to touch its own body
    {
        if(body[0].x==body[i].x&&body[0].y==body[i].y)
        {
            check++;    //check's value increases as the coordinates of head is equal to any other body coordinate
        }
        if(i==length||check!=0)
            break;
    }
    if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0)
    {
        life--;
        if(life>=0)
        {
            head.x=25;
            head.y=20;
            bend_no=0;
            head.direction=RIGHT;
            moveSnakeGame();
        }
        else
        {
            system("cls");
            printf("All lives completed\nBetter Luck Next Time!!!\n");
            returnMain();
        }
    }
}
// Responsible to generate food randomly on the screen within the borders
void randomFoodSnakeGame()
{
    if(head.x==food.x&&head.y==food.y)
    {
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)

            food.y+=11;
    }
    else if(food.x==0)/*to create food for the first time coz global variable are initialized with 0*/
    {
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }
}
void leftMovementSnakeGame()
{
    int i;
    for(i=0; i<=(bend[bend_no].x-head.x)&&len<length; i++)
    {
        GotoXY((head.x+i),head.y);
        {
            if(len==0)
                printf("<");
            else
                printf("*");
        }
        body[len].x=head.x+i;
        body[len].y=head.y;
        len++;
    }
    bendSnakeGame();
    if(!kbhit())
        head.x--;

}
// Responsible for snake's right movement
void rightMovementSnakeGame()
{
    int i;
    for(i=0; i<=(head.x-bend[bend_no].x)&&len<length; i++){
        body[len].x=head.x-i;
        body[len].y=head.y;
        GotoXY(body[len].x,body[len].y);
        {
            if(len==0)
                printf(">");
            else
                printf("*");
        }
        len++;
    }
    bendSnakeGame();
    if(!kbhit())
        head.x++;
}
void bendSnakeGame()
{
    int i, j, diff;
    for(i = bend_no; i >= 0 && len < length; i--)
    {
        if(bend[i].x==bend[i-1].x)
        {
            diff =bend[i].y-bend[i-1].y;
            if(diff < 0)
                for(j = 1; j <= (-diff); j++)
                {
                    body[len].x = bend[i].x;
                    body[len].y = bend[i].y+j;
                    GotoXY(body[len].x ,body[len].y);
                    printf("*");
                    len++;
                    if(len == length)
                        break;
                }
            else if(diff > 0)
                for(j = 1; j <= diff; j++)
                {
                    body[len].x = bend[i].x;
                    body[len].y = bend[i].y-j;
                    GotoXY(body[len].x, body[len].y);
                    printf("*");
                    len++;
                    if(len == length)
                        break;
                }
        }
        else if(bend[i].y == bend[i-1].y)
        {
            diff = bend[i].x-bend[i-1].x;
            if(diff < 0)
                for(j = 1; j <= (-diff) && len < length; j++){
                    body[len].x = bend[i].x + j;
                    body[len].y = bend[i].y;
                    GotoXY(body[len].x, body[len].y);
                    printf("*");
                    len++;
                    if(len == length)
                        break;
                }
            else if(diff > 0)
                for(j = 1; j <= diff && len < length; j++){
                    body[len].x = bend[i].x - j;
                    body[len].y = bend[i].y;
                    GotoXY(body[len].x, body[len].y);
                    printf("*");
                    len++;
                    if(len == length)
                        break;
                }
        }
    }
}
// Responsible to display food within border
void borderSnakeGame()
{
    system("cls");
    int i;
    GotoXY(food.x, food.y);   
    printf("F");
    for(i = 10; i < 71; i++)
    {
        GotoXY(i, 10);
        printf("!");
        GotoXY(i, 30);
        printf("!");
    }
    for(i = 10; i < 31; i++)
    {
        GotoXY(10, i);
        printf("!");
        GotoXY(70, i);
        printf("!");
    }
}
void instructionsSnakeGame()
{
    printf("\tWelcome to the mini Snake game.(press any key to continue)\n");
    getch();
    system("cls");
    printf("\tGame instructions:\n");
    printf("\n-> Use arrow keys to move the snake.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> Here you are provided with three lives. Your life will decrease as you hit the wall or snake's body.\n\n-> YOu can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press esc. \n");
    printf("\n\nPress any key to play game.....");
    if(getch() == 27)
        exit(0);
}
// Responsible calculating Score gained
int scoreSnakeGame()
{
    int score;
    GotoXY(20, 8);
    score = length - 5;
    printf("SCORE : %d", (length - 5));
    score = length - 5;
    GotoXY(50, 8);
    printf("Life : %d", life);
    return score;
}
// Responsible for snake's up movement
void upMovementSnakeGame()
{
    int i;
    for(i = 0; i <= (bend[bend_no].y - head.y) && len < length; i++)
    {
        GotoXY(head.x, head.y+i);
        {
            if(len == 0)
                printf("^");
            else
                printf("*");
        }
        body[len].x= head.x;
        body[len].y= head.y+i;
        len++;
    }
    bendSnakeGame();
    if(!kbhit())
        head.y--;
}

void readAppointments(){
	FILE *apPtr = fopen("appointments.txt","r");
    if(apPtr == NULL)
    {
        apPtr = fopen("appointments.txt","w");
        fclose(apPtr);
        printf("\nCreating Database.....\n\n");
    }

    numberAppointment = fread(&appointmentAll, sizeof(struct appointments), 50, apPtr);

    fclose(apPtr);	
}

// This function is responsible to write to the file "clients.txt"
void writeAppointments(){
	 FILE *apPtr = fopen("appointments.txt","a+");
    if(apPtr == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(&appointmentAll, sizeof(struct appointments), numberAppointment, apPtr);

    fclose(apPtr);
}


// This function is responsible to provide accessibility to the user to book Appointments
void bookAppointments(){
	printf("\n---------------------------------------------------BOOK APPOINTMENTS---------------------------------------------------\n\n");
	printf("Enter your Name: ");
	fflush(stdin);
	gets(appointmentAll[numberAppointment].appointmentName);
	printf("Enter your Mobile Number: ");
	scanf("%lld", &appointmentAll[numberAppointment].appointmentMobile);
	fflush(stdin);
	printf("Enter Date of visit [DD/MM/YYYY] and Time [HH:MM] A.M./P.M. with space: ");
	gets(appointmentAll[numberAppointment].appointmentVisit);
	printf("\nAppointment Booked!\n");
	numberAppointment++;
	writeAppointments();

}
// This function is responsible to view all stored Appointments
void viewAppointments(){
	int i;
	printf("\n---------------------------------------------------VIEW APPOINTMENTS---------------------------------------------------\n\n");
	readAppointments();
	for(i = 0; i < numberAppointment; i++){
		printf("\nBooking Number: %d\n", i);
		printf("Name: ");
		puts(appointmentAll[i].appointmentName);
		printf("Mobile: %lld", appointmentAll[i].appointmentMobile);
		printf("\nDetails Of Visit: ");
		puts(appointmentAll[i].appointmentVisit);
		printf("______________________________________________________________\n\n");
		
	}
}

// This function is responsible for reading from the file and creating it in case it doesn't exist
void readFile( struct  clientData* stptr){
	FILE *fp = fopen("clients.bin","rb");
    if(fp == NULL)
    {
        fp = fopen("clients.bin","wb");
        fclose(fp);
        printf("File for storing Client's details does not exist. Creating.....\n\n");
    }

    numberData = fread(stptr, sizeof(struct clientData), 100, fp);
    fclose(fp);	
}

// This function is responsible to write to the file "clients.txt"
void writeFile(struct  clientData* stptr){
	 FILE *fp = fopen("clients.bin","wb+");
    if(fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(stptr, sizeof(struct clientData), numberData, fp);

    fclose(fp);
}
// This function is responsible for calling main function recursively
void returnMain(){
	char mainMenu;
	fflush(stdin);
	printf("Type 'M' or 'm' to return to the Main Menu: ");
	scanf("%c", &mainMenu);
// To return to the main menu using recursion if 'M' or 'm' is entered
	if(mainMenu == 'M' || mainMenu == 'm'){
		system("cls");
   		printf("Returning to the Main Menu.....");
   		sleep(1);
   		system("cls");
   		main();
	}
// To exit the program if invalid character is entered
	else{
		printf("Invalid character. Exiting program......");
		sleep(1);
		exit(1);
	}
}


