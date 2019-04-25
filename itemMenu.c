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
		/*int ecost[] ={1,2,3,4,5,6,7,8,9};//cost of entree

		char* ename[] ={"dumplings","cottage_cheese_fritters","fried_babycorn","lettuce_wraps","rodeo_nachos","mozarella_sticks","chicken_and_mozarella sticks","potato_fingers","pita_bread_and_hummus"};*/

		/*int ecost[] ={1,2,3,4,5,6,7,8,9};//cost of entree

		char* ename[] ={"dumplings","cottage_cheese_fritters","fried_babycorn","lettuce_wraps","rodeo_nachos","mozarella_sticks","chicken_and_mozarella sticks","potato_fingers","pita_bread_and_hummus"};*/
	    //int k;


	    /*int mcost[] ={1,2,3,4,5,6,7,8,9};//cost of main
		//below is the name of main
		char* mname[] ={"fried_salmon_with_asparagus","alfredo_gnocchi","vegetable_lasagna","pasta_arrabiata","naan_pizza","baked_cottage_cheese_and_brocolli","pesto_sphagetti","vegtarian_palette","non_vegtarian_palette"};*/



	   /*int dcost[] ={1,2,3,4,5,6,7,8,9};//cost of dessert
		//below is the name of dessert
		char* dname[] ={"classic newyork style baked cheesecake","baked blueberry cheesecake","vegan mousse","creme brulee","sizzling brownie","butterscotch sundae","tiramisu","banoffee_pie","red_velvet_lava_cupcake"};*/

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
			/*printf (" 1.dumplings  \n 2.cottage cheese fritters	\n 3.fried babycorn\n");
			printf (" 4.lettuce wraps\n 5.rodeo nachos\n 6.mozarella sticks\n 7.chicken and mozarella sticks\n 8.potato fingers\n 9.pita bread and hummus\n");*/
			printEntree();
			for(i=0;choice==1;i++){
				printf(" enter your choice of dish :\n");
				scanf("%d",&coe[i]);
				printf(" to enter more dishes type '1' else type '0' \n");
				scanf("%d",&choice);
			}

		/*int ecost[] ={1,2,3,4,5,6,7,8,9};//cost of entree

		char* ename[] ={"dumplings","cottage_cheese_fritters","fried_babycorn","lettuce_wraps","rodeo_nachos","mozarella_sticks","chicken_and_mozarella sticks","potato_fingers","pita_bread_and_hummus"};*/
	    //int k;

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
			/*printf (" 1.dumings \n 2.mainfritters\n 3.babycorn\n");
			printf (" 4.lettuce wraps\n 5.rodeo nachos\n 6.mozarella sticks\n 7.chicken and mozarella sticks\n 8.potato fingers\n 9.pita bread and hummus\n");*/
			printMainCourse();
			for(i=0;choice==1;i++){
				printf(" enter your choice of dish :\n");
				scanf("%d",&com[i]);
				printf(" to enter more dishes type '1' else type '0' \n");
				scanf("%d",&choice);
					}

		printf("you have chosen: \n");
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
			/*printf (" 1.dumplings \n 2.cottagetters\n 3.fried icecream\n");
			printf (" 4.lettuce wraps\n 5.rodeo nachos\n 6.mozarella sticks\n 7.chicken and mozarella sticks\n 8.potato fingers\n 9.pita bread and hummus\n");*/
			printDessert();
			for(i=0;choice==1;i++){
				printf(" enter your choice of dish :\n");
				scanf("%d",&cod[i]);
				printf(" to enter more dishes type '1' else type '0' \n");
				scanf("%d",&choice);
					}

		printf("you have chosen: \n");
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
	printf("would you like to continue ordering? if yes enter 1 if no enter 0 ");
	scanf("%d",&co);


	}
	while(co==1);
	printf("\n Great choice.\n Your order will be ready and served in 20 minutes  \n");
	wait(2.0);

	printf("Would you like to see your bill?[Y/n]: ");
	scanf(" %c", &billChoice);
	if(billChoice == 'Y'|| billChoice == 'y'){
		printf("We are preparing your bill.\n");
		printf("Please wait...\n");

		printf("\t\t\t***************************MENU*************************\n\n");
		for(i=1; i<=l; i++)
			printf("\t\t\t%d\t%s\n", i, bill[i]);
		printf("\t\t\tTotal =  %f\n", amount);
		printf("Payment methods:\n");
		printf("1 Credit Card\n");
		printf("2 UPI\n");

		scanf("%d", &paymentMethod);

		switch(paymentMethod){
			case 1: printf("Enter Card Number: ");
							scanf("%s", cardNumber);
							printf("Enter CVV: ");
							scanf("%d", &cvvNumber);
							printf("Processing your payment...");
							wait(2.0);
							printf("Transaction successful.\n");
							break;
			case 2: printf("Enter UPI ID: ");
							scanf("%s", upiID);
							printf("Please the request for fund transfer...");
							wait(2.0);
							printf("Transaction successful.\n");
		}

	}

}

/*int main(){

itemMenu();
}*/
/*
int i, n,j, coe[9],com[9],cod[9],choice=1,co=1;
do{
     choice=1;


	printf("                                   You are now in the menu section.        \n\n");
	printf("                                   Choose one of the 3 meal course         \n");
	printf(" 1.Entree \n 2.Main Course \n 3.Dessert\n");
	printf(" enter your choice in integer");
	printf("\n\n");
	scanf("%d",&n);


	///               the code for entree              //

	if(n==1){
		printf (" 1.dumplings  \n 2.cottage cheese fritters	\n 3.fried babycorn\n");
		printf (" 4.lettuce wraps\n 5.rodeo nachos\n 6.mozarella sticks\n 7.chicken and mozarella sticks\n 8.potato fingers\n 9.pita bread and hummus\n");
		for(i=0;choice==1;i++){
			printf(" enter your choice of dish :\n");
			scanf("%d",&coe[i]);
			printf(" to enter more dishes type '1' else type '0' \n");
			scanf("%d",&choice);
				}

	printf("you have chosen: \n");
	for(j=0;j<i;j++){
	    k=coe[j];
		printf("%s \n",ename[k-1]);

	}

}

	/////               code for main                  ///
	else if(n==2){
		printf (" 1.fried_salmon_with_asparagus \n 2.alfredo_gnocchi\n 3.vegetable_lasagna\n");
		printf (" 4.pasta_arrabiata\n 5.naan_pizza\n 6.baked_cottage_cheese_and_brocolli\n 7.pesto_sphagetti\n 8.vegtarian_palette\n\n 9.non_vegtarian_palette\n\n");
		for(i=0;choice==1;i++){
			printf(" enter your choice of dish :\n");
			scanf("%d",&com[i]);
			printf(" to enter more dishes type '1' else type '0' \n");
			scanf("%d",&choice);
				}

	printf("you have chosen: \n");
	for(j=0;j<i;j++){
	    k=com[j];
		printf("%s \n",mname[k-1]);
	}
}


/////               code for dessert                ///
	else{
		printf (" 1.classic new york style baked cheesecake \n 2.baked blueberry cheesecake\n 3.vegan chocolate avocado mousse\n");
		printf (" 4.creme brulee\n 5.sizzling brownie with icecream and hot chocolate sauce\n 6.butterscotch sundae\n 7.tiramisu\n 8.banoffee pie\n 9.red velvet lava cupcake\n");
		for(i=0;choice==1;i++){
			printf(" enter your choice of dish :\n");
			scanf("%d",&cod[i]);
			printf(" to enter more dishes type '1' else type '0' \n");
			scanf("%d",&choice);
				}

	printf("you have chosen: \n");
	for(j=0;j<i;j++){
	    k=cod[j];
		printf("%s \n",dname[k-1]);
	}
}




	printf("would you like to continue ordering? if yes enter 1 if no enter 0 ");
	scanf("%d",&co);


}
	while(co==1);
*/

//(bruschettas,fried onion rings, springrolls with coleslaw & pasta salad with mushrooms/cottage cheese)
//(chicken bruschettas,fried onion rings,meat springrolls with coleslaw & prawn/meatball pasta salad)
