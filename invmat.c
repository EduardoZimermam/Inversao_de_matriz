#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void commandLine(int argc, char const *argv[], char fileIn, char fileOut, int dimIn, int nInter){
  int pos;

  pos = strcmp(*argv, "-e");
  if(pos != -1)
    fileIn = argv[pos + 1];

  pos = strcmp(*argv, "-o");
  if(pos)
    fileOut = argv[pos + 1];

  pos = strcmp(*argv, "-r");
  if(pos)
    dimIn = atoi(argv[pos + 1]);

  pos = strcmp(*argv, "-i");
  if(pos)
    nInter = atoi(argv[pos + 1]);
}

int main(int argc, char const *argv[]) {

  char *fileIn, *fileOut;
  int *dimIn, *nInter;

  commandLine(argc, argv, &fileIn, &fileOut, &dimIn, &nInter);   //Método para tratar a linha de comando verificando se há erros e retornando para o usuário.

  printf("%s\n", fileIn);
  printf("%s\n", fileOut);
  printf("%d\n", *dimIn);
  printf("%d\n", *nInter);

  return 0;
}
