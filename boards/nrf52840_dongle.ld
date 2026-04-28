/* Linker script to configure memory regions. */

SEARCH_DIR(.)
GROUP(-lgcc -lc -lnosys)

MEMORY
{
  /* We leave  a 0x1000 kb margin between bootloader and usable flash
   * for safety.
   *
   * We also leave a 0x2000 kb margin between code and internal filesystem
   * for safety.
   */

  /* Leave space for an InternalFilesystem at 0xD2000 - 0xD9000
   */
  FLASH (rx)     : ORIGIN = 0x27000, LENGTH = 0xD0000 - 0x27000
  BOOTLOADER (rx) : ORIGIN = 0xE0000, LENGTH = 0x2000
  INTERNAL_FS     : ORIGIN = 0xD2000, LENGTH = 0x7000

  /* SRAM required by Softdevice depend on
   * - Attribute Table Size (Number of Services and Characteristics)
   * - Vendor UUID count
   * - Max ATT MTU
   * - Concurrent connection peripheral + central + secure links
   * - Event Len, HVN queue, Write CMD queue
   */ 
  RAM (rwx) :  ORIGIN = 0x20006000, LENGTH = 0x20040000 - 0x20006000
}

SECTIONS
{
  . = ALIGN(4);
  .svc_data :
  {
    PROVIDE(__start_svc_data = .);
    KEEP(*(.svc_data))
    PROVIDE(__stop_svc_data = .);
  } > RAM
  
  .fs_data :
  {
    PROVIDE(__start_fs_data = .);
    KEEP(*(.fs_data))
    PROVIDE(__stop_fs_data = .);
  } > RAM
} INSERT AFTER .data;

INCLUDE "nrf52_common.ld"
