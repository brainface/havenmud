#include <lib.h>
#include <domains.h>
inherit "/domains/crystal_reaches/virtual/llorykroad";
int DomainCheck();

static void create(int x, int y) {
  ::create(15, 0);
  RemoveExit("northeast");
  AddExit("northeast", SOUTHERN_COAST_VIRTUAL "havenroad/-36,0", (: DomainCheck :) );    
}

int DomainCheck() {
  if (!OPEN_SOUTHERN_COAST)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_SOUTHERN_COAST;  
}
