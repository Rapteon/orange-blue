#include<stdio.h>
#include<string.h>
#include<conio.h>
char verify(char username[],char password[])
{int l=0;
char usernameo[]="user";
char passwordo[]="user";

for(int i=0;i<4;i++)
{l=0;
if((password[i]==passwordo[i])and(username[i]==usernameo[i]))
l=1;
}
if(l==1)
printf("Access granted");
else
printf("Access denied");

}
 int main()
{char username[20],password[20];
char ch;
printf("Enter the username");
scanf("%s",username);
printf("Enter the password");
for(int i=0;i<4;i++)
{
ch=getch();
password[i]=ch;
ch='*';
printf("%c",ch);
}
verify(username,password);
}
