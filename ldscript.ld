ENTRY(Reset_Handler)

_flash_data_start = LOADADDR(.data);

_stack_end = ORIGIN(sram) + LENGTH(sram);

MEMORY {
  flash (rx) : o = 0x08000000, l = 512k
  sram (wx) : o = 0x20000000, l = 192k
  shared (wx) : o = 0x20030000, l = 10k
}

SECTIONS {
  .text : {
    . = ALIGN(4);
    KEEP(* (.vector_table))
    * (.text*)
    . = ALIGN(4);
  } >flash

  .rodata : {
    . = ALIGN(4);
    * (.rodata*)
    . = ALIGN(4);
  } >flash

  .data : {
    . = ALIGN(4);
    _sram_data_start = .;
    * (.data*)
    . = ALIGN(4);
    _sram_data_end = .;
  } >sram AT>flash

  .bss : {
    . = ALIGN(4);
    _bss_start = .;
    * (.bss*)
    * (COMMON)
    . = ALIGN(4);
    _bss_end = .;
  } >sram

  MAPPING_TABLE (NOLOAD) : {
    * (MAPPING_TABLE)
  } >shared

  MB_MEM1 (NOLOAD) : {
    * (MB_MEM1)
  } >shared

  MB_MEM2 (NOLOAD) : {
    _MB_MEM2_start = .;
    * (MB_MEM2);
    _MB_MEM2_end = .;
  } >shared
}
