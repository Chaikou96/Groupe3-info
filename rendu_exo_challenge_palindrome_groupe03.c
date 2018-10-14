typedef struct m {
	int val ;
	struct m * suite ;
} t_maillon ;

typedef t_maillon * liste ;

/* question 1 */

liste* quick_sort_liste_chainee(liste *ptr_deb, liste *ptr_fin)
{

	liste *ptr_m, piv, *ptr_pre, *ptr_piv;
	
	ptr_m = ptr_deb -> suite;
	ptr_pre = ptr_deb;
	ptr_piv = ptr_deb;
	
	while (ptr_m -> suite != ptr_fin)
	{
		if (ptr_m -> val < ptr_piv -> val)
		{
			ptr_pre -> suite = ptr_m -> suite;
			ptr_m -> suite = ptr_deb;
			ptr_deb = ptr_m;
		}
		*ptr_m = *(*ptr_pre).suite;
	}
	if (ptr_m -> val < ptr_piv -> val)
	{
		ptr_pre -> suite = ptr_m -> suite;
		ptr_m -> suite = ptr_deb;
		ptr_deb = ptr_m;
	}
	
	ptr_m = ptr_deb;
	if (ptr_piv -> suite != ptr_deb -> suite)
	{
		ptr_m = quick_sort_liste_chainee(ptr_piv -> suite , ptr_fin);
		ptr_piv -> suite = ptr_m;
		ptr_m = quick_sort_liste_chainee(ptr_deb, ptr_piv);
	}
	return(ptr_m);
}

/* question 2 */

//Fonction qui inverse une liste sans recopie
liste inversecopie(liste l) {
	liste res = NULL ;
	while(l) {
		liste local = l ;
		l = l->suite ;
		local->suite = res ;
		res = local ;
	} 
	return res ;

//Fonction qui permet de savoir si une liste est un palindrome
int palindrome(liste l) {
	liste l2 = inversecopie(l) ;
	if(palindrome_aux(l,l2)) return 1 ;
	else return 0 ;

//Fonction récursive
int palindrome_aux(liste l, liste l2) {
	int res ;
	while(l2 && l) {
		if(l2->val == l->val){
			l2 = l2->suite ;
			l = l->suite ;
			res = 1 ;
		}
		else{
			res = 0 ;
			return res ;
		}
	}
	return res ;
}