#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user
{
      char phone[50];
      char ac[50];
      char password[50];
      float balance;
};
int main()
{
      struct user usr, user1;
      FILE *fp;
      char filename[50], phone[50], pword[50];
      int opt;
      float amount;
      char cont = 'y';
      int choice;
      printf("\nwhat you want to do");
      printf("\n\n1.register an account");
      printf("\n2.login to an account");

      printf("\n\nyour choice:\t");
      scanf("%d", &opt);
      if (opt == 1)
      {
            system("clsr");
            printf("enter your account no:\t");
            scanf("%s", usr.ac);
            printf("\nenter your phone number:\t");
            scanf("%s", usr.phone);
            printf("\n enter your new password:\t");
            scanf("%s", usr.password);
            usr.balance = 0;
            strcpy(filename, usr.phone);
            fp = fopen(strcat(filename, ".dat"), "w");
            fwrite(&usr, sizeof(struct user), 1, fp);
            if (fwrite != 0)
            {
                  printf("\n\n account successfully registerd");
            }
            else
            {
                  printf("\n\n something  went wrong please try again");
            }
            fclose(fp);
      }
      if (opt == 2)
      {
            system("clear");
            printf("\n phone number:\t");
            scanf("%s", phone);
            printf("\npassword:\t");
            scanf("%s", pword);
            strcpy(filename, phone);
            fp = fopen(strcat(filename, ".dat"), "r");
            if (fp == NULL)
            {
                  printf("\n account number not registerd");
            }
            else
            {

                  fread(&usr, sizeof(struct user), 1, fp);
                  fclose(fp);
                  if (!strcmp(pword, usr.password))
                  {
                        printf("\n\t welcome %s", usr.phone);
                        while (cont == 'y')
                        {
                              system("clear");
                              printf("\npress 1 for  balance  inquiry");
                              printf("\n press 2 to deposit an amount");
                              printf("\npress 3 to withdraw ");
                              printf("\npress 4 to transfer the balance");
                              printf("\n press 5 to changr password");
                              printf("\n\n your choice:\t");
                              scanf("%d", &choice);
                              switch (choice)
                              {
                              case 1:
                                    printf("\n your current balance is Rs.%.2f", usr.balance);
                                    break;

                              case 2:
                                    printf("\n enter the amount \t");
                                    scanf("%f", &amount);
                                    usr.balance += amount;
                                    fp = fopen(filename, "r");
                                    fwrite(&usr, sizeof(struct user), 1, fp);
                                    if (fwrite != NULL)
                                          printf("\nsuccessfully deposited");
                                    fclose(fp);
                                    break;

                              case 3:
                                    printf("\n enter the amount \t");
                                    scanf("%f", &amount);
                                    usr.balance -= amount;
                                    fp = fopen(filename, "r");
                                    fwrite(&usr, sizeof(struct user), 1, fp);
                                    if (fwrite != NULL)
                                          printf("\n you have withdraw Rs.%2f", amount);
                                    fclose(fp);
                                    break;
                              case 4:
                                    printf("\n please enter the phone number to transfer the money:\t");
                                    scanf("%s", &phone);
                                    printf("\n please enter the amount to transfer :\t");
                                    scanf("%f", &amount);
                                    strcpy(filename, phone);
                                    fp = fopen(strcat(filename, ".dat"), "r");

                                    if (fp == NULL)
                                    {
                                          printf("\n account number not register");
                                          return 0;
                                    }
                                    fread(&user1, sizeof(struct user), 1, fp);
                                    fclose(fp);
                                    if (amount > usr.balance)
                                          printf("\n insufficiant balance");
                                    else
                                    {
                                          strcpy(filename, phone);
                                          fp = fopen(strcat(filename, ".dat"), "r");
                                          if (fp == NULL)
                                          {
                                                printf("\nphone number not registerd");
                                                return 0;
                                          }
                                          fread(&user1, sizeof(struct user), 1, fp);
                                          fclose(fp);
                                          fp = fopen(filename, "w");
                                          user1.balance += amount;
                                          fwrite(&user1, sizeof(struct user), 1, fp);
                                          fclose(fp);
                                          if (fwrite != NULL)
                                          {
                                                printf("\nyou have successfully transfferd Rs.%2f to %s", amount, phone);
                                                strcpy(filename, usr.phone);
                                                fp = fopen(strcat(filename, ".dat"), "w");
                                                usr.balance -= amount;
                                                fwrite(&usr, sizeof(struct user), 1, fp);
                                                fclose(fp);
                                          }
                                    }
                                    break;
                              case 5:
                                    printf("\n please enter a new password:\t");
                                    scanf("%s", pword);
                                    fp = fopen(filename, "w");
                                    strcpy(usr.password, pword);
                                    fwrite(&usr, sizeof(struct user), 1, fp);
                                    if (fwrite != NULL)
                                          printf("\npassword successfully changed:\t");
                                    break;
                              default:
                                    printf("\n invalid option");

                                    printf("\n do you want to continue your transiction[y/n]");
                                    scanf("%s", &cont);
                              }
                              printf("\n do you want to continue your transiction[y/n]");
                              scanf("%s", &cont);
                        }
                  }
                  else
                  {
                        printf("\n invalid password");
                  }
            }
      }
}