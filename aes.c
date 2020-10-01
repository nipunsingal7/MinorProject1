
	
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

void MixColumns(unsigned char * state) {
	unsigned char tmp[16];

	tmp[0] = (unsigned char) mul2[state[0]] ^ mul3[state[1]] ^ state[2] ^ state[3];
	tmp[1] = (unsigned char) state[0] ^ mul2[state[1]] ^ mul3[state[2]] ^ state[3];
	tmp[2] = (unsigned char) state[0] ^ state[1] ^ mul2[state[2]] ^ mul3[state[3]];
	tmp[3] = (unsigned char) mul3[state[0]] ^ state[1] ^ state[2] ^ mul2[state[3]];

	tmp[4] = (unsigned char)mul2[state[4]] ^ mul3[state[5]] ^ state[6] ^ state[7];
	tmp[5] = (unsigned char)state[4] ^ mul2[state[5]] ^ mul3[state[6]] ^ state[7];
	tmp[6] = (unsigned char)state[4] ^ state[5] ^ mul2[state[6]] ^ mul3[state[7]];
	tmp[7] = (unsigned char)mul3[state[4]] ^ state[5] ^ state[6] ^ mul2[state[7]];

	tmp[8] = (unsigned char)mul2[state[8]] ^ mul3[state[9]] ^ state[10] ^ state[11];
	tmp[9] = (unsigned char)state[8] ^ mul2[state[9]] ^ mul3[state[10]] ^ state[11];
	tmp[10] = (unsigned char)state[8] ^ state[9] ^ mul2[state[10]] ^ mul3[state[11]];
	tmp[11] = (unsigned char)mul3[state[8]] ^ state[9] ^ state[10] ^ mul2[state[11]];

	tmp[12] = (unsigned char)mul2[state[12]] ^ mul3[state[13]] ^ state[14] ^ state[15];
	tmp[13] = (unsigned char)state[12] ^ mul2[state[13]] ^ mul3[state[14]] ^ state[15];
	tmp[14] = (unsigned char)state[12] ^ state[13] ^ mul2[state[14]] ^ mul3[state[15]];
	tmp[15] = (unsigned char)mul3[state[12]] ^ state[13] ^ state[14] ^ mul2[state[15]];

	for (int i = 0; i < 16; i++) {
		state[i] = tmp[i];
	}
}

