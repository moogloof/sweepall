SECTIONS
{
	.text : {
		KEEP(*(.vectors))
		KEEP(*(.text.boot))
		*(.text .text.*)
	}
	.rodata : {
		*(.rodata .rodata.*)
	}
	.data : {
		*(.data)
	}
	.bss (NOLOAD) : {
		. = ALIGN(16);
		_sbss = .;
		*(.bss .bss.*)
		_ebss = .;
	}
}
