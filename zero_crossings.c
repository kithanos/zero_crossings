//Programa que lê um arquivo texto (de números), exibe o seu contéudo na tela, e calcula os "zero crossings" do arquivo.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main( int argc, char **argv )
{
  //Declaração de variáveis:
  FILE *arq;
  char Linha[100];
  char nomearquivo[100];
  nomearquivo [ 0 ] = 0;
  char *result;
  int i,n;
  float dado[512];
  int zerocrossings=0;

  //Copia string do nome do arquivo (passado como parâmetro) para a varável "nomearquivo"
  strcpy( nomearquivo, argv[ 1 ] );

  //Abre o arquivo passado como leitura
  arq = fopen(nomearquivo, "rt");

  //Condicional para testar se o parâmetro passado está correto (se há algum arquivo de texto válido para leitura):
  /* if (strlen(nomearquivo) == 0)
  {
    printf("Faltou: %c\n",nomearquivo);
    return;
  }
  */

  //Outro condicional que testa se há algum arquivo para ler:
  if (arq == NULL)  
  {
    printf("Problemas na abertura do arquivo\n");
    return;
  }

  i = 1;

  //Enquanto não houver o fim do arquivo: 
  while (!feof(arq))
  {
    //"fgets" lendo cada linha do arquivo e salvando na variável "LINHA", lê até 99 caracteres, ou até \n
    result = fgets(Linha, 100, arq);

    //Transfere o conteúdo da variável "Linha" para o array dado[i] convertendo de char para float
    dado[i] = atof(Linha);

    //Se foi possivel ler:
    if (result)
    { 
      //printf("%f",Linha);

      //Condicional que testa se o indice está maior que 1, pois é preciso ter pelo menos dois dados para calcular o zero crossings
      if(i>1)
      {
	//printf("Anterior=%f, Atual=%f\n",dado[i-1],dado[i]);
	if((dado[i-1]*dado[i])<0)
	{
	  zerocrossings++;
	}

      }
      i++;
    }
    
  }

  //Fecha o arquivo e imprime o valor das contagens por zero:
  fclose(arq);
  printf("Zerocrossings = %d\n", zerocrossings);
}

