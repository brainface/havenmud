#include <lib.h>
#include <domains.h>
inherit FROSTMARCHES_VIRTUAL+"frostmarchrd";
int DomainCheck();

static void create(int x, int y) {
  ::create(0, 49);
  RemoveExit("east");
  RemoveExit("north");
  RemoveExit("south");
  AddExit("north", FROSTMARCHES_VIRTUAL + "frostmarchrd/0,50");
  AddExit("south", FROSTMARCHES_VIRTUAL + "frostmarchrd/0,48");
  AddExit("east", GUROV_VIRTUAL "gurovrd/-99,0", (: DomainCheck :) );    
  SetupRoom(0,49);
 }

int DomainCheck() {
  if (!OPEN_GUROV)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_GUROV;  
}