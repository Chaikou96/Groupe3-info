#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 9
typedef struct zMaillon {
	int valeur;
	struct zMaillon *suite;
} maillon, *pile;

//Fonction qui crée une pile vide
pile create_empty_stack(void) {return NULL ;}

//Fonction qui vérifi si une pile est vide ou non 
int is_empty_stack(pile p) {return (p==NULL) ;}
 
//Fonction qui permet de retourner la valeur de la tête de la pile
int tete_pile(pile p) {
	assert(!is_empty_stack(p)) ;
	return (p->valeur) ;
}

//Fonction qui permet de retourner la fin d'une pile
pile queue_pile(pile p) {
	assert(!is_empty_stack(p)) ;
	return (p->suite) ;
}

//Fonction qui empile(ajoute) un élément
pile push(pile p, int val) {
	pile new=malloc(sizeof(maillon)) ;
	new->valeur=val ;
	new->suite=p ;
	return new ;
}

//Fonction qui dépile(supprime) un élément
pile pop(pile p) {
  pile *tmp = p->suite ;
  free(p) ;
  return tmp ;
}

//Fonction qui permet d'accéder au dernier élément
int top(pile p) {return p->valeur ;}

//Fonction qui affiche la pile
void affichage(pile p) {
	if(is_empty_stack(p)) printf("La pile est vide");
	do {
		printf("%d ", p->valeur);
		p = pop(p) ;
	}while(!(is_empty_stack(p))) ;
	printf("\n") ;
}

//Fonction qui effectue l'addition des valeurs
pile addition(pile p) {
  int res, val1, val2 ;
  
  val1 = top(p) ;
  p = pop(p) ;
  val2 = top(p) ;
  p = pop(p) ;
  
  res = val2 + val1 ;
  p = push(p,res);
  return p;
}

//Fonction qui effectue la multiplication des valeurs
pile multiplication(pile p) {
  int res, val1, val2 ;
  
  val1 = top(p) ;
  p = pop(p) ;
  val2 = top(p) ;
  p = pop(p) ;
  
  res = val2 * val1 ;
  p = push(p,res);
  return p;
}

//Fonction qui effectue les calculs en postfixée
int calcul(char T[], int n, pile p) {
  int i, char_to_int;
  for (i = 0; i<N; i++) {
    if (T[i] == '+') p = addition(p);
    else if (T[i] == '*') p = multiplication(p);
    else {
      char_to_int = T[i] - 48;
      p = push(p,char_to_int);
    }
  }
  return top(p);
}


int main(void) {
  int res1, res2 ;
  char T1[N] = {'1','4','+','5','*','3','2','*','+'} ;
  char T2[N] = {'1','4','5','+','*','3','2','*','+'} ;
  
  pile p = create_empty_stack() ;
  res1 = calcul(T1,N,p) ;
  res2 = calcul(T2,N,p) ;
  printf("tableau T1 : %d\n", res1) ;
  printf("tableau T2 : %d\n", res2) ;
  
  p = push(p, 5) ;
  p = push(p, 7) ;
  p = push(p, 8) ;
  p = push(p, 23) ;
  p = push(p, 11) ;
  p = push(p, 1996) ;
  affichage(p);
  
  return 0 ;
}

