#include <lib.h>
#include <domains.h>
inherit "/domains/gurov/virtual/gurovrd";
int DomainCheck();

static void create(int x, int y) {
  ::create(-99, 0);
  RemoveExit("west");
  AddExit("west", FROSTMARCHES_VIRTUAL "frostmarchrd/0,49", (: DomainCheck :) );    
  SetupEncounters(-99,0);
}

int DomainCheck() {
  if (!OPEN_FROSTMARCHES)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_FROSTMARCHES;  
}