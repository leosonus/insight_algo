#include <stdio.h>
#include <stdlib.h>

int rand_int(int n)
{
    return rand() % n;
}

int main() 
{
	int sex1, sex2;
	int birth1, birth2;
	int	count = 0;
	int boy = 0;

	while(count < 1000000) {
		sex1 = rand_int(2);
		sex2 = rand_int(2);

		birth1 = rand_int(7);
		birth2 = rand_int(7);

		if ((sex1 == 0 && birth1 == 2) || (sex2 == 0 && birth2 == 2))  {
		}
		else 
			continue;
		
		count++;

		if (sex1 ==0 && sex2 == 0)
			boy++;
	}
	printf("%d\n", boy);
	return 0;
}
