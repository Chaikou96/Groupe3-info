#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


typedef char Elt ;
typedef int bool ;
struct znoeud {
	Elt elt ;
	struct znoeud * fils_gauche ;
	struct znoeud * fils_droit ; } ; 
typedef struct znoeud noeud ;
typedef struct znoeud * arbre ;

//Fonction qui crée un arbre vide
arbre creer_arbre_vide (void) {
  return NULL ;
}

//Fonction qui permet de savoir si c'est l'arbre est vide ou non
bool est_arbre_vide(arbre a) {
  return (a == NULL) ;
}

//Fonction qui permet de savoir si c'est une feuille ou non
bool est_feuille(arbre a) {
  if (est_arbre_vide(a)) return 0 ;
  return (est_arbre_vide(a->fils_gauche) && est_arbre_vide(a->fils_droit)) ;
}

//Fonction qui permet de créer un arbre
arbre creer_arbre(Elt e, arbre fg, arbre fd) {
	arbre new ;
	new = (arbre)malloc(sizeof(arbre)) ;
	new->elt = e ;
	new->fils_gauche = fg ;
	new->fils_droit = fd ;
	return new ;
}

//Fonction qui permet de savoir si un noeud possede un fils gauche
arbre fils_gauche(arbre a) {
	assert(!(est_arbre_vide(a->fils_gauche))) ;
	return (a->fils_gauche) ;
}

//Fonction qui permet de savoir si un noeud possede un fils droit
arbre fils_droit(arbre a) {	
	assert(!(est_arbre_vide(a->fils_droit))) ;
	return (a->fils_droit) ;
}

//Fonction qui nous permet de récupérer l'élément d'un noeud
Elt racine(arbre a) {
  	assert(a) ;
  	return (a->elt) ;
}

//Fonction qui crée une feuille
arbre creer_feuille(Elt e) {
  return creer_arbre(e, creer_arbre_vide(), creer_arbre_vide()) ;
}

//Fonction serialisation
int serialisation_rec(arbre a, char s[], int *i) {
	if (est_arbre_vide(a)){
		s[*i] = '0' ;
		*i = *i + 1 ;
	}
  	else {
  		s[*i] = '1' ;
  		*i = *i + 1 ;
    	s[*i] = a->elt ;
    	*i = *i + 1;
    	serialisation_rec(a->fils_gauche, s, i) ;
    	serialisation_rec(a->fils_droit, s, i) ;
  	}
  	return (*i);
}

void serialisation(arbre a, char s[]) {
	int i = 0 ;
	i = serialisation_rec(a, s, &i) ;
	s[i] = '\0' ;
}

//Fonction deserialisation
arbre deserialisation_rec(char *s, int *i) {
	arbre A ;
	arbre B1, B2 ;
	Elt e ;
	
	if (s[*i] == '0') {
		*i = *i + 1 ;
		return (creer_arbre_vide()) ;
	}
	if (s[*i] == '1') *i = *i + 1 ;
	e = s[*i] ;
	*i = *i + 1 ;
	B1 = deserialisation_rec(s, i) ;
	B2 = deserialisation_rec(s, i) ;
	A = creer_arbre(e, B1, B2) ;
	return (A) ;
}

arbre deserialisation(char *s) {
	int i = 0 ;
	return deserialisation_rec(s, &i) ;
}

int main() {
	arbre A, B ;
	char s[] = "1a1b1c0001d1x001y00";
	char s1[100] ;
	char s2[100] ;
	
	A = creer_arbre('a', creer_arbre('b', creer_arbre('c', creer_arbre_vide(), creer_arbre_vide()), creer_arbre_vide()), creer_arbre('d', creer_arbre('x', creer_arbre_vide(), creer_arbre_vide()), creer_arbre('y', creer_arbre_vide(), creer_arbre_vide()))) ;
	serialisation(A, s1) ;
	printf("Sérialisation d'un arbre. La chaîne de caractères permettant d'encoder l'arbre 5 est : %s\n", s1) ;
	
	B = deserialisation(s);
	serialisation(B, s2) ;
	printf("Desérialisation d'un arbre. On prend le même exemple que celui ci dessus et on vérifie s'ils ont les mêmes caractères : %s\n", s2) ;
	
	return 0 ;
}

