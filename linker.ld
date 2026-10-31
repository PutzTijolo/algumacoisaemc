OUTPUT_FORMAT("binary")
SECTIONS
{
    . = 0x7C00;
    
    .text : { *(.text) }
    .data : { *(.data) }
    .rodata : { *(.rodata) }

    . = 0x7C00 + 510;
    .boot_signature : { *(.boot_signature) }
}