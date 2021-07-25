#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char data[100], gen[100], code[50];
int dataLen, genLen;

void doXor(int i) {
  if (code[i] == gen[i])
    code[i] = '0';
  else
    code[i] = '1';
}

void crc() {
  int i, j;
  for (i = 0; i < genLen; i++) {
    code[i] = data[i];
  }
  do { 
    if (code[0] == '1') {
      for (j = 1; j < genLen; j++) {
        doXor(j);
      }
    }
    for (j = 0; j < genLen - 1; j++)
      code[j] = code[j + 1];
    code[j] = data[i++];
  } while (i <= dataLen + genLen - 1);
}

int receiver() {
  int i;
  printf("Enter the data : ");
  scanf("%s", data);
  dataLen = strlen(data);\
   printf("Enter the polynomial: ");
  scanf("%s", gen);
    genLen = strlen(gen);
  int flag = 0;
  crc();
  for(i = 0; i < strlen(code); i++) {
    if(code[i]=='1')
      flag = 1;
  }
  return flag;
}

void main() {
    int flag = receiver();
    printf(flag == 1 ? "\nThere is an error in the data\n" : "\nNo error has been detected\n");
}