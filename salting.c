#include<time.h>
#include<inttypes.h>
#include<stdio.h>


char arr1[32];
int binary[32];
int test,value1;
int lower=35,upper=126;
FILE *fp;

void salt()
{
    rewind(fp);
   for(int i=0;i<32;i++)

  {
     arr1[i]= (rand() % (lower-upper+1)) + lower;
     value1=(int) arr1[i];

      int result=0,a=1,rem;
      while(value1>0)
       {
          rem=value1%2;
          result=result+(a*rem);
          value1=value1/2;
          a=a*10;

       }

       binary[i]=result;

  }


    while(!feof(fp))
  {  int count=0;

     for(int j=0;j<32;j++)
     {
       fscanf(fp,"%d",&test);

       if(test==binary[j])
         { count++; }

     }

     if(count>29)
     {salt();
       break;
     }




  }




}







void salting(uint32_t *h)
{int number;

fp=fopen("salt.bin","ab+");

FILE *hfp=fopen("password.txt","a");

  if(hfp==NULL)
  {printf("\n error..file cannot be open");}


  if(fp==NULL)
  {printf("\n error..file cannot be open");}

 srand(time(0));
  salt();

for(int k=0;k<32;k++)
  { fprintf(fp," %d",binary[k]); }

  fseek(hfp,0,SEEK_END);

  if(ftell(hfp)!=0)
  {fprintf(hfp,"\n");}

 printf("\t");
  for(int q=0;q<8;q++)
  {fprintf(hfp,"%x",h[q]);
   printf("%x",h[q]);}

  for(int f=0;f<32;f++)
  {number=(int)arr1[f];
  fprintf(hfp,"%x",number);
   printf("%x",number);}


  fclose(hfp);

 fclose(fp);

 
}

