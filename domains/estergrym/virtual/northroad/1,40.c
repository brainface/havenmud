#include <lib.h>
#include <domains.h>
inherit "/domains/estergrym/virtual/northroad";
int DomainCheck();

static void create(int x, int y) {
  ::create(1, 40);
  RemoveExit("west");
  AddExit("west", GUROV_VIRTUAL "gurovrd/58,0", (: DomainCheck :) );    
  Setup(1, 40);
}

int DomainCheck() {
  if (!OPEN_GUROV)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_GUROV;  
}
