#include<stdio.h>
#include<malloc.h>
#include<fcntl.h>

void tes_segmant(void)
{
	char *p;
	p=0;
	*p='a';
}

typedef void (*undef_instruction_jump)(void);
/*instruction exception*/
void test_undef_instruction()
{
//	unsigned int instruction_array[12] = {0};
	unsigned int *instruction_array;
	unsigned int instruction_arres;
	undef_instruction_jump * test_func;

	instruction_array = malloc(12*4);
	instruction_array[0] = 0x89c4;
	instruction_arres = 0x89c0;
#if 0
	asm (
		  "ldr r3, %0\n"
		  "blx r3\n"
		  :"+m"(instruction_arres)
		);
#else
	asm (
		  "ldr r3, %0\n"
		  "bl #35252"
		  :"+m"(instruction_arres)
		);
			
#endif

	//test_func = instruction_array;
	//(*test_func)();
}
#if 0
void tes_foalt(void)
{
	double a,b,c;
	a = 23.543;
	b = 323.234;
	c = b/a;
	printf("the 13/2 = %f\n", c);
	printf("hello world !\n");
}
#endif

int test_file_read_write(void)
{
#if 0
	int fd = open("test.out", O_RDONLY);
	char buf[128];
	int size;

	if (fd <= 0) {
		printf("open err\n");
		return 1;
	}
		printf("fd:%d\n", fd);
		size = read(fd, buf, 128); 
		printf("read:%d\n", size);
	close(fd);
#endif
}


void dump_call(int c)
{
	int a;
	a=c+1;
	printf("dump_call\n");
#if 0
	if (a > 10) {
		test_undef_instruction();
		return;
	}
#endif
	dump_call(a);
}
int main(int args, char *argv[])
{
#if 0
	int cnt = 0;
	int flag_cnt;
	char test_str[]="asfasfasfasf";
	printf("test\n");
	while(1) {
		void *mem_p;
		mem_p = malloc(102);
		cnt++;
		flag_cnt++;
		if (mem_p) {
				memcpy(mem_p, test_str,10);
			if(flag_cnt > 10000 * 40) {
				printf("malloc 1MB mem\n");
				flag_cnt = 0;
				system(" cat /proc/meminfo");
				sleep(1);
			}
		}
	}
#else
	//while(1)
	//	test_file_read_write();
	printf("test\n");
	//0tes_foalt();
	//tes_segmant();
	test_undef_instruction();
	//dump_call(0);
#endif
	return 0;
}
