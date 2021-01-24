#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "aes.c"
#include "hashing.c"
#include "salting.c"
#include "login.c"

unsigned char cipher1[16];
unsigned char cipher2[16];
int q=0;
unsigned char testname[20];
unsigned char name[20];


void display()
{printf("\n\n\n\n\n\t\t\t\t\t\t\t\t    Welcome To\t\t\t\t\t\t\t\t\t");
 printf("\n\n\n\n\t\t\t\t\t\t\tHIGH DELIVERABLE PASS-CODE SYSTEM\t\t\t\t\t\t\t");
 printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Don't worry we will secure passwords for you\t\t\t\t\t\t");
 printf("\n\n\n\n\n\n\n\n\n\n\n\n\tDeveloped By:\n\tNipun Singal");
 printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tPress enter to continue......");

}

int check()
{ int cnt=0;
  FILE *fp0=fopen("name.txt","r");
  memset(name,'\0',sizeof(name));
  printf("Enter the UserName: ");
  scanf("%s",&name);
 
 if(!((int)name[0]>=65 && (int)name[0]<=90 || (int)name[0]>=97 && (int)name[0]<=122 ) )
	   { printf("username can only contain numbers and letters and underscore sign. Username cannot start with special character\n\n");
      check();
       cnt=1;
       break;}
    
    if(cnt==1)
    {return(0);}

 
 for(int u=0;u<strlen(name);u++)
{   int ab=(int)name[u];
   
    if(!(ab>=65 && ab<=90 || ab>=97 && ab<=122 || ab>=48 && ab<=57 || ab==95) )
    { printf("username can only contain numbers and letters and underscore sign. Username cannot start with special character\n\n");
      check();
       cnt=1;
       break;}
    

}
   
    if(cnt==1)
    {return(0);}

   while(!feof(fp0))
  {
     fscanf(fp0,"%s",&testname);
     if(strcasecmp(testname,name)==0)
     {printf("username already taken\n\n");
       fclose(fp0);
       check();
      break;}


   }

 return 0;
}


void display2()
{
 int choice=0;

check();

printf("\nEnter the password: ");
 scanf("%s",&cipher1);
 printf("\n\n\n\tPlease choose the option:");
 printf("\n\n\t1)Only encryption\n\t2)Encryption + hashing\n\t3)Triple Crypt\n\t4)Exit\n\n\tnote:It is recomended to use Triple Crypt for high security");



 while(choice!=4)
{memset(cipher2, '\0',sizeof(cipher2));
 strcpy(cipher2,cipher1);

 printf("\n\n\n\tEnter your choise: ");
 scanf("%d",&choice);
 switch (choice)
{case 1:printf("\n\n\tYour password is very less secure");
        aes(cipher2);
        printf("\n\n\tEncrypted message is: ");
        for(int l=0;l<16;l++)
        {
          printf("%x",cipher2[l]);

        }

        break;

 case 2:printf("\tYour password is somewhat secure\n\n");
         aes(cipher2);
         hashing(cipher2);
         for(int m=0;m<8;m++)
         {printf("%x",h[m]);  }
         break;

 case 3:printf("\tYour password is highly secure\n\n");

          FILE *kp=fopen("name.txt","a+");

             fseek(kp,0,SEEK_END);

              if(ftell(kp)!=0)
             {fprintf(kp,"\n");}

           for(int c=0;c<strlen(name);c++)
           {fprintf(kp,"%c",name[c]);}


            fclose(kp);

         aes(cipher2);
         hashing(cipher2);
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

  case 2:  system("clear");
            login();
            system("clear");
            break;


  case 3: system("exit");
           break;

  default: printf("invalid choice, select again");
          break;


  }

}



}





int main()
{char a;
 FILE *abc=fopen("name.txt","a");
 fclose(abc);
 display();
scanf("%c",&a);
system("clear");
display3();
 return(0);}
