#include "../oars.h"
#include <stdlib.h>

static void *freemap;
static Q_t freemap_cells[14];

#define CELL_BITS ((Q_t)(8 * sizeof(*freemap_cells)))
#define PAGE_SIZE ((Q_t)0x1000)
#define PAGE_BITS ((Q_t)12)
#define CELLS_COUNT ((Q_t)(sizeof(freemap_cells) / sizeof(*freemap_cells)))

void page_init() {
  freemap = malloc(PAGE_SIZE * 8 * sizeof(freemap_cells));
  for (Q_t i = 0; i < CELLS_COUNT; i++)
    freemap_cells[i] = (Q_t)0xffffffffffffffff;
}
void *page_alloc() {
  for (Q_t i = 0; i < CELLS_COUNT; i++) {
    if (freemap_cells[i] != 0) {
      for (Q_t j = 0; j < CELL_BITS; j++) {
        Q_t cellmask = ((Q_t)1 << j);
        if (freemap_cells[i] & cellmask) {
          freemap_cells[i] &= ~cellmask;
          Q_t pagenumber = i * CELL_BITS + j;
          void *pageaddr = (pagenumber << PAGE_BITS) + freemap;
          return pageaddr;
        }
      }
    }
  }
  printf("memory: WARNING: everything allocated\n");
  return 0;
}
void page_free(void *pageaddr) {
  Q_t pagenumber = (pageaddr - freemap) >> PAGE_BITS;
  if (pagenumber >= (8 * sizeof(freemap_cells)))
    return printf("Señor, a page address is not from our memory space.\n"), exit(9);
  Q_t cellnumber = pagenumber / CELL_BITS;
  Q_t celloffset = pagenumber % CELL_BITS;
  Q_t cellmask = ((Q_t)1 << celloffset);
  if (freemap_cells[cellnumber] & cellmask)
    return printf("Señor, a page is already free.\n"), exit(9);
  freemap_cells[cellnumber] |= cellmask;
}
