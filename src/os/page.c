#include <stdint.h>

static uint32_t pages_free = 0;
static uint32_t pages_total = 0;

static uint32_t *freemap = 0;
static uint32_t freemap_cells = 0;

#define CELL_BITS (8 * sizeof(*freemap))
#define PAGE_SIZE 0x1000
void page_init(void *freemap, uint64_t size) {
  int i;

  pages_total = size / PAGE_SIZE;
  pages_free = pages_total;
  uint32_t freemap_bits = pages_total;
  uint32_t freemap_bytes = 1 + freemap_bits / 8;
  freemap_cells = 1 + freemap_bits / CELL_BITS;
  uint32_t freemap_pages = 1 + freemap_bytes / PAGE_SIZE;
  memset(freemap, 0xff, freemap_bytes);
  for (i = 0; i < freemap_pages; i++) page_alloc(0);
}

void page_stats(uint32_t *nfree, uint32_t *ntotal) {
  *nfree = pages_free;
  *ntotal = pages_total;
}

void *page_alloc(bool zeroit) {
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
          void *pageaddr =
              (pagenumber << PAGE_BITS) + (void *)MAIN_MEMORY_START;
          if (zeroit)
            memset(pageaddr, 0, PAGE_SIZE);
          pages_free--;
          return pageaddr;
        }
      }
    }
  }
  printf("memory: WARNING: everything allocated\n");
  halt();
  return 0;
}

void page_free(void *pageaddr) {
  uint32_t pagenumber = (pageaddr - (void *)MAIN_MEMORY_START) >> PAGE_BITS;
  uint32_t cellnumber = pagenumber / CELL_BITS;
  uint32_t celloffset = pagenumber % CELL_BITS;
  uint32_t cellmask = (1 << celloffset);
  freemap[cellnumber] |= cellmask;
  pages_free++;
}

