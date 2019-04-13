#include<stdio.h>
#include<stdlib.h>
void thankYouScreen();
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

/*int main(){
	feedback();
}*/
