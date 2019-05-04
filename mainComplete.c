//Project: Hotel Management System
/*Group Members:
	Name											PRN
	Raghav Gaur							18070124054
	Saha Nakul Amitabh			18070124062
	Tanvi Pathak						18070124072
	Suraj Prasanth Naranatt	18070124071
*/



/*README:::::::: This code was written as multiple files and compiled and run on a linux system.
	::::::::::			The following functions may not work on a windows system:
	:::::::					1. void wait();
	::::::					2. int Imager(char *imageFile, char *text);
	::::::					3.
*/

#include<stdio.h>
#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_font.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

void a_la_carte();
void hostEventScreen();
void event();

int k, itemCount = 0, l = 0, paymentMethod, cvvNumber;
char billChoice;
char cardNumber[16], upiID[50];
char* bill[9];
float amount = 0;
//cost of entree
float ecost[] ={100.0,125.0,75.0,80.0,125.0,175.0,235.0,145.0,250.0};
char* ename[] ={"dumplings","cottage_cheese_fritters","fried_babycorn","lettuce_wraps","rodeo_nachos","mozarella_sticks","chicken_and_mozarella sticks","potato_fingers","pita_bread_and_hummus"};

//cost of maincourse
float mcost[] ={355.0,200.0,300.0,275.0,490.0,349.0,299.0,489.0,599.0};
char* mname[] ={"fried_salmon_with_asparagus","alfredo_gnocchi","vegetable_lasagna","pasta_arrabiata","naan_pizza","baked_cottage_cheese_and_brocolli","pesto_sphagetti","vegtarian_palette","non_vegtarian_palette"};

//cost of dessert
float dcost[] ={299.0,189.0,349.0,278.0,329.0,169.0,220.0,311.1,279.2};
char* dname[] ={"classic newyork style baked cheesecake","baked blueberry cheesecake","vegan mousse","creme brulee","sizzling brownie","butterscotch sundae","tiramisu","banoffee_pie","red_velvet_lava_cupcake"};

void wait(float duration){
	time_t start, end;
	double elapsed;  // seconds
	start = time(NULL);
	int terminate = 1;
	while (terminate) {
		end = time(NULL);
		elapsed = difftime(end, start);
		if (elapsed >= duration /* seconds */)
			terminate = 0;
		else  // No need to sleep when 90.0 seconds elapsed.
			usleep(duration*1000000);
	}
}

/*Function to draw an image. This takes in two character arrays as formal parameters
The first character array is the name of the image file to display(.png format),
and the second parameter is the array which contains the text to show.*/
/*                this|     and this|*/
int Imager(char *imageFile, char *text){
	if(!al_init()){
        printf("Could not initialize allegro.\n");
        return 1;
    }
    if(!al_install_keyboard()){
        printf("Could not initialize keyboard.\n");
        return 1;
    }
    ALLEGRO_TIMER* timer = al_create_timer(1.0/30.0);
    if(!timer){
        printf("Could not initialize timer.\n");
        return 1;
    }
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    if(!queue){
        printf("Could not initialize queue.\n");
        return 1;
    }
    ALLEGRO_DISPLAY* disp = al_create_display(1366,768);
    if(!disp){
        printf("Could not initialize display.\n");
        return 1;
    }
    ALLEGRO_FONT* font = al_create_builtin_font();
    if(!font){
        printf("Could not initialize font.\n");
        return 1;
    }

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;

    ALLEGRO_EVENT event;
    al_start_timer(timer);

    if(!al_init_image_addon()){
        printf("Could not initialize image addon");
        return 1;
    }
    ALLEGRO_BITMAP* image = al_load_bitmap(imageFile);
    if(!image){
        printf("Could not load image");
        return 1;
    }

    while(1)
    {
        al_wait_for_event(queue,&event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                //Any logic if required.
                redraw = true;
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
                done = true;
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }
        if(done)
            break;
        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(244,67,54));
            al_draw_text(font, al_map_rgb(255,235,59), 120, 0, 0, text);
            al_draw_bitmap(image, 100, 100, 0);
            al_flip_display();

            redraw = false;
        }
    }
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_destroy_bitmap(image);

    return 0;
}

int authenticate(){
	int authStat = 0;
	char username[] = "user";
	char password[] = "user";

	char uName[32], uPass[32];

	printf("Enter username: ");
	scanf("%s", uName);

	printf("Enter password: ");
	scanf("%s", uPass);

	int uResult = strncmp(username, uName, 4);           //Comparing the stored and the input passwords/usernames.
	int pResult = strncmp(password, uPass, 4);

	if((uResult == 0)){                                  //First checking the username and then the password.
		if(pResult == 0){
			printf("Access granted :)\n");
			authStat = 1;
		}
		else
			printf("Access denied :( \n");
	}

	return authStat;
}

void welcomeScreen(){


	printf("WWWWWWWW                           WWWWWWWW               lllllll                                                                                  \n");
	printf("W::::::W                           W::::::W               l:::::l                                                                                  \n");
	printf("W::::::W                           W::::::W               l:::::l                                                                                  \n");
	printf("W::::::W                           W::::::W               l:::::l                                                                                  \n");
	printf(" W:::::W           WWWWW           W:::::W eeeeeeeeeeee    l::::l     cccccccccccccccc   ooooooooooo      mmmmmmm    mmmmmmm       eeeeeeeeeeee    \n");
	printf("  W:::::W         W:::::W         W:::::Wee::::::::::::ee  l::::l   cc:::::::::::::::c oo:::::::::::oo  mm:::::::m  m:::::::mm   ee::::::::::::ee  \n");
	printf("   W:::::W       W:::::::W       W:::::We::::::eeeee:::::eel::::l  c:::::::::::::::::co:::::::::::::::om::::::::::mm::::::::::m e::::::eeeee:::::ee\n");
	printf("    W:::::W     W:::::::::W     W:::::We::::::e     e:::::el::::l c:::::::cccccc:::::co:::::ooooo:::::om::::::::::::::::::::::me::::::e     e:::::e\n");
	printf("     W:::::W   W:::::W:::::W   W:::::W e:::::::eeeee::::::el::::l c::::::c     ccccccco::::o     o::::om:::::mmm::::::mmm:::::me:::::::eeeee::::::e\n");
	printf("      W:::::W W:::::W W:::::W W:::::W  e:::::::::::::::::e l::::l c:::::c             o::::o     o::::om::::m   m::::m   m::::me:::::::::::::::::e \n");
	printf("       W:::::W:::::W   W:::::W:::::W   e::::::eeeeeeeeeee  l::::l c:::::c             o::::o     o::::om::::m   m::::m   m::::me::::::eeeeeeeeeee  \n");
	printf("        W:::::::::W     W:::::::::W    e:::::::e           l::::l c::::::c     ccccccco::::o     o::::om::::m   m::::m   m::::me:::::::e           \n");
	printf("         W:::::::W       W:::::::W     e::::::::e         l::::::lc:::::::cccccc:::::co:::::ooooo:::::om::::m   m::::m   m::::me::::::::e          \n");
	printf("          W:::::W         W:::::W       e::::::::eeeeeeee l::::::l c:::::::::::::::::co:::::::::::::::om::::m   m::::m   m::::m e::::::::eeeeeeee  \n");
	printf("           W:::W           W:::W         ee:::::::::::::e l::::::l  cc:::::::::::::::c oo:::::::::::oo m::::m   m::::m   m::::m  ee:::::::::::::e  \n");
	printf("            WWW             WWW            eeeeeeeeeeeeee llllllll    cccccccccccccccc   ooooooooooo   mmmmmm   mmmmmm   mmmmmm    eeeeeeeeeeeeee  \n");

	printf("________________________to the restaurant.\n");
 }

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
                    a_la_carte();
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

void event()
{
	int i,j=0;
	char s[100];
	char phone[10];
	printf("\n Please choose the event .\n 1) Wedding\t\t\t\t\t2)Party\n");

	while(j==0){
	scanf("%d",&i);
	  if(i==1){
			printf("\n Congratulations for the wedding !!!! \n");
			printf("Please entre your phone number and our team will contact you...\n");
			scanf("%s", phone);
			j = 1;
		}

	  else if(i==2){
			printf("\n Time to party!!!!! \n");
			printf("Please enter your phone number and our team will contact you...\n");
			scanf("%s", phone);
			j = 1;
		}

	  else
	  {
	  printf("\n Invalid entry .\n Please try again .\n");
      j = 0;
      }
    }
}

void showMap(){
      int zone, floor;

      printf("Which floor would you like to be on?\n ");
      printf("1 Ground\n ");
      printf("2 Halls\n ");
      printf("3 Terrace\n");
      scanf("%d", &floor);
      switch(floor){
        case 1:   printf("              |````````````````````|````````````````````````````````````````````````````````````````````|         N         \n");
                  printf("              |                    |                                                                    |         ^         \n");
                  printf("              |                    |                                                                    |       --|--       \n");
                  printf("              |                    |                                                                    |         |         \n");
                  printf("              |                 1  |                    Pool Side                                       |\n");
                  printf("              |                    |                                                                    |\n");
                  printf("              |                    |                                                                    |\n");
                  printf("              |                    |                                                                    |\n");
                  printf("              |                    |                                                                    |\n");
                  printf("              |                    |____________________________________________________________________|\n");
                  printf("              |                                                           |                             |\n");
                  printf("              |                                                 2         |              4              |\n");
                  printf("              |                                                           |                             |\n");
                  printf("              |```````````````````````````````|                           |         Game Zone           |\n");
                  printf("              |                              |                            |                             |\n");
                  printf("              |                             |                             |                             |\n");
                  printf("              |                            |                              |___________________________  |\n");
                  printf("              |            3              |                                                             |\n");
                  printf("              |                          |                                                              |\n");
                  printf("              |         Lounge          |                                                               |\n");
                  printf("              |                        |                                                                |\n");
                  printf("              |                        |                                                                |\n");
                  printf("              |                        |                                                                |\n");
                  printf("              |_________________________________________________________________________________________|\n\n");

                  printf("Select your zone: ");
                  scanf("%d", &zone);
                  if(zone>4 || zone < 1){
                    printf("Invalid Zone. :/\n");
                    printf("Autoselecting available zone...\n");
                  }
                  break;
          case 2:
                  printf("              |````````````````````````````````````````````|````````````````````````````````````````````|         N         \n");
                  printf("              |                                            |                                            |         ^         \n");
                  printf("              |                                            |                                            |       --|--       \n");
                  printf("              |                                            |                                            |         |         \n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                  1                         |                        2                   |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |______  _____________  ___________________  |_________  ______________  _______________  |\n");
                  printf("              |                                                                                         |\n");
                  printf("              |                                                                                         |\n");
                  printf("              |                                                                                         |\n");
                  printf("              |_________________________________________________________________________________________|\n\n");

                  printf("Select your zone: ");
                  scanf("%d", &zone);
                  if(zone>2 || zone < 1){
                    printf("Invalid Zone. :/\n");
                    printf("Autoselecting available zone...\n");
                  }
                  break;

          case 3: printf("              |````````````````````|```````````````````````|````````````````````````````````````````````|         N         \n");
                  printf("              |                    |                       |                                            |         ^         \n");
                  printf("              |                    |                       |                                            |       --|--       \n");
                  printf("              |          1         |          2            |                                            |         |         \n");
                  printf("              |                    |                       |                                            |\n");
                  printf("              |                    |                       |                                            |\n");
                  printf("              |__   _______________|____________________   |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                        4                   |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                                            |\n");
                  printf("              |                                            |                         |``````````````````|\n");
                  printf("              |``````````````````````|                     |                        /                   |\n");
                  printf("              |                      |                     |                       /                    |\n");
                  printf("              |                      |                     |                      |                     |\n");
                  printf("              |                      |___________________  |_________   __________|                     |\n");
                  printf("              |           3                                    |                         5              |\n");
                  printf("              |                                                |                                        |\n");
                  printf("              |                                                |                                        |\n");
                  printf("              |________________________________________________|________________________________________|\n\n");

                  printf("Select your zone: ");
                  scanf("%d", &zone);
                  if(zone>5 || zone < 1){
                    printf("Invalid Zone. :/\n");
                    printf("Autoselecting available zone...\n");
                  }
                  break;
					}
}

void printEntree(){
	printf(" Entree~~~~~\n\n");
	printf(" Item  - > Price\n\n");
	for(int m = 0;  m < 9 ; m++){
		printf(" %d\t%s\t\t%f\n",m+1,  ename[m], ecost[m]);
	}
}

void printMainCourse(){
	printf(" Main Course~~~~~\n\n");
	printf(" Item  - > Price\n\n");

	for(int m = 0;  m < 9 ; m++)
	printf(" %d\t%s\t\t%f\n",m+1,  mname[m], mcost[m]);
}

void printDessert(){
	printf(" Something sweet?~~~~~\n\n");
	printf(" Item  - > Price\n\n");

	for(int m = 0;  m < 9 ; m++)
	printf(" %d\t%s\t\t%f\n",m+1,  dname[m], dcost[m]);
}

void itemMenu(){

		wait(2.0);
		int k;
		int i, n,j, coe[9],com[9],cod[9],choice=1,co=1;

		do{
			printf("\x1b[H\x1b[J");
	     choice=1;


			printf("\t\t\t********************MENU********************************\n\n");
	 		printf("\t\t\t*     Choose one of the 3 meal course:                 *\n");
	 		printf("\t\t\t*     1. Entree                                        *\n");
	 		printf("\t\t\t*     2. mainCourse                                    *\n");
	 		printf("\t\t\t*     3. Dessert                                       *\n");
	 		//printf("\t\t\t* 1.Entree\n\t\t\t* 2.Main Course\n\t\t\t* 3.Dessert\n");
	 		printf("\t\t\t********************************************************\n\n");
	 		printf("Select your choice: ");
	 		scanf("%d",&n);


			///               the code for entree              //

		if(n==1){

			printEntree();
			for(i=0;choice==1;i++){
				printf(" Enter your choice of dish :\n");
				scanf("%d",&coe[i]);
				printf(" To enter more dishes type 1 else type 0 \n");
				scanf("%d",&choice);
			}

		printf("you have chosen: \n");
		for(j=0;j<i;j++){
		    k=coe[j];
				amount += ecost[k-1];
				l++;
				bill[l] = ename[k-1];
			printf("%s \n",ename[k-1]);

		}
		itemCount += i;
	}

		/////               code for main                  ///
		else if(n==2){

			printMainCourse();
			for(i=0;choice==1;i++){
				printf(" Enter your choice of dish :\n");
				scanf("%d",&com[i]);
				printf(" To enter more dishes type 1 else type 0 \n");
				scanf("%d",&choice);
					}

		printf("You have chosen: \n");
		for(j=0;j<i;j++){
		    k=com[j];
				amount += mcost[k-1];
				l++;
				bill[l] = mname[k-1];
			printf("%s \n",mname[k-1]);

		}
		itemCount += i;
	}


		/////               code for dessert                ///
		else if(n==3){

			printDessert();
			for(i=0;choice==1;i++){
				printf(" Enter your choice of dish :\n");
				scanf("%d",&cod[i]);
				printf(" To enter more dishes type 1 else type 0 \n");
				scanf("%d",&choice);
					}

		printf("You have chosen: \n");
		for(j=0;j<i;j++){
		    k=cod[j];
				amount += dcost[k-1];
				l++;
				bill[l] = dname[k-1];
			printf("%s \n",dname[k-1]);

		}
		itemCount += i;
	}
		else
		{
		printf("Wrong entry");
		}
	printf("Cost: %f\n\n", amount);
	printf("Number of items is %d\n", itemCount);
	printf("Would you like to continue ordering? If yes, enter 1, else enter 0 ");
	scanf("%d",&co);


	}
	while(co==1);
	printf("\n Great choice.\n Your order will be ready and served in 20 minutes  \n");
	wait(2.0);

	printf("Would you like to see your bill now?[Y/n]: ");
	scanf(" %c", &billChoice);
	if(billChoice == 'Y'|| billChoice == 'y'){
		printf("We are preparing your bill.\n");
		printf("Please wait...\n\n");
		wait(2.0);
		printf("\t\t\t***************************BILL*************************\n\n");
		for(i=1; i<=l; i++)
			printf("\t\t\t%d\t%s\n", i, bill[i]);
		printf("\t\t\tTotal =  %f\n", amount);
		printf("\t\t\tPayment methods:\n");
		printf("\t\t\t1 Credit Card\n");
		printf("\t\t\t2 UPI\n");

		scanf("\t\t\t%d", &paymentMethod);

		switch(paymentMethod){
			case 1: printf("Enter Card Number: ");
							scanf("%s", cardNumber);
							printf("Enter CVV: ");
							scanf("%d", &cvvNumber);
							printf("Processing your payment...");
							wait(2.0);
							printf("Transaction successful.\n\n\n");
							break;
			case 2: printf("Enter UPI ID: ");
							scanf("%s", upiID);
							printf("Please accept the request for fund transfer...");
							wait(2.0);
							printf("Transaction successful.\n\n\n");
		}
		wait(3.0);
	}
	else
		wait(2.0);
}

void a_la_carte()
{
	int t_no;
	char s[100]; /*this is a string */
	printf("\n Please enter the number of guests (including yourself as well) : \n ");
	scanf("%d",&t_no);

	showMap();

	printf("\n Thank you.\n We'll book a table for %d people \n",t_no);
	printf("\n Now this is the menu : \n");
	//printf("\n ******MENU****** \n");
	itemMenu();
	//printf("\n 1)");/*starters drinks main course dessert */

	//printf("\n what would you like to order ? ");
	//scanf("%s",s);
	//printf("\n Great choice.\n Your order will be ready and served in 20 minutes  \n");

	//printf("Your bill is %f: ", amount);
	//printf("\n time to pay up \n");
}

void thankYouScreen(){

			printf("888   888                     888                              \n");
			printf("888   888                     888                              \n");
			printf("888   888                     888                              \n");
			printf("88888888888b.  8888b. 88888b. 888  888888  888 .d88b. 888  888 \n");
			printf("888   888 \"88b    \"88b888 \"88b888 .88P888  888d88""88b888    888 \n");
			printf("888   888  888.d888888888  888888888K 888  888888  888888  888 \n");
			printf("Y88b. 888  888888  888888  888888 \"88bY88b 888Y88..88PY88b 888 \n");
			printf(" \"Y888888  888\"Y888888888  888888  888 \"Y88888 \"Y88P\"  \"Y88888 \n");
			printf("                                           888                 \n");
			printf("                                      Y8b d88P                 \n");
			printf("                                       \"Y88P\"           \n");


				printf("Hope you will visit us again !\n");
}

void feedbackScreen(){
	int feedback[2];
	int sum = 0;
	char recommendations[140];
	int averageOpinion = 0;

	printf("+++++++++++++++++++>>>\n");
	printf(" Before you go ...\n\n");
	printf("	      _`_- \n");
	printf("     , |`----`|\n");
	printf("    (( |      |\n");
	printf("     |_|      |\n");
	printf("       |      |\n");
	printf("       '------'\n");


	printf("Please rate us on a scale of 1 to 9 :)\n");
	printf("                                       \n");
	printf("1-------->----------5-------->-------9\n\n");
	printf(":(                  :|               :)\n");
	printf("\n---------------------------------------\n");

	printf("How would you rate our food?\n");
	scanf("%d", &feedback[0]);
	printf("\n");

	printf("How would you rate the ambience of our place?\n");
	scanf("%d", &feedback[1]);

	fflush(stdin);
	printf("\n\n\n");
	printf("Would you like to give some recommendations to improve our service?\n");
	scanf("%s", recommendations);
	printf("\n");

	for(int i = 0 ;i < 2; i++)
		averageOpinion = averageOpinion + feedback[i];
	//printf("%d", averageOpinion);

	printf("\n\n");
	thankYouScreen();

}


 //Main function begins here...
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
