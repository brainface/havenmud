#include <lib.h>
#include <domains.h>
#include "../vimp.h"
inherit VIMP_DIR "vimp";
int DomainCheck();

static void create(int x, int y) {
  ::create(0, 6);
  RemoveExit("northeast");
  RemoveExit("northwest");
  AddExit("north", SOUTHERN_COAST_VIRTUAL "havenroad/0,0", (: DomainCheck :) );
  AddExit("east", "/domains/peninsula/areas/wood/room/entrance");
  AddExit("west", PENINSULA_AREAS "sulumus/room/path");
  SetInventory( ([
    PENINSULA_VIRTUAL "npc/wandering_man" : 1,
  ]) );
  Setup();
}

int DomainCheck() {
  if (!OPEN_SOUTHERN_COAST)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_SOUTHERN_COAST;  
}
