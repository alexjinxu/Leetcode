/*

29. Divide Two Integers

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

Subscribe to see which companies asked this question.


*/






void reverse(char* s, int i, int j )
{
	char temp;
	while(i < j)
	{
		temp = s[i];
		s[i++] = s[j];
		s[j--] = temp;
	}
}


void reverseWords(char *s) {
    int i , j , count;
	char* P, *Q;
	char *Head;
    if (s == NULL) return;
	P=s;
	j=i=count=0;

	while (P[i] != '\0')
	{
		while (P[i]==' ')
		{
			i ++;
		}

		j=i;

		while (P[j] !=' ' && P[j] !='\0' )
		{
			j++;
		}
		
        
		reverse(s, i, j-1);

		if(count < i)
		{
           while(i < j)	P[count++]=P[i++];

		}
		
		count += j-i;

		i = j;

		while (P[i]==' ')
		{
			i ++;
		}
		if ( P[i] == '\0')
		{
			P[count]='\0';
		}
		else
		{
			P[count++] = ' ';
		}


	}

	reverse(s, 0, count-1);
}