#include <lib.h>
#include <domains.h>
inherit "/domains/havenwood/virtual/havenwoodroad.c";
int DomainCheck();

static void create(int x, int y) {
  ::create(165, 165);
  AddExit("north", ESTERGRYM_VIRTUAL "northroad/0,0", (: DomainCheck :) );  
  AddExit("east",  HAVENWOOD_VIRTUAL "parvaroad/0,237");
  SetInventory( ([
    HAVENWOOD_VIRTUAL "sign/havenwoodroad165165" : 1,
  ]) );
}

int DomainCheck() {
  if (!OPEN_ESTERGRYM)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_ESTERGRYM;  
}
