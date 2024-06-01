#include <stdio.h>
#include <stdint.h>

int
main(int argc, char **argv)
{
	uint32_t variable= 0x0D0C0B0A;
	char c = *(char *)&variable;
	printf("MSB:= 0x%02x\n",c);

	unsigned char *p = (unsigned char *)&variable;
	if(p[0]==0x0D && p[1]==0x0C && p[2]==0x0B && p[3]==0x0A)
		printf("Machine is Little Endian\n");
        else if(p[0]==0x0A && p[1]==0x0B && p[2]==0x0C && p[3]==0x0D)
                printf("Machine is Big Endian\n");
	else
		printf("Unknown Machine\n");

	return 0;

}
