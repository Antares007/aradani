SECTIONS
{
  .text : {
    *(.text.begin)
    *(.text)
  }
  .data ALIGN(0x1000) : {
    *(.data)
    *(.bss)
  }
  .text.end ALIGN(0x1000) : {
    *(.text.end)
  }
}
