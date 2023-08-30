#include <stdio.h>
#include <math.h>

int order(int x)
{
	int n = 0;
	while (x) {
		n++;
		x = x / 10;
	}
	return n;
}
int isArmstrong(int x)
{
	int n = order(x);
	int temp = x, sum = 0;
	while (temp) {
		int r = temp % 10;
		sum += pow(r, n);
		temp = temp / 10;
	}
	if (sum == x)
		return 1;
	else
		return 0;
}

// Driver Program
int main()
{

	int x = 1253;
	if (isArmstrong(x) == 1)
		printf("Amstrong number\n");
	else
		printf("Not Amstrong number\n");

	return 0;
}
true
