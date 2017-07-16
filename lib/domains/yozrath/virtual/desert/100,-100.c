#include <lib.h>
#include <domains.h>
inherit "/domains/yozrath/virtual/desert";
int DomainCheck();

static void create(int x, int y) {
  ::create(100, -100);
  RemoveExit("southeast");
  AddExit("southeast", HAVENWOOD_VIRTUAL "havenwoodroad/155,155", (: DomainCheck :) );    
  SetRoom(100,-100);
}

int DomainCheck() {
  if (!OPEN_HAVENWOOD)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_HAVENWOOD;  
}
