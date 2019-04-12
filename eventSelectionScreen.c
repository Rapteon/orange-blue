#include<stdio.h>
#include<stdlib.h>
void event_selection_description();     /* Function declaration */
void a_la_carte();
void event();
void bill();
void event_selection_description()
{
    int i;
	printf("\n Please choose one of the following :");
	printf("\n 1) a la carte    \t   2) PARTY / WEDDING  \n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
			printf("\n You've chosen a la carte ,good choice ");
			a_la_carte();
			break;
		case 2:
			printf("\n Events ");
			event();
			break;
		default:
			printf("\n Please enter a valid option number like 1 or 2 .\n Any other option is invalid.\n");
	}
}
void a_la_carte()
{
	int t_no;
	char s[100]; /*this is a string */
	printf("\n Please enter the number of guests (including yourself as well) : \n");
	scanf("%d",&t_no);
	printf("\n Thank you.\n We'll book a table for %d people \n",t_no);
	printf("\n Now this is the menu : \n");
	printf("\n ******MENU****** \n");
	printf("\n 1)");/*starters drinks main course dessert */
	printf("\n what would you like to order ? ");
	scanf("%s",s);
	printf("\n Great choice.\n Your order will be ready and served in 20 minutes  \n");
	printf("\n time to pay up \n");
}
void event()
{
	int i,j=0;
	char s[100];
	printf("\n Please choose the event .\n 1) Wedding\t\t\t\t\t2)Party\n");
	while(j==0)
	{
	scanf("%d",&i);
	  if(i==1)
	  printf("\n Congratulations on the wedding !!!! \n");
	  else if(i==2)
	  printf("\n Time to party!!!!! \n");
	  else
	  {
	  printf("\n Invalid entry .\n Please try again .\n");
      continue;
      }
    }
}

void main()                                /* starting point of program */
{
	printf("\n Welcome ");
	event_selection_description();
}
