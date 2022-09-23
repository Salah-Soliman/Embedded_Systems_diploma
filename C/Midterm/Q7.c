#include <stdio.h>

int sum=0;
void add_sequance(int num)
{

	if(num>0)
	{
		sum+=num;
		add_sequance(num-1);
	}
	else
	{
		printf("%d",sum);
	}

}

int main ()
{
	add_sequance(100);
}

