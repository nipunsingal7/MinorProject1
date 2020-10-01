#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char cipher[16];
int choice=0;
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
 printf("\n\n\t1)Only encryption\n\t2)Encryption + Hashing\n\t3)Triple Crypt\n\t4)Exit\n\n\tnote:It is recomended to use Triple Crypt for high security");
 
 while(choice!=4)
{printf("\n\n\n\tEnter your choise: ");
 scanf("%d",&choice);
 switch (choice)
{case 1:printf("\tYour password is very less secure");
        break;
 case 2:printf("\tYour password is somewhat secure");
         break;
 case 3:printf("\tYour password is highly secure");
         break;
 case 4: exit(0);  
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
display2();
 return(0);}
