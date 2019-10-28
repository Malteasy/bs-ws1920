#include <stdio.h>

int main(int argc, char const *argv[]) {

  //* = Zeiger - zeigt auf die Speicheradresse  einer Variable
  //* benötigt & - liefert die Speicheradresse
  int a = 0;    //normale Variable
  int *b = &a;  //Zeigervariable auf a's Speicheradresse
  *b = 1;       //Der Zeiger kann den Speicherinhalt manipulieren
  a = 2;
  printf("%i\n",*b);
  printf("%i\n",a);
  return 0;
}
