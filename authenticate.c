#include<stdio.h>
#include<string.h>

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
/*int main(){
	authenticate();					     //comment or uncomment to test.
}*/
