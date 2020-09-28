
void AddRoundKey(unsigned char * state, unsigned char * roundKey) {
	for (int i = 0; i < 16; i++) {
		state[i] ^= roundKey[i];
	}
	
void rowshift(unsigned char * cipher)
{
   unsigned char temp[16];


  temp[0]=cipher[0];                                           //according to row shifting, in first row there would be no shifting.
  temp[1]=cipher[5];                                           //in second row, one element will be shifted towards left.
  temp[2]=cipher[10];                                          //in third row, two elements will be dhifted towards left.
  temp[3]=cipher[15];                                          //in fourth row, three elements would be shifted towards left.


  temp[4]=cipher[4];
  temp[5]=cipher[9];
  temp[6]=cipher[14];
  temp[7]=cipher[3];
  

  temp[8]=cipher[8];
  temp[9]=cipher[13];
  temp[10]=cipher[2];
  temp[11]=cipher[7];


   temp[12]=cipher[12];
   temp[13]=cipher[1];
   temp[14]=cipher[6];
   temp[15]=cipher[11];

for (int i=0; i<16; i++)
{
    cipher[i]=temp[i];
}
}
