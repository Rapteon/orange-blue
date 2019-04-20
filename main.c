#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_font.h>
#include<unistd.h>

int Imager(char *imageFile, char *text);
void welcomeScreen();
int authenticate();
void displayChoices();
void feedbackScreen();
int main(){
	int authStat;
	char authFail = 'Y';
	char welcomeImage[] = "welcomePic.png";
	char welcomeText[] = "Welcome to theRestaurant...";
	int image = Imager(welcomeImage,welcomeText);
	welcomeScreen();
	while(authFail == 'Y'){
		authStat = authenticate();
		if(authStat == 0){
			printf("Try again?[Y/n]: ");
			scanf(" %c", &authFail);
		}
		else{
				displayChoices();
				feedbackScreen();
				authFail = 'n';
		}
	}



}
