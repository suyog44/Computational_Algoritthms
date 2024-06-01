#include <stdio.h>

int
main(int argc, char **argv)
{
	int var = -1;
	int var2 = var>>1; //Arithmetic right shift by 1
	int var3 = var/2;  //Division

	unsigned int va = 10;
	unsigned int va1 = va>>1; //logical right shift by 1
	unsigned int va2 = va/2;  //Division
	
	printf("Signed values: %d %d\n", var2, var3);
	printf("Unsigned values: %u %u\n", va1, va2);

	return 0;
}
