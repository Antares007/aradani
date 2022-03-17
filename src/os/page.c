#include <stdint.h>
#include <stdio.h>
#include <string.h>

static uint32_t pages_free = 0;
static uint32_t *freemap = 0;
static uint32_t freemap_cells = 0;

#define CELL_BITS (8 * sizeof(*freemap))
#define PAGE_SIZE 0x1000
#define PAGE_BITS 12

void *page_alloc() {
  if (!freemap) {
    printf("memory: not initialized yet!\n");
    return 0;
  }
  for (uint32_t i = 0; i < freemap_cells; i++) {
    if (freemap[i] != 0) {
      for (uint32_t j = 0; j < CELL_BITS; j++) {
        uint32_t cellmask = (1 << j);
        if (freemap[i] & cellmask) {
          freemap[i] &= ~cellmask;
          uint32_t pagenumber = i * CELL_BITS + j;
          void *pageaddr = (pagenumber << PAGE_BITS) + freemap;
          pages_free--;
          return pageaddr;
        }
      }
    }
  }

  printf("memory: WARNING: everything allocated\n");
  return 0;
}

void page_init(void *_freemap, uint64_t size) {
  freemap = _freemap;
  int i;
  uint32_t pages_total = size / PAGE_SIZE;
  pages_free = pages_total;
  uint32_t freemap_bits = pages_total;
  uint32_t freemap_bytes = 1 + freemap_bits / 8;
  freemap_cells = 1 + freemap_bits / CELL_BITS;
  uint32_t freemap_pages = 1 + freemap_bytes / PAGE_SIZE;
  memset(freemap, 0xff, freemap_bytes);
  for (i = 0; i < freemap_pages; i++)
    page_alloc();
}

void page_free(void *pageaddr) {
  uint32_t pagenumber = (pageaddr - (void *)freemap) >> PAGE_BITS;
  uint32_t cellnumber = pagenumber / CELL_BITS;
  uint32_t celloffset = pagenumber % CELL_BITS;
  uint32_t cellmask = (1 << celloffset);
  freemap[cellnumber] |= cellmask;
  pages_free++;
}
