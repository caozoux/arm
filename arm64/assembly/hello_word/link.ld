ENTRY(_start)
SECTIONS
{
    /* This says where `.text` will go in the executable. */
    . = 0x49000000;
    .text :
    {
        *(.test)
    }

	.data :
	{
		* (.data)
	}

	_bss_start = . ;
	.bss :
	{
		* (.bss)
	}
	_bss_end = . ;

}
