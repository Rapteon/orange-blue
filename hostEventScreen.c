#include<stdio.h>
#include<stdlib.h>
void hostEventScreen();
void displayChoices();
void welcomeScreen();
void event();
void hostEventScreen(){
	int choice;	//This is used to store value for navigation.
	char exitVariable;

	printf("\n");

	//Printing stuff
	printf("\t------------------------------------------\n");
	printf("\t|                EVENTS                   |\n");
	printf("\t|                                         |\n");
	printf("\t| Hosting an event is a difficult job,    |\n");
	printf("\t| but we are here to make it easy.        |\n");
	printf("\t| A party, a marriage or a formal dinner, |\n");
	printf("\t| host your event at our restaurant, the  |\n");
	printf("\t| way you want.*                          |\n");
	printf("\t|                                         |\n");
	printf("\t| For more details,                       |\n");
	printf("\t|  Contact Us: 1234567890	          |\n");
	printf("\t|  email: therestaurant@gmail.com	  |\n");
	printf("\t------------------------------------------\n");
	printf("\n\n");
	printf("*terms & conditions apply.\n\n");
	event();


	//Navigation code
	printf("Navigation:\n");
	printf("1.Back\t2.Quit\n");
	fflush(stdin);
	scanf("%d", &choice);

	switch(choice){
		case 1: displayChoices();				//eventSelectionScreen();
						break;
		case 2: printf("Are you sure you want to exit?[Y/n]: ");
						scanf(" %c", &exitVariable);
						if(exitVariable == 'Y'|| exitVariable == 'y')
							exit(0);
	}

}


/*int main(){
	hostEventScreen();

}*/
