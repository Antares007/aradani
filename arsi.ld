SECTIONS
{
  .text : {
    *(.text.begin)
    *(.text)
  }
  .data ALIGN(0x1000) : {
    *(.data)
    *(.data.*)
    *(.rodata)
    *(.rodata.*)
    *(.bss)
  }
  .text.end ALIGN(0x1000) : {
    *(.text.end)
  }
}
