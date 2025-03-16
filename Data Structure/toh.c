#include<stdio.h>
void toh(char from,char aux, char to, int n)
{
	if(n==1)
	{
		printf("Shift dish %d from %c to %c\n",n,from,to);
	}
	else{
		toh(from,to,aux,n-1);
		printf("Shift dish %d from %c to %c\n",n,from,to);
		toh(aux,from,to,n-1);
	}
}
int main()
{
	int n=3;
	char from='A', to='C', aux='B';
	toh(from,aux,to,n);
	return 0;
}