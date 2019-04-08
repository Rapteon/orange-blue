#include<stdio.h>
#include<stdlib.h>
//#include<restaurant.h>
void hostEventScreen();

void displayChoices(){
    int choice, status = 1;
    while(status == 1){
        printf("Please select an option from below:\n\n");
        printf("1. dine-out : for a casual dining experience...\n");
        printf("2. Host an Event: parties | birthdays | weddings etc.\n");
        printf("3. Cancel :\(\n");
        scanf("%d", &choice);
	
        switch(choice){
            case 1: //tableSelection();
                    status = 0;
                    break;
            case 2: //hostEvent();
                    status = 0;
		    hostEventScreen();
                    break;
            case 3: exit(0);
                    break;
        }
    }
}

