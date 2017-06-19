#ifndef __SOLVE_H__
#define __SOLVE_H__

#include<stdlib.h>
#include <string.h>

typedef struct {
  int nn; // numar noduri
  int **Ma; // matrice de adiacenta
} TGraphM;

typedef struct node {
  int v; // indicele nodului destinatie
  int c; // cost asociat arcului
  struct node *next;
} TNode, *ATNode;

typedef struct {
  int nn; // numar noduri
  ATNode *adl; // vector de pointeri alocati dinamici la vecini
} TGraphL;


void alloc_matrix(TGraphM * G, int n)
{
    if(G == NULL) return;
   
    G->nn = n;
    G->Ma = malloc((n + 1) * sizeof(int*));
   
    if(G->Ma == NULL) return;
 
    for(int i = 0; i < n + 1; i++)
    {
        G->Ma[i] =  calloc(n + 1, sizeof(int));
        if(G->Ma[i] == NULL)
        {
            for(int j = 0; j < i; j++)
            {
                free(G->Ma[j]);
            }
            free(G->Ma);
        return;
        }
    }
return;
}

void insert_edge_matrix(TGraphM *G, int v1, int v2 , int cost )
{

    G->Ma[v1][v2] = cost;

return;
}

void delete_node_matrix(TGraphM *G, int n)
{
    for(int i = 0; i <= G->nn; i++)
    {
        G->Ma[i][n] = 0;
        G->Ma[n][i] = 0;
    }
    return;
}

void free_matrix(TGraphM *G)
{

    for(int i = 0; i < G->nn + 1; i++)
    {
        free(G->Ma[i]);
    }
    free(G->Ma);
    return;

}

//CALCULEAZA MINIMUL PE LINIE
int calculeaza_min_linie( TGraphM *G, int n )
{ 
  int count = G->Ma[n][0];
  
  for ( int i = 1 ; i < G->nn ; i++ )
  {
      if( count > G->Ma[n][i] )
          count = G->Ma[n][i];
  }

return count;
} 

//CALCULEAZA MINIMUL PE COLOANA
int calculeaza_min_coloana( TGraphM *G, int n )
{

  int count = G->Ma[0][n];

  for ( int i = 1 ; i < G->nn ; i++ )
  {
      if( count > G->Ma[i][n] )
          count = G->Ma[i][n];
  }
  
return count;
} 

//FACE 0 PE LINIE
void get_zero_linie( TGraphM *G, int n )
{

  int zero = calculeaza_min_linie(G , n);
   
  for ( int i = 0 ; i < G->nn ; i++ )
  {
     G->Ma[n][i] = G->Ma[n][i] - zero;
  }

}

//FACE 0 PE COLOANA
void get_zero_coloana( TGraphM *G, int n )
{

  int zero = calculeaza_min_coloana(G , n);
   
  for ( int i = 0 ; i < G->nn ; i++ )
  {
     G->Ma[i][n] = G->Ma[i][n] - zero;
  }
}

//FUNCTIE OPTINALA DE AFISARE.
void print_mat( TGraphM *G)
{
  for (int i = 0 ; i < G->nn ; i++ )
  {
     for (int j = 0 ; j < G->nn ; j++ )
     { 
        printf("%d ", G->Ma[i][j] );
     }
  printf("\n");
  }
  
}

//COPIAZA O MATRICE
TGraphM copy_Mat( TGraphM* G )
{

  TGraphM newMat; 
  alloc_matrix(&newMat , G->nn );

  for (int i = 0 ; i < G->nn ; i++ )
  {
     for (int j = 0 ; j < G->nn ; j++ )
     { 
        newMat.Ma[i][j] = G->Ma[i][j];
     }
  }

return newMat;  
}

//RETURNEAZA NR DE 0 DE PE LINIE.
int get_nr_zero_linie( TGraphM *G, int n )
{
  int count = 0;
  for (int i = 0; i < G->nn; i++)
  {
     if( G->Ma[n][i] == 0 ) count++;
  }

return count;
}

//RETURNEAZA NR DE 0 DE PE COLOANA.
int get_nr_zero_coloana( TGraphM *G, int n )
{
  int count = 0;
  for (int i = 0; i < G->nn; i++)
  {
     if( G->Ma[i][n] == 0 ) count++;
  }
  
return count;
}

//MRCHEAZA LINIE.
void umple_linie( TGraphM *G, int n )
{
  for (int i = 0; i < G->nn; i++)
  {
    if( G->Ma[n][i] != 3 ) 
    {
      if( G->Ma[n][i] == 1 ) 
         G->Ma[n][i] = 2; 
      else
         G->Ma[n][i] = 1;
    }
  }

}

//MARCHEAZA COLOANA.
void umple_coloana( TGraphM *G, int n )
{

  for (int i = 0; i < G->nn; i++)
  {
    if( G->Ma[i][n] != 3 ) 
    {  
      if( G->Ma[i][n] == 1 ) 
          G->Ma[i][n] = 2; 
      else
          G->Ma[i][n] = 1;
    }
  }

}

//RETURNEAZA NR DE 0 DE PE LINIE, NEMARCATI.
int get_nr_zero_linie_NEMARC( TGraphM *G, int n , TGraphM* marcat )
{
  int count = 0;
  for (int i = 0; i < G->nn; i++)
  {
     if( G->Ma[n][i] == 0 && marcat->Ma[n][i] == 0 ) count++;
  }

return count;
}

//RETURNEAZA NR DE 0 DE PE COLOANA, NEMARCATI.
int get_nr_zero_coloana_NEMARC( TGraphM *G, int n , TGraphM* marcat)
{
  int count = 0;
  for (int i = 0; i < G->nn; i++)
  {
     if( G->Ma[i][n] == 0 && marcat->Ma[i][n] == 0 ) count++;
  }
  
return count;
}

//RETURNEAZA POZITIA CU 0 DE PE LINIE.
int poziton_z_linie(TGraphM* G , int n  , TGraphM* marcat)
{
  for (int i = 0 ; i < G->nn ; i++ )
  {
     if( G->Ma[n][i] == 0 && marcat->Ma[n][i] == 0 ) return i;
  }

return 0;
}

//RETURNEAZA POZITIA CU 0 DE PE COLOANA.
int poziton_z_coloana(TGraphM* G , int n , TGraphM* marcat)
{
  for (int i = 0 ; i < G->nn ; i++ )
  {
     if( G->Ma[i][n] == 0 && marcat->Ma[i][n] == 0) return i;
  }

return 0;
}

//RETURNEAZA NUMARUL TOTAL DE 0 DIN MATRICE.
int nr_z_total( TGraphM* G  ,  TGraphM* marcat )
{
  
  int count = 0;
  for (int i = 0 ; i < G->nn ; i++ )
  {
    for (int j = 0 ; j < G->nn ; j++ )
    {

     if( G->Ma[i][j] == 0 && marcat->Ma[i][j] == 0 ) count++;
    
    }
  }  

return count;
}

//MARCHEAZA
int marcheaza_linii(TGraphM *G , TGraphM *marcat)
{
  int save;
  int count = 0;
  int total;  

pass:
  //DACA O LINIE CONTINE UN 0 SE MARCHEAZA COLOANA RESPECTIVA.
  //DACA O COLOANA CONTINE UN 0 SE MARCHEAZA LINIA RESPECTIVA.
  //DACA SE GASESC MAI MULTI DE 1 ATUNCI SE TRECE PESTE.
  //DACA NU AU FOST MARCATE TOATE CELCULELE CU 0 SE REIA ALGORITMUL.
  for (int i = 0 ; i < G->nn ; i++ )
  {
      if( get_nr_zero_linie_NEMARC( G, i , marcat ) == 1 )
      {
          save = poziton_z_linie( G , i , marcat );
          umple_coloana( marcat , save );
          if( marcat->Ma[i][save] == 2 )
              marcat->Ma[i][save] = 5;
          else 
              marcat->Ma[i][save] = 3;
          count++;
      }   
  }

  for (int i = 0 ; i < G->nn ; i++ )
  {
      if( get_nr_zero_coloana_NEMARC( G, i , marcat ) == 1 )
      {
          save = poziton_z_coloana( G , i , marcat);
          marcat->Ma[save][i] = 3;

          umple_linie( marcat , save );
          
          if( marcat->Ma[save][i] == 2 )
              marcat->Ma[save][i] = 5;
          else 
              marcat->Ma[save][i] = 3;
           
          count++;
      }   
  }
  
total = nr_z_total(G , marcat );
if( total != 0 ) goto pass;

return count; 
}

void get_min_marcat_solve(TGraphM *G , TGraphM *marcat )
{
  //COUNT VA PRIMI VALOAREA MINIMICA DIN TOATE ELEMENTELE NEMARCATE.
  //SE VA SCADEA DIN FIECARE ELEMENT NEMARCAT.
  //SE VA ADUNA LA FIECARE INTERSECTIE A LINILOR.
  int count = 100000;
  for (int i = 0 ; i < G->nn ; i++ )
  {
     for (int j = 0 ; j < G->nn ; j++ )
     { 
        if( count > G->Ma[i][j] && marcat->Ma[i][j] == 0 && G->Ma[i][j] != 0)
            count = G->Ma[i][j];      
     }
  }

  for (int i = 0 ; i < G->nn ; i++ )
  {
     for (int j = 0 ; j < G->nn ; j++ )
     { 
        if( marcat->Ma[i][j] == 0 )
            G->Ma[i][j] = G->Ma[i][j] - count;
        if( marcat->Ma[i][j] == 2 )
            G->Ma[i][j] = G->Ma[i][j] + count;
     }
  }

}

//GOLOSESTE MATRICEA DE MARCAJE.
void clear_marcat(TGraphM* marcat )
{

  for (int i = 0 ; i < marcat->nn ; i++ )
  {
     for (int j = 0 ; j < marcat->nn ; j++ )
     {
        marcat->Ma[i][j] = 0;
     } 
  }

}

//CALCULEAZA SUMA.
int get_sum(TGraphM* G , TGraphM* marcat )
{
  int sum = 0;
   for (int i = 0 ; i < G->nn ; i++ )
   {
       for (int j = 0 ; j < G->nn ; j++ )
       {
           if( marcat->Ma[i][j] == 3 || marcat->Ma[i][j] == 5 )
           sum += G->Ma[i][j];
       }
   }

return sum;  
}

//FUNCTIA PRINCIPALA A AGLORITMULUI
int calculeaza_suma( TGraphM *G )
{

 //SE SALVEAZA MATRICEA.
 TGraphM copy_Matrix = copy_Mat(G);
 TGraphM marcat;
 int count;
 int sum = 0;

 alloc_matrix(&marcat , G->nn );

 //SE FAC ZEROURILE PE LINIE SI COLOANA.
 for (int i = 0 ; i < copy_Matrix.nn ; i++ )
 {
     get_zero_linie(&copy_Matrix, i );     
 }
 
 for (int i = 0 ; i < copy_Matrix.nn ; i++ )
 {   
     if( calculeaza_min_coloana(&copy_Matrix, i ) != 0 )
         get_zero_coloana(&copy_Matrix, i );     
 }
 
 //SE MARCHEAZA LINILE
 count = marcheaza_linii(&copy_Matrix , &marcat);

 //DACA NUMARUL DE 0 MARCATE NU CORESPUNDE CU NR DE LINII SE REPETA ALG.
 while ( count < G->nn )
 {
   //SE FACE UN NOU ZERO.
   get_min_marcat_solve(&copy_Matrix , &marcat);
   clear_marcat(&marcat);
   //SE MARCEAZA IAR LINILIE.
   count = marcheaza_linii(&copy_Matrix , &marcat);
 
 }
 
 //CALCULEAZA SUMA.
 sum = get_sum(G , &marcat );
 free_matrix(&copy_Matrix);
 free_matrix(&marcat);

return sum;
}

int solve(char *testInputFileName) 
{

  int number = 0;  
  int suma;
  int cost;
  //DESCHIDE FISIERUL
  FILE* file = fopen(testInputFileName, "rt");

  fscanf( file , "%d" , &number );
    
  TGraphM MATRIX;
  //ALOCA MATRICEA
  alloc_matrix(&MATRIX , number );

  //SE CITESC INFORMATILE
  for (int i = 0 ; i < MATRIX.nn ; i++ )
  {
     for (int j = 0 ; j < MATRIX.nn ; j++ )
     { 
       fscanf( file , "%d" , &cost );
       insert_edge_matrix(&MATRIX, i , j , cost );   
     }
  }

  //SE CALCULEAZA SUMA.
  suma = calculeaza_suma(&MATRIX); 
  free_matrix(&MATRIX);
  fclose(file);

return suma;
}

#endif
