#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "aes.c"
#include "hashing.c"
#include "salting.c"

unsigned char cipher[16];
int choice=0,q;
void display()
{printf("\n\n\n\n\n\t\t\t\t\t\t\t\t    Welcome To\t\t\t\t\t\t\t\t\t");
 printf("\n\n\n\n\t\t\t\t\t\t\tHIGH DELIVERABLE PASS-CODE SYSTEM\t\t\t\t\t\t\t");
 printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Don't worry we will secure passwords for you\t\t\t\t\t\t");
 printf("\n\n\n\n\n\n\n\n\n\n\tDeveloped By:\n\tNipun Singal\n\tMadhav Bhatia\n\tRajat Panwar\n\tIshita Bansal");
 printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tPress enter to continue......");

}




void display2()
{printf("Enter the password: ");
 scanf("%s",cipher);
 printf("\n\n\n\tPlease choose the option:");
 printf("\n\n\t1)Only encryption\n\t2)Encryption + hashing\n\t3)Triple Crypt\n\t4)Exit\n\n\tnote:It is recomended to use Triple Crypt for high security");

 while(choice!=4)
{printf("\n\n\n\tEnter your choise: ");
 scanf("%d",&choice);
 switch (choice)
{case 1:printf("\n\n\tYour password is very less secure");
        aes(cipher);
        printf("\n\n\tEncrypted message is: ");
        for(int l=0;l<16;l++)
        {
          printf("%x",cipher[l]);

        }
        break;

 case 2:printf("\tYour password is somewhat secure\n\n");
         aes(cipher);
         hashing(cipher);
         for(int m=0;m<8;m++)
         {printf("%x",h[m]);  }
         break;

 case 3:printf("\tYour password is highly secure\n\n");
         aes(cipher);
         hashing(cipher);
         salting(h);
         break;

 case 4: break;

 default: printf("invalid choice, select again");
          break;

}
}
}



void display3()
{

  while(q!=3)
  {printf("\n\n\n\n\n");
  printf("\tPlease create the account first, If not");
  printf("\n\n\n\tPlease choose the option:");
  printf("\n\n\t1)Signup\n\t2)Login\n\t3)Exit");

  printf("\n\n\tchoice: ");
  scanf("%d",&q);
  switch (q)
  {
    case 1: system("clear");
            display2();
            system("clear");
            break;

  case 2:


  case 3: system("exit");
           break;

  default: printf("invalid choice, select again");
          break;


  }

}



}





int main()
{char a;
 display();
scanf("%c",&a);
system("clear");
display3();
 return(0);}
