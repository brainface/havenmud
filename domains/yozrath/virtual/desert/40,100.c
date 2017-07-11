#include <lib.h>
#include <domains.h>
inherit "/domains/yozrath/virtual/desert";
int DomainCheck();

static void create(int x, int y) {
  ::create(40, 100);
  RemoveExit("north");
  AddExit("north", GUROV_AREAS "gurthlad/rooms/room45", (: DomainCheck :) );    
  SetRoom(40,100);
}

int DomainCheck() {
  if (!OPEN_GUROV)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_GUROV;  
}
