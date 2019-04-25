#include<stdio.h>
#include<stdlib.h>
void wait(float duration);
//cost of entree
int k, itemCount = 0, l = 0, paymentMethod, cvvNumber;
char billChoice;
char cardNumber[16], upiID[50];
char* bill[9];
float amount = 0;
float ecost[] ={100.0,125.0,75.0,80.0,125.0,175.0,235.0,145.0,250.0};
char* ename[] ={"dumplings","cottage_cheese_fritters","fried_babycorn","lettuce_wraps","rodeo_nachos","mozarella_sticks","chicken_and_mozarella sticks","potato_fingers","pita_bread_and_hummus"};

//cost of maincourse
float mcost[] ={355.0,200.0,300.0,275.0,490.0,349.0,299.0,489.0,599.0};
char* mname[] ={"fried_salmon_with_asparagus","alfredo_gnocchi","vegetable_lasagna","pasta_arrabiata","naan_pizza","baked_cottage_cheese_and_brocolli","pesto_sphagetti","vegtarian_palette","non_vegtarian_palette"};

//cost of dessert
float dcost[] ={299.0,189.0,349.0,278.0,329.0,169.0,220.0,311.1,279.2};
char* dname[] ={"classic newyork style baked cheesecake","baked blueberry cheesecake","vegan mousse","creme brulee","sizzling brownie","butterscotch sundae","tiramisu","banoffee_pie","red_velvet_lava_cupcake"};

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
