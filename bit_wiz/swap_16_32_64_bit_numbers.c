#include <stdio.h>
#include <stdlib.h>


#define byteswap16(value) (((value&0x00ff) << 8) | ((value&0xff00) >> 8))
#define IGNORE_SPACE 2

#define reversebits(value) ((value&0x80)>>7|\
		(value&0x40)>>5|\
		(value&0x20)>>3|\
		(value&0x10)>>1|\
		(value&0x08)<<1|\
		(value&0x04)<<3|\
		(value&0x02)<<5|\
		(value&0x01)<<7)

int
main(int argc, char**argv)
{
	if(argc<2)
	{
		printf("Usage: ./a.out <0x1234>");
		return 0;
	}

	unsigned short val = atoi(argv[1]+IGNORE_SPACE);
	printf("Original val: 0x%04x\n Byteswap: 0x%04x\n", val, byteswap16(val));
	printf("Original val: 0x%04x\n Byteswap: 0x%04x\n", val, reversebits(val));
	return 0;
}
