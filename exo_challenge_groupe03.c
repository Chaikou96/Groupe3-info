// principe de dichotomie utilise
int appartient_gr_03(int x,int *T1,int s1,int n1)
{
    int i=0,j=s1-1,m;
    if (x<T1[0]) return 0;
    if (x==T1[0]) return 1;
    if (x==T1[s1-1]) return 1;
    if (x>T1[s1-1]) return 0;
    do {
        m=(i+j)/2; // diviser le tableau en 2
        if (x<T1[m]) j=m;
        else i=m;
    }while (x!=T1[m]&& (j>i+1));
        if(x==T1[m]) return 1;
        else return 0;

}

void union_gr_03(int *T1, int s1, int n1, int *T2, int s2, int n2, int *T3, int s3, int *n3)
{
    int i=0, j=0, k=0;// initialisation des valeurs
    while ((i< s1)&& (j<s2))
    {
        if (T1[i]<T2[i]) T3[k++]=T1[i++];
        else T3[k++]=T2[j++];
    }
    while (j<s2) {
        T3[k++]=T2[j++];
    }
    while (i<s1){
        T3[k++]=T1[i++];
    }
}

void inter_gr_03(int *T1, int s1, int n1, int *T2, int s2, int n2, int *T3, int n3, int s3)
{
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	while (i < s1 && j < s2)
	{
		if (T1[i] < T2[j])
			i++;
		else if (T1[i] > T2[j])
			j++;
		else //T1[i] == T2[j]
		{
			T3[k] = T1[i];
			i++;
			j++;
			k++;
		}
	}
}

int inclus_gr_03(int *T1, int s1, int n1, int *T2, int s2, int n2)
{
	int i;

	if (T1[s1 - 1] < T2[0])
		return 0;
	if (T1[0] > T2[s2 - 1])
		return 0;
	for (i = 0; i < s2; i++)
	{
		if (!appartient_gr_03(T2[i], T1, s1, n1))
			return 0;
	}
	return 1;
}



