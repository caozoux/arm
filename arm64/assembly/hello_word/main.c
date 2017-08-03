#include <stdio.h>
#define TX_ADDR 		(0xe6e8800c)
#define TX_STATE  		(0xe6e88010)

#define SCI_TDRE	(0x80)	/* Transmit Data Register Empty */

#define io_writeb(addr, val) 		*((volatile char*) addr) =val
#define io_readb(addr) 		 		*((volatile char*)) addr

#define io_write(addr, val)  		*(volatile unsigned int*) addr =val
#define io_read(addr)  				*(volatile unsigned int*) addr

#define TRAN_TO_CH(ch) (ch >9) ? (ch-11+'a') : (ch-1+'0')
void put_char(unsigned char ch);

void data_format(unsigned int data, int size)
{
	char val;
	int i;
	for (i = 0; i < size; ++i) {
		val = (data>>((size-i-1)*4))&0xf;
		val =TRAN_TO_CH(val);
		put_char(val);
	}
}

void data_format8(unsigned char data)
{
	data_format(data,2);
}

void data_format16(unsigned short int data)
{
	data_format(data,4);
}

void data_format32(unsigned int data)
{
	data_format(data,8);
}

#if 0
void data_format16(unsigned char ch)
void data_format32(unsigned char ch)
void data_format64(unsigned char ch)
#endif

void print(unsigned char *data, int size)
{
	int i;
	for (i = 0; i < size; ++i) {
		put_char(data[i]);
	}
}

void put_char(unsigned char ch)
{
	unsigned char test = ch;
	unsigned int status;
	do {
		status = io_read(TX_STATE);
		ch++;
	} while(!(status|SCI_TDRE));

	io_writeb(TX_ADDR, ch);
}

void test1(void)
{
	unsigned char val =0xef;
	char c='a';
	data_format8(val);
	data_format16(0x1a3b);
	data_format32(0xf23eac0);
	while(1) {
		//io_writeb(TX_ADDR, c);
		put_char(c);
	}
}

void test(void)
{
	while(1) {
		io_writeb(TX_ADDR, 'a');
	}
}
