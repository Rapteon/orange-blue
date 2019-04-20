#include<stdio.h>
#include<string.h>

void authenticate(){
	char username[4] = "user";
	char password[4] = "user";

	char uName[4], uPass[4];

	printf("Enter username: ");
	scanf("%s", uName);

	printf("Enter password: ");
	scanf("%s", uPass);

	int uResult = strncmp(username, uName, 4);           //Comparing the stored and the input passwords/usernames.
	int pResult = strncmp(password, uPass, 4);

	if((uResult == 0)){                                  //First checking the username and then the password.
		if(pResult == 0)
			printf("Access granted :)\n");
		else
			printf("Access denied :( \n");
	}
}
/*int main(){
	authenticate();					     //comment or uncomment to test.
}*/
