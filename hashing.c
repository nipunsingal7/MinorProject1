#include<string.h>
#include<inttypes.h>
#include<stdio.h>

#define rightrotate(n,m) ((n>>m) | (n<<(32-m)))
uint8_t arr[64];
uint32_t value[64];


void newbytes();
void bitchanger();
void compression();


uint32_t h[8];



//First 32 bits of cube root of first 64 prime numbers
//formula= hex(2^32(cuberoot(number)))

uint32_t k[64]= {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2 };




//this function converts four 8bits elements to one 32bit element
void bitchanger()
{
   for(int j=0,l=0;j<16;j++,l+=3)
   {
      value[j]=(arr[j+l]<<24) | (arr[j+l+1]<<16) | (arr[j+l+2]<<8) | (arr[j+l+3]) ;
   }

}


//this function generates the remaining 48words
void newbytes()
{
   for(int i=16;i<64;i++)
   {
      uint32_t s0=rightrotate(value[i-15],7) ^ rightrotate(value[i-15],18) ^ (value[i-15]>>3);
      uint32_t s1= rightrotate(value[i-2],17) ^ rightrotate(value[i-2],19) ^ (value[i-2]>>10);
      value[i]=value[i-16]+s0+value[i-7]+s1;

   }

}


//this is the main function which generates the hash
void compression(uint32_t *h1)
{uint32_t a[8]={h1[0],h1[1],h1[2],h1[3],h1[4],h1[5],h1[6],h1[7]};


 for(int j=0;j<64;j++)
 {
   uint32_t s0=rightrotate(a[4],6) ^ rightrotate(a[4],11) ^ rightrotate(a[4],25);
   uint32_t ch=(a[4] & a[5]) ^ (~a[4] & a[6]);
   uint32_t temp1=a[7]+s0+ch+k[j]+value[j];
   uint32_t s1=rightrotate(a[0],2) ^ rightrotate(a[0],13) ^ rightrotate(a[0],22);
   uint32_t maj=(a[0] & a[1]) ^ (a[0] & a[2]) ^ (a[1] & a[2]);
   uint32_t temp2=maj+s1;

   a[7]=a[6];
   a[6]=a[5];
   a[5]=a[4];
   a[4]=a[3]+temp1;
   a[3]=a[2];
   a[2]=a[1];
   a[1]=a[0];
   a[0]=temp1+temp2;

 }

 h[0]=h1[0]+a[0];
 h[1]=h1[1]+a[1];
 h[2]=h1[2]+a[2];
 h[3]=h1[3]+a[3];
 h[4]=h1[4]+a[4];
 h[5]=h1[5]+a[5];
 h[6]=h1[6]+a[6];
 h[7]=h1[7]+a[7];


}

void hashing(unsigned char *cipher)
{

//First 32 bits of square root of first 8 prime numbers
//formula= hex(2^32(squareroot(number)))
uint32_t h1[8]={0x6a09e667,0xbb67ae85,0x3c6ef372,0xa54ff53a,0x510e527f,0x9b05688c,0x1f83d9ab,0x5be0cd19};

   for(int i=0;i<64;i++)
    {   if(i<16)
      {arr[i]=(int) cipher[i];}

       if(i>=17 && i<63)
       {arr[i]=0;}

       if(i==63 || i==16)
       {arr[i]=128;}

    }

    bitchanger();
    newbytes();
    compression(h1);


}
