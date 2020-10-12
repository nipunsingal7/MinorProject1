#include<time.h>

char arr[32];
int binary[32];
int test,value;
int lower=35,upper=126;
FILE *fp;

void salt()
{
    rewind(fp);
   for(int i=0;i<32;i++)

  {
     arr[i]= (rand() % (lower-upper+1)) + lower;
     value=(int) arr[i];

      int result=0,a=1,rem;
      while(value>0)
       {
          rem=value%2;
          result=result+(a*rem);
          value=value/2;
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

   for(int k=0;k<32;k++)
  { fprintf(fp," %d",binary[k]); }



}







void salting()
{fp=fopen("salt.bin","ab+");

  if(fp==NULL)
  {printf("\n error..file cannot be open");}

 srand(time(0));
  salt();

 fclose(fp);

}

