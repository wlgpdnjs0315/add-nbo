#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
	
	//write_0x12345678();
	if(argc <3){
		printf("Usage : %s <filename1> <filename2>\n", argv[0]);
		return 0;
	}
	
	FILE *bin1, *bin2;
	uint8_t buf1[4], buf2[4];

	bin1 = fopen(argv[1], "rb");
	bin2 = fopen(argv[2], "rb");
	
	fread(buf1, 1, 4, bin1);
	fread(buf2, 1, 4, bin2);

	uint32_t* tmp1 = reinterpret_cast<uint32_t*>(buf1);
	uint32_t* tmp2 = reinterpret_cast<uint32_t*>(buf2);
	uint32_t n1 = htonl(*tmp1);
	uint32_t n2 = htonl(*tmp2);
	uint32_t sum = n1 + n2;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, sum, sum);
	return 0;

} 
