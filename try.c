#include<stdio.h>
#include<windows.h>
#define ANSI_COLOR_RED   "\x1b[31m"

int main()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  WORD saved_attributes;

  /* Save current attributes */
  GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
   saved_attributes = consoleInfo.wAttributes;

   SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
   printf("This is some nice COLORFUL text, isn't it?");

   /* Restore original attributes */
   SetConsoleTextAttribute(hConsole, saved_attributes);
   printf("Back to normal");

   return 0;

}
