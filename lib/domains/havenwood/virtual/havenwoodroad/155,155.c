#include <lib.h>
#include <domains.h>
inherit "/domains/havenwood/virtual/havenwoodroad.c";
int DomainCheck();

static void create(int x, int y) {
  ::create(155, 155);
  AddExit("east", "/domains/havenwood/areas/wood/rooms/wood4", (: DomainCheck :) );
  AddExit("northwest", YOZRATH_VIRTUAL "desert/100,-100");
  SetInventory( ([
    HAVENWOOD_VIRTUAL "sign/havenwoodroad155155" : 1,
  ]) );
}

int DomainCheck() {
  if (!OPEN_YOZRATH)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_YOZRATH;  
}
