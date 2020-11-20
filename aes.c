#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void subbytes(unsigned char *text1);
void roundkey(unsigned char *text,unsigned char *key1);
void mixcolumns(unsigned char *text3);
void keyexpansion(unsigned char *key0, int z);
void shiftrow(unsigned char *text2);








unsigned char s[256] =
{
	0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
	0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
	0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
	0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
	0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
	0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
	0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
	0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
	0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
	0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
	0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
	0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
	0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
	0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
	0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
	0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
};



// Multiply by 2 for MixColumns
unsigned char m2[256] =
{
	0x00,0x02,0x04,0x06,0x08,0x0a,0x0c,0x0e,0x10,0x12,0x14,0x16,0x18,0x1a,0x1c,0x1e,
	0x20,0x22,0x24,0x26,0x28,0x2a,0x2c,0x2e,0x30,0x32,0x34,0x36,0x38,0x3a,0x3c,0x3e,
	0x40,0x42,0x44,0x46,0x48,0x4a,0x4c,0x4e,0x50,0x52,0x54,0x56,0x58,0x5a,0x5c,0x5e,
	0x60,0x62,0x64,0x66,0x68,0x6a,0x6c,0x6e,0x70,0x72,0x74,0x76,0x78,0x7a,0x7c,0x7e,
	0x80,0x82,0x84,0x86,0x88,0x8a,0x8c,0x8e,0x90,0x92,0x94,0x96,0x98,0x9a,0x9c,0x9e,
	0xa0,0xa2,0xa4,0xa6,0xa8,0xaa,0xac,0xae,0xb0,0xb2,0xb4,0xb6,0xb8,0xba,0xbc,0xbe,
	0xc0,0xc2,0xc4,0xc6,0xc8,0xca,0xcc,0xce,0xd0,0xd2,0xd4,0xd6,0xd8,0xda,0xdc,0xde,
	0xe0,0xe2,0xe4,0xe6,0xe8,0xea,0xec,0xee,0xf0,0xf2,0xf4,0xf6,0xf8,0xfa,0xfc,0xfe,
	0x1b,0x19,0x1f,0x1d,0x13,0x11,0x17,0x15,0x0b,0x09,0x0f,0x0d,0x03,0x01,0x07,0x05,
	0x3b,0x39,0x3f,0x3d,0x33,0x31,0x37,0x35,0x2b,0x29,0x2f,0x2d,0x23,0x21,0x27,0x25,
	0x5b,0x59,0x5f,0x5d,0x53,0x51,0x57,0x55,0x4b,0x49,0x4f,0x4d,0x43,0x41,0x47,0x45,
	0x7b,0x79,0x7f,0x7d,0x73,0x71,0x77,0x75,0x6b,0x69,0x6f,0x6d,0x63,0x61,0x67,0x65,
	0x9b,0x99,0x9f,0x9d,0x93,0x91,0x97,0x95,0x8b,0x89,0x8f,0x8d,0x83,0x81,0x87,0x85,
	0xbb,0xb9,0xbf,0xbd,0xb3,0xb1,0xb7,0xb5,0xab,0xa9,0xaf,0xad,0xa3,0xa1,0xa7,0xa5,
	0xdb,0xd9,0xdf,0xdd,0xd3,0xd1,0xd7,0xd5,0xcb,0xc9,0xcf,0xcd,0xc3,0xc1,0xc7,0xc5,
	0xfb,0xf9,0xff,0xfd,0xf3,0xf1,0xf7,0xf5,0xeb,0xe9,0xef,0xed,0xe3,0xe1,0xe7,0xe5
};




// Multiply by 3 for MixColumns
unsigned char m3[256] =
{
	0x00,0x03,0x06,0x05,0x0c,0x0f,0x0a,0x09,0x18,0x1b,0x1e,0x1d,0x14,0x17,0x12,0x11,
	0x30,0x33,0x36,0x35,0x3c,0x3f,0x3a,0x39,0x28,0x2b,0x2e,0x2d,0x24,0x27,0x22,0x21,
	0x60,0x63,0x66,0x65,0x6c,0x6f,0x6a,0x69,0x78,0x7b,0x7e,0x7d,0x74,0x77,0x72,0x71,
	0x50,0x53,0x56,0x55,0x5c,0x5f,0x5a,0x59,0x48,0x4b,0x4e,0x4d,0x44,0x47,0x42,0x41,
	0xc0,0xc3,0xc6,0xc5,0xcc,0xcf,0xca,0xc9,0xd8,0xdb,0xde,0xdd,0xd4,0xd7,0xd2,0xd1,
	0xf0,0xf3,0xf6,0xf5,0xfc,0xff,0xfa,0xf9,0xe8,0xeb,0xee,0xed,0xe4,0xe7,0xe2,0xe1,
	0xa0,0xa3,0xa6,0xa5,0xac,0xaf,0xaa,0xa9,0xb8,0xbb,0xbe,0xbd,0xb4,0xb7,0xb2,0xb1,
	0x90,0x93,0x96,0x95,0x9c,0x9f,0x9a,0x99,0x88,0x8b,0x8e,0x8d,0x84,0x87,0x82,0x81,
	0x9b,0x98,0x9d,0x9e,0x97,0x94,0x91,0x92,0x83,0x80,0x85,0x86,0x8f,0x8c,0x89,0x8a,
	0xab,0xa8,0xad,0xae,0xa7,0xa4,0xa1,0xa2,0xb3,0xb0,0xb5,0xb6,0xbf,0xbc,0xb9,0xba,
	0xfb,0xf8,0xfd,0xfe,0xf7,0xf4,0xf1,0xf2,0xe3,0xe0,0xe5,0xe6,0xef,0xec,0xe9,0xea,
	0xcb,0xc8,0xcd,0xce,0xc7,0xc4,0xc1,0xc2,0xd3,0xd0,0xd5,0xd6,0xdf,0xdc,0xd9,0xda,
	0x5b,0x58,0x5d,0x5e,0x57,0x54,0x51,0x52,0x43,0x40,0x45,0x46,0x4f,0x4c,0x49,0x4a,
	0x6b,0x68,0x6d,0x6e,0x67,0x64,0x61,0x62,0x73,0x70,0x75,0x76,0x7f,0x7c,0x79,0x7a,
	0x3b,0x38,0x3d,0x3e,0x37,0x34,0x31,0x32,0x23,0x20,0x25,0x26,0x2f,0x2c,0x29,0x2a,
	0x0b,0x08,0x0d,0x0e,0x07,0x04,0x01,0x02,0x13,0x10,0x15,0x16,0x1f,0x1c,0x19,0x1a
};




//rcon table
unsigned char rcon[10]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1B,0x36};





void roundkey(unsigned char *text,unsigned char *key1)
{
	for (int i=0; i<16;i++)
	{	text[i]=text[i] ^ key1[i];



	}



}


void subbytes(unsigned char *text1)
{  for(int g=0;g<16;g++)
   {int value= (int) text1[g];
      text1[g]=s[value];


   }


}


void shiftrow(unsigned char *text2)
{ unsigned char temp[16];


 temp[0]=text2[0];                                        //1st row, nothing happens
 temp[1]=text2[5];                                         //2nd row, 1 shift
 temp[2]=text2[10];                                        //3rd row, 2 shift
 temp[3]=text2[15];                                        //4th row, 3 shift



  temp[4]=text2[4];
  temp[5]=text2[9];
  temp[6]=text2[14];
  temp[7]=text2[3];



  temp[8]=text2[8];
  temp[9]=text2[13];
  temp[10]=text2[2];
  temp[11]=text2[7];



  temp[12]=text2[12];
  temp[13]=text2[1];
  temp[14]=text2[6];
  temp[15]=text2[11];


  for(int f=0;f<16;f++)
  { text2[f]=temp[f];

  }
}



void mixcolumns(unsigned char *text3)
{ unsigned char temp[16];

    //1st column
   temp[0]= m2[(int)text3[0]] ^ m3[(int)text3[1]] ^ text3[2] ^ text3[3];
   temp[4]= m2[(int)text3[4]] ^ m3[(int)text3[5]] ^ text3[6] ^ text3[7];
   temp[8]= m2[(int)text3[8]] ^ m3[(int)text3[9]] ^ text3[10] ^ text3[11];
   temp[12]= m2[(int)text3[12]] ^ m3[(int)text3[13]] ^ text3[14] ^ text3[15];

   //2nd column
    temp[1]= text3[0] ^ m2[(int)text3[1]] ^ m3[(int)text3[2]] ^ text3[3];
    temp[5]= text3[4] ^ m2[(int)text3[5]] ^ m3[(int)text3[6]] ^ text3[7];
    temp[9]= text3[8] ^ m2[(int)text3[9]] ^ m3[(int)text3[10]] ^ text3[11];
    temp[13]= text3[12] ^ m2[(int)text3[13]] ^ m3[(int)text3[14]] ^ text3[15];

    //3rd column
    temp[2]= text3[0] ^ text3[1] ^ m2[(int)text3[2]] ^ m3[(int)text3[3]];
    temp[6]= text3[4] ^ text3[5] ^ m2[(int)text3[6]] ^ m3[(int)text3[7]];
    temp[10]= text3[8] ^ text3[9] ^ m2[(int)text3[10]] ^ m3[(int)text3[11]];
    temp[14]= text3[12] ^ text3[13] ^ m2[(int)text3[14]] ^ m3[(int)text3[15]];

    //4th column
    temp[3]= m3[(int)text3[0]] ^ text3[1] ^ text3[2] ^ m2[(int)text3[3]];
    temp[7]= m3[(int)text3[4]] ^ text3[5] ^ text3[6] ^ m2[(int)text3[7]];
    temp[11]= m3[(int)text3[8]] ^ text3[9] ^ text3[10] ^ m2[(int)text3[11]];
    temp[15]= m3[(int)text3[12]] ^ text3[13] ^ text3[14] ^ m2[(int)text3[15]];

    for(int l=0;l<16;l++)
    { text3[l]=temp[l];

    }


}



void keyexpansion(unsigned char *key0, int z)
{ unsigned char temp[16];

//1st column

temp[0]=s[(int)key0[13]]^key0[0]^rcon[z];
temp[1]=s[(int)key0[14]]^key0[1];
temp[2]=s[(int)key0[15]]^key0[2];
temp[3]=s[(int)key0[12]]^key0[3];

//2nd column
temp[4]=temp[0]^key0[4];
temp[5]=temp[1]^key0[5];
temp[6]=temp[2]^key0[6];
temp[7]=temp[3]^key0[7];

//3rd column
temp[8]=temp[4]^key0[8];
temp[9]=temp[5]^key0[9];
temp[10]=temp[6]^key0[10];
temp[11]=temp[7]^key0[11];

//4th column
temp[12]=temp[8]^key0[12];
temp[13]=temp[9]^key0[13];
temp[14]=temp[10]^key0[14];
temp[15]=temp[11]^key0[15];

for(int a=0;a<16;a++)
{
  key0[a]=temp[a];
}


}



void aes(unsigned char *cipher)
{
unsigned char key[16]={0x41,0x41,0x41,0x41,0x41,0x41,0x31,0x31,0x31,0x31,0x31,0x31,0x71,0x71,0x71,0x71};


    roundkey(cipher,key);              //1st round

   for(int y=0;y<9;y++)                //9 rounds
    {
       subbytes(cipher);
       shiftrow(cipher);
       mixcolumns(cipher);
       keyexpansion(key,y);
       roundkey(cipher,key);

    }

    subbytes(cipher);                 //final round
    shiftrow(cipher);
    keyexpansion(key,9);
    roundkey(cipher,key);



}


