SECTIONS
{
  .text : {
    *(.text.begin)
    *(.text)
  }
  .data ALIGN(0x10) : {
    *(.data)
    *(.data.*)
    *(.rodata)
    *(.rodata.*)
    *(.bss)
  }
  .text.end ALIGN(0x10) : {
    *(.text.end)
  }
}
