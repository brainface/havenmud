#include <lib.h>
#include <domains.h>
inherit "/domains/baria/virtual/jungle";
int DomainCheck();

static void create(int x, int y) {
  ::create(-10, 10);
  RemoveExit("north");
  RemoveExit("east");
  RemoveExit("south");
  AddExit("north", FROSTMARCHES_VIRTUAL "frostmarchrd/0,-10", (: DomainCheck :) );    
  AddExit("east", BARIA_VIRTUAL "jungle/-9,10");
  AddExit("south", BARIA_VIRTUAL "jungle/-10,9");
  SetLongAndItems();
}

int DomainCheck() {
  if (!OPEN_FROSTMARCHES)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_FROSTMARCHES;  
}
