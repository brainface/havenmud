#include <lib.h>
#include <domains.h>
inherit "/domains/estergrym/virtual/northroad";
int DomainCheck();

static void create(int x, int y) {
  ::create(0, 0);
  RemoveExit("south");
  AddExit("south", HAVENWOOD_VIRTUAL "havenwoodroad/165,165", (: DomainCheck :) );  
  AddExit("northeast", ESTERGRYM_AREAS "kids/room/trail");  
  Setup(0, 0);
}

int DomainCheck() {
  if (!OPEN_HAVENWOOD)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_HAVENWOOD;  
}
