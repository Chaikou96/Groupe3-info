//Sébastien Rouff
//16/12/2018
//TD3_challenge.c

#include "algebre.h"
#include "TD3_challenge.h"
#include <stdio.h>

float absolute (float x)
{
	if (x < 0)
		return (-x);
	return x;
}

int coef_max (mymatrix *C, int pivot, int n, int k)
//Recherche la ligne pivot de plus grand coeficient et la remonte à 
//la i_ème ligne
{
	int i;
	int j;
	int i_max = pivot;
	float max = absolute((C->M)[pivot][pivot]);
	float tmp;
	
	//Recherche du plus grand coef
	for (i = pivot + 1; i < n; i++)
	{
		if (max < absolute((C->M)[i][pivot]))
		{
			max = absolute((C->M)[i][pivot]);
			i_max = i;
		}
	}

	//Remontée de la ligne à plus grand coef
	for (j = 0; j < n + k; j++)
	{
		tmp = (C->M)[pivot][j];
		(C->M)[pivot][j] = (C->M)[i_max][j];
		(C->M)[i_max][j] = tmp;
	}
	return i_max;
}

int gauss(mymatrix *C, int n, int k)
{
	int pivot, i, j;
	float coef;
	
	//On fait n - 1 pivots
	for (pivot = 0; pivot < n - 1; pivot++)
	{
		coef_max(C, pivot, n, k);
		//On applique le pivot sur toutes les lignes en dessous
		for (i = pivot + 1; i < n; i++)
		{
			if ((C->M)[pivot][pivot] != 0)
			{
				coef = (C->M)[i][pivot] / (C->M)[pivot][pivot];
				//L'opération se fait sur chaque élément de la ligne
				for (j = 0; j < n + k; j++)
				{
					(C->M)[i][j] -= coef * (C->M)[pivot][j];
				}
			}
		}
	}
	return inversible(C, n);
}

int inversible (mymatrix *C, int n)
{
	int i, j;
	
	for (i = 0; i < n; i++)
	{
		if ((C->M)[i][0] == 0)
		{
			for (j = 1; j < n; j++)
			{
				if ((C->M)[i][j] != 0)
					break;
			}
			if (j == n)
				return 0;
		}
	}
	for (j = 1; j < n; j++)
	{
		if ((C->M)[0][j] == 0)
		{
			for (i = 1; i < n; i++)
			{
				if ((C->M)[i][j] != 0)
					break;
			}
			if (i == n)
				return 0;
		}
	}
	return 1;
}

int remontee_gauss(mymatrix *C, int n, int k)
{
	int i, j, l;
	float tmp;
	
	//On part de la dernière ligne et on remonte
	for (i = n - 1; i >= 0; i--)
	{
		if ((C->M)[i][i] != 0)
		{
			tmp = (C->M)[i][i];
			//On applique la transformation aux nombres à droite
			//de la diagonale (il y a déjà des 0 à gauche)
			for (j = i; j < n + k; j++)
			{
				(C->M)[i][j] /= tmp;
			}
			for (j = i + 1; j < n; j++)
			{
				if ((C->M)[j][j] != 0)
				{
					for (l = i + 1; l < n + k; l++)
					{
						(C->M)[i][l] -= (C->M)[i][j] / (C->M)[j][j];
					}
				}
			}
		}
	}
	return 0;
}
