#include<stdio.h>
#include<stdlib.h>
#include<string.h>





char u;


int decimal(int data)
{  int ldigit=0,base=1,result2=0;

  while(data)
  {
     ldigit=data%10;
     data=data/10;
       result2+=ldigit*base;
       base=base*2;
  }


  return result2;
}






void login()
{
unsigned char passw[16];
unsigned char test[20],name1[20];;
 int flag=0,value2,count=0;
 char testing1[130],testing2[130],c;


printf("Enter the Name: ");
scanf("%s",&name1);

printf("\nEnter the password: ");
scanf("%s",&passw);



FILE *fp1=fopen("name.txt","r");
if(fp1==NULL)
  {printf("\n error..file cannot be open");}


while(!feof(fp1))
{ memset(test, '\0',sizeof(test));

  fscanf(fp1,"%s",&test);

   count+=1;

   if(strcasecmp(test,name1)==0)
   {flag=1;
    break;}


}

fclose(fp1);




if(flag!=1)
{printf("\nincorrect username or password..");
scanf("%c",&u);
scanf("%c",&u);
return;}


aes(passw);
hashing(passw);


FILE *fp2=fopen("salt.bin","rb");
if(fp2==NULL)
  {printf("\n error..file cannot be open");}

FILE *fp3=fopen("temp.txt","w+");
if(fp3==NULL)
  {printf("\n error..file cannot be open");}


  for(int m=0;m<8;m++)
  {fprintf(fp3,"%x",h[m]); }

  for(int i=0;i<(count-1)*32;i++)
  {fscanf(fp2,"%d",&value2);}

  for(int j=0;j<32;j++)
  {fscanf(fp2,"%d",&value2);
   fprintf(fp3,"%x",decimal(value2));
  }
 fclose(fp2);

FILE *fp4=fopen("password.txt","r");
if(fp4==NULL)
  {printf("\n error..file cannot be open");}

for(int h=0;h<count;h++)
{fscanf(fp4,"%s",&testing1);}


rewind(fp3);
fscanf(fp3,"%s",&testing2);


if(strcmp(testing1,testing2)==0)
{printf("\nlogin successful...");
scanf("%c",&u);
scanf("%c",&u);
}

else
{printf("\nincorrect username or password...");
scanf("%c",&u);
scanf("%c",&u);
}


fclose(fp3);
fclose(fp4);

}
