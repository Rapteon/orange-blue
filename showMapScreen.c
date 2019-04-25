#include<stdio.h>

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
