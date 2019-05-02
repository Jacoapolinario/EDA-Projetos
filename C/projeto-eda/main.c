#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <unistd.h>


void var_func(char *);
void ilbp(int**, double**, int, int,int );
void glcm(int **, int, int, int, int, double **, int, int);
void manipulador(FILE **,double**,int , int , int ,int **, char );
void normaliza(double **, double **,  int);
void media_calculo(double **, double*);
double distancia_drone(double *);

int main(int argc, char const *argv[]) {
    int var_number_um = 51, var_number_dois = 50, var_number_tres;
    int linha,coluna,n=0, **matAsfalto, **matGrama;
    double **vetor_asfalto_resultado, **vetor_normalizador_asfalto, *vetor_asfalto_final, **vetor_grama_resultado, **vetor_normalizador_grama, *vetor_grama_final;
    double grama_distancia_media, asfalto_distancia_media, grama_distancia_vetor[25], asfalto_distancia_vetor[25], acertos_taxas, falsa_aceitacao_taxa, falsa_resegundo_contadoreicao_taxa;
    char fNameAsfalto[var_number_dois],fNameGrama[var_number_dois],letra, asfalto[var_number_dois],grama[var_number_dois];
    FILE *arquivos_imagens_a, *arquivos_imagens_g;

var_func(asfalto);

for (int contador = 1; contador < var_number_one; contador++) {
    printf("%d ",asfalto[contador]);
}


vetor_asfalto_resultado = (double**)malloc(var_number_dois*sizeof(double *));
for(int contador = 0; contador<var_number_one; contador++)
  *(vetor_asfalto_resultado+contador) = (double*)malloc(536*sizeof(double));

vetor_grama_resultado = (double**)malloc(var_number_dois*sizeof(double *));
for(int contador = 0; contador<var_number_one; contador++)
  *(vetor_grama_resultado+contador) = (double*)malloc(536*sizeof(double));


vetor_normalizador_asfalto = (double**)malloc(var_number_dois*sizeof(double *));
for(int contador = 0; contador<var_number_one; contador++)
  *(vetor_normalizador_asfalto+contador) = (double*)malloc(536*sizeof(double));

vetor_normalizador_grama = (double**)malloc(var_number_dois*sizeof(double *));
for(int contador = 0; contador<var_number_one; contador++)
  *(vetor_normalizador_grama+contador) = (double*)malloc(536*sizeof(double));


vetor_asfalto_final = (double*)malloc(536*sizeof(double));
vetor_grama_final = (double*)malloc(536*sizeof(double));



 for (int contador = 1; contador < var_number_one; contador++){

   if (asfalto[contador]<10)
   sprintf(fNameAsfalto,"asphalt/asphalt_0%d.txt",asfalto[contador]);

   else
   sprintf(fNameAsfalto,"asphalt/asphalt_%d.txt",asfalto[contador]);

    arquivos_imagens_a = fopen(fNameAsfalto, "r");

    if (arquivos_imagens_a == NULL)
       {
         printf("N�o foi poss�vel abrir o arquivo %s \n",fNameAsfalto);
         system("pause");
         exit(1);
       }
 
    linha = coluna = 0;
    while((letra=fgetc(arquivos_imagens_a))!=EOF){
          if (letra=='\n'){
            linha++;
          }
          else if (linha==0 && letra == ';'){
            coluna++;
          }
        }
        coluna++;
        rewind(arquivos_imagens_a);
       
        matAsfalto = (int**)malloc(linha*sizeof(int *));
        for(int contador = 0; contador<linha; contador++)
          *(matAsfalto+contador) = (int*)malloc(coluna*sizeof(int));


           manipulador(&arquivos_imagens_a, vetor_asfalto_resultado, linha,  coluna, n,matAsfalto, letra);
           glcm(matAsfalto , linha, coluna, 0, -1, vetor_asfalto_resultado, 512, n); 
           printf("\n");
           glcm(matAsfalto, linha, coluna, 0, +1, vetor_asfalto_resultado, 515, n); 
           printf("\n");
           glcm(matAsfalto , linha, coluna, -1, 0, vetor_asfalto_resultado, 518, n); 
           printf("\n");
           glcm(matAsfalto , linha, coluna, +1, 0, vetor_asfalto_resultado, 521, n); 
           printf("\n");
           glcm(matAsfalto , linha, coluna, -1, -1, vetor_asfalto_resultado, 524, n); 
           printf("\n");
           glcm(matAsfalto , linha, coluna, -1, +1, vetor_asfalto_resultado, 527, n); 
           printf("\n");
           glcm(matAsfalto , linha, coluna, +1, +1, vetor_asfalto_resultado, 530, n); 
           printf("\n");
           glcm(matAsfalto , linha, coluna, +1, -1, vetor_asfalto_resultado, 533, n); 
           printf("\n");
           normaliza(vetor_asfalto_resultado, vetor_normalizador_asfalto, n);
    fclose(arquivos_imagens_a);
    n+=1;
    printf("\nArquivo %s (%d)\nLinhas: %d \n Colunas: %d \n",fNameAsfalto,contador, linha,coluna);
    
    for (int contador=0;contador<linha;contador++)
           free(*(matAsfalto+contador));

           free(matAsfalto);

  }  
var_func(grama);

 for (int contador = 1; contador < var_number_one; contador++){

   if (grama[contador]<10)
   sprintf(fNameGrama,"grass/grass_0%d.txt",grama[contador]);

   else
   sprintf(fNameGrama,"grass/grass_%d.txt",grama[contador]);

    arquivos_imagens_g = fopen(fNameGrama, "r");

    if (arquivos_imagens_g == NULL)
       {
         printf("N�o foi poss�vel abrir o arquivo %s \n",fNameGrama);
         system("pause");
         exit(1);
       }
  
    linha = coluna = 0;
    while((letra=fgetc(arquivos_imagens_g))!=EOF){
          if (letra=='\n'){
            linha++;
          }
          else if (linha==0 && letra == ';'){
            coluna++;
          }
        }
        coluna++;
        rewind(arquivos_imagens_g);
        
        matGrama = (int**)malloc(linha*sizeof(int *));
        for(int contador = 0; contador<linha; contador++)
          *(matGrama+contador) = (int*)malloc(coluna*sizeof(int));

           manipulador(&arquivos_imagens_g, vetor_grama_resultado, linha,  coluna, contador,matGrama, letra);
           glcm(matGrama , linha, coluna, 0, -1, vetor_grama_resultado, 512, contador); 
           printf("\n");
           glcm(matGrama, linha, coluna, 0, +1, vetor_grama_resultado, 515, contador); 
           printf("\n");
           glcm(matGrama , linha, coluna, -1, 0, vetor_grama_resultado, 518, contador); 
           printf("\n");
           glcm(matGrama , linha, coluna, +1, 0, vetor_grama_resultado, 521, contador); 
           printf("\n");
           glcm(matGrama , linha, coluna, -1, -1, vetor_grama_resultado, 524, contador); 
           printf("\n");
           glcm(matGrama , linha, coluna, -1, +1, vetor_grama_resultado, 527, contador); 
           printf("\n");
           glcm(matGrama , linha, coluna, +1, +1, vetor_grama_resultado, 530, contador); 
           printf("\n");
           glcm(matGrama , linha, coluna, +1, -1, vetor_grama_resultado, 533, contador); 
           printf("\n");
           normaliza(vetor_grama_resultado, vetor_normalizador_grama, contador);
    fclose(arquivos_imagens_g);
    n+=1;
    printf("\nArquivo %s  (%d)\nLinhas: %d \n Colunas: %d \n",fNameGrama,contador, linha,coluna);
    
    for (int contador=0;contador<linha;contador++)
           free(*(matGrama+contador));

           free(matGrama);

  }  


  printf("Normalizando ...\n" );
  printf("Normalizando ...\n" );
  printf("Normalizando ...\n" );
  printf("Normalizando ...\n" );



media_calculo(vetor_normalizador_asfalto,vetor_asfalto_final);
media_calculo(vetor_normalizador_grama,vetor_grama_final);

asfalto_distancia_media = distancia_drone(vetor_asfalto_final);
grama_distancia_media = distancia_drone(vetor_grama_final);

int cont = 0;
for (int contador=25;contador<var_number_dois;contador++){
  asfalto_distancia_vetor[cont] = distancia_drone(*(vetor_normalizador_asfalto + contador));
  cont++;
}

cont = 0;
for (int contador=25;contador<var_number_dois;contador++){
  grama_distancia_vetor[cont] = distancia_drone(*(vetor_normalizador_grama + contador));
  cont++;
}


for (int contador=0;contador<25;contador++){
  if((asfalto_distancia_vetor[contador] - asfalto_distancia_media) < (asfalto_distancia_vetor[contador] - grama_distancia_media)){
    acertos_taxas += 1.0;
  }

  if((asfalto_distancia_vetor[contador] - asfalto_distancia_media) > (asfalto_distancia_vetor[contador] - grama_distancia_media)){
    falsa_aceitacao_taxa += 1.0;
  }

}
for (int contador=0;contador<25;contador++){
  if((grama_distancia_vetor[contador] - asfalto_distancia_media) > (grama_distancia_vetor[contador] - grama_distancia_media)){
    acertos_taxas += 1.0;
  }

  printf("%lf\n", grama_distancia_vetor[contador] - asfalto_distancia_media );
  printf("%lf\n", grama_distancia_vetor[contador] - grama_distancia_media );

  if((grama_distancia_vetor[contador] - asfalto_distancia_media) < (grama_distancia_vetor[contador] - grama_distancia_media)){
    falsa_resegundo_contadoreicao_taxa += 1.0;
  }
  printf("\n");
  printf("%lf\n",grama_distancia_vetor[contador] - asfalto_distancia_media);
  printf("%lf\n",  grama_distancia_vetor[contador] - grama_distancia_media);
}


for (int contador=0;contador<var_number_dois;contador++){
  free(*(vetor_asfalto_resultado+contador));
  free(*(vetor_grama_resultado+contador));
}
free(vetor_asfalto_resultado);
free(vetor_grama_resultado);


 for (int contador=0;contador<var_number_dois;contador++){
  free(*(vetor_normalizador_asfalto+contador));
  free(*(vetor_normalizador_grama+contador));
}
 free(vetor_normalizador_asfalto);
 free(vetor_normalizador_grama);

 
  free(vetor_asfalto_final);
  free(vetor_grama_final);

  printf("\n distancia media asphalt: %lf\n", asfalto_distancia_media);
  printf("\n distancia media grama:%lf\n", grama_distancia_media);

  for (int contador=0;contador<25;contador++){
    printf("%lf ", asfalto_distancia_vetor[contador]);
  }

  printf("\n");

  for (int contador=0;contador<25;contador++){
    printf("%lf ", asfalto_distancia_vetor[contador]);

  }

  printf("Taxa de acerto: %lf \n", acertos_taxas);
  printf("Taxa de taxa falsa aceitacao: %lf \n", falsa_aceitacao_taxa);
  printf("Taxa de taxa falsa resegundo_contadoreicao: %lf \n", falsa_resegundo_contadoreicao_taxa);

    return 0;

}

void var_func(char *array){

  srand(time( NULL ));

  printf("\n Vetor original: \n");
  for (int contador = 1; contador < var_number_one; contador++) {   
      array[contador] = contador;
      printf("%d ", array[contador]);
  }

  printf("Esse � o vetor final:\n");

  for (int contador = 1; contador < var_number_one; contador++) {

    int temp = array[contador];
    int randomIndex = 0;
    randomIndex = rand() %var_number_dois;
    if (randomIndex==0) randomIndex = rand() %var_number_dois;
      array[contador]           = array[randomIndex];
      array[randomIndex] = temp;
    if (array[contador]==0){
      printf("DEU RUIM no %d\n",array[randomIndex] );
      exit(0);
    }
    }

printf("\n");

}

void ilbp(int **mat,double **vetresultante,int linha,int coluna,int n){

  int decimal=0,contador,segundo_contador,
  contl=0,contc=0;

  double media=0;

  char submat[3][3],
       bit[9];

  
  for ( contador = linha-1 ;contador<linha+2;contador++){
    for ( segundo_contador =coluna-1 ; segundo_contador<coluna+2; segundo_contador++){
      media += *(*(mat+(contador))+(segundo_contador));
    }
  }

 
  for ( contador = linha-1 ;contador<linha+2;contador++){
    for ( segundo_contador =coluna-1 ; segundo_contador<coluna+2; segundo_contador++){
      if ( *(*(mat+(contador))+(segundo_contador)) > (media/9)){
        submat[contl][contc] = '1';
        contc++;}
      if ( *(*(mat+(contador))+(segundo_contador)) < (media/9)){
        submat[contl][contc] = '0';
        contc++;}

    }
  }


  bit[0]=submat[0][0];
  bit[1]=submat[0][1];
  bit[2]=submat[0][2];
  bit[3]=submat[1][2];
  bit[4]=submat[2][2];
  bit[5]=submat[2][1];
  bit[6]=submat[2][0];
  bit[7]=submat[1][0];
  bit[8]=submat[1][1];

  
  for (int bitsegundo_contador=0; bitsegundo_contador<9; bitsegundo_contador++){
  if (bit[bitsegundo_contador] == '1') decimal = decimal * 2 + 1;
  else if (bit[bitsegundo_contador] == '0') decimal *= 2;}

 
  int dec = 0;
  for (int contador = 0; contador <8; contador ++){
    dec = 0;
    char bit2 = bit[0];
    for (int shiftsegundo_contador=0;shiftsegundo_contador<9;shiftsegundo_contador++){


      if (shiftsegundo_contador==8)
        bit[8]=bit2;
      else
        bit[shiftsegundo_contador]=bit[shiftsegundo_contador+1];
         
        if (bit[shiftsegundo_contador] == '1') dec = dec * 2 + 1;
        else if (bit[shiftsegundo_contador] == '0') dec *= 2;



    }
    if (decimal>dec )
      decimal=dec;

  }
(*(*(vetresultante+n)+decimal))++;
}

void manipulador(FILE **arquivo, double **vetresultante,int linha, int coluna, int n, int **mat, char letra){


  
  for (int contador=0;contador<linha;contador++){
        for (int segundo_contador=0;segundo_contador<coluna;segundo_contador++){
           fscanf(*arquivo,"%d%c", (*(mat+contador)+segundo_contador),&letra);
        }
  }
 
  for (int contador=1;contador<linha-1;contador++){
    for (int segundo_contador=1;segundo_contador<coluna-1;segundo_contador++){
      ilbp(mat,vetresultante ,contador,segundo_contador,n);
    }
  }

}

void glcm(int **img , int L, int C, int pos_lin, int pos_col, double **vetresultante, int pos_freq,int n){
  int **glcm, contador, segundo_contador, lin_glcm, col_glcm;
  double energia = 0.0, contraste = 0.0, homogeneidade = 0.0;

  glcm = (int**)calloc(256,sizeof(int *));

  for(contador =  0; contador<256; contador++)                         
    *(glcm+contador) = (int*)calloc(256,sizeof(int));


    for(contador =  1; contador<L - 1; contador++){
      for(segundo_contador = 1; segundo_contador<C - 1; segundo_contador++){ 
          lin_glcm = img[contador][segundo_contador];
          col_glcm = img[contador + pos_lin][segundo_contador + pos_col]; 
          *(*(glcm+lin_glcm)+col_glcm) += 1;

        }
      }

      for (contador =  0; contador < 256; contador++){
          for (segundo_contador = 0; segundo_contador < 256; segundo_contador++){
          if(*(*(glcm + contador)+ segundo_contador) >= 1){
            contraste += (*(*(glcm + contador)+ segundo_contador)) * pow(contador - segundo_contador, 2); 
            energia += pow((*(*(glcm + contador)+ segundo_contador)), 2);
            homogeneidade += (*(*(glcm + contador)+ segundo_contador))/1+ (contador - segundo_contador) ;
          }
        }
      }

    energia = sqrt(energia);

    *(*(vetresultante + n)+ pos_freq) = contraste;
    *(*(vetresultante + n)+ (pos_freq + 1)) = energia;
    *(*(vetresultante + n)+ (pos_freq + 2)) = homogeneidade;

    printf("Cont: %.0lf ener: %.0lf homo: %.0lf \n", contraste, energia, homogeneidade);

   for (contador = 0;contador<256;contador++)
      free(*(glcm+contador));

    free(glcm);


}
void normaliza(double **vetresultante, double **vetnormalizado, int n){
  int contador = 0;
  double menor = 999999999, maior = 0;

    for(contador =  0; contador < 536; contador++){
      if(*(*(vetresultante + n)+ contador) > maior){
          maior = *(*(vetresultante + n)+ contador);
      }
      if(*(*(vetresultante + n)+ contador) < menor){
        menor = *(*(vetresultante + n)+ contador);
      }

    }
    for(contador =  0; contador < 536; contador++){
      *(*(vetnormalizado + n)+ contador) = (*(*(vetresultante + n)+ contador) - menor) / (maior - menor);
    }
    printf("Menor: %f\n Maior: %f\n", menor, maior );

}

void media_calculo(double **vetnormalizado, double *vetor_asfalto_final){
  int contador,segundo_contador=0;
  double *media;

  media = (double *) calloc(536, sizeof (double));

  for(contador = 0;contador<25;contador++){
    for(segundo_contador=0;segundo_contador<536;segundo_contador++){
      *(media+segundo_contador) += (*(*(vetnormalizado + contador)+ segundo_contador));
    }
  }

  for(segundo_contador=0;segundo_contador<536;segundo_contador++){
    *(vetor_asfalto_final+segundo_contador)= *(media+segundo_contador)/25;
  }
  printf("M�dias:::::::\n" );

  for(segundo_contador=0;segundo_contador<536;segundo_contador++){
    printf(" %lf", *(vetor_asfalto_final+segundo_contador));
  }
  free(media);
}

double distancia_drone(double *vetresultante){
  int contador = 0;
  double distancia = 0.0;

    for(contador =  0; contador < 536; contador++){
        distancia += pow(*(vetresultante + contador),2);
    }
    distancia = sqrt(distancia);

    return distancia;

}
