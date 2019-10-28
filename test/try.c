#include <stdio.h>
#include <stdbool.h>

typedef int normalInt;



int main(){

  //Werte
  normalInt n = 10;
  int i = 10;
  char c = 'c';
  char cs = "cccc"; //-127...128
  unsigned char uc = "c"; //0-255
  //Ausgabe
  printf("%i\n", sizeof(i));
  //Strings
  char s[] = "abcdefg";
  char t[] = {'a','b','c'};

  //Arays
  normalInt a[] = {0,0,0,1,1};
  char b[20];
  b[0] = a[1];
  printf("%i\n", a[0]);


  int size = 20;


  for (int i = 0; i <size; i++) {
    b[i] = 'c';
  }


  //Zeiger
  int a = 0;
  int *b = &a;
  printf("%i\n",*b );






  //If-Anweisung
  if (i - 10) { // i = i-10 = 0 = false
    printf("%i\n", i);
  } else {
    printf("%c\n", c);
  }



}


struct Person{
  unsigned int alter;
  char name[20];
};
