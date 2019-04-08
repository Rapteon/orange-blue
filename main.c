#include<stdio.h>
#include<stdlib.h>

#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_font.h>

#include "/home/suraj/Documents/cProjectDev/restaurant.h"
int Imager(char *imageFile, char *text);
void welcomeScreen();
void displayChoices();
int main(){
	char welcomeImage[] = "welcomePic.png";
	char welcomeText[] = "~~~~~~~~~~~~~~~~~";
	int finish = Imager(welcomeImage,welcomeText);
	welcomeScreen();
	displayChoices();
	
}
