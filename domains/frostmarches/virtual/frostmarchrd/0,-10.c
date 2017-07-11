#include <lib.h>
#include <domains.h>
inherit FROSTMARCHES_VIRTUAL+"frostmarchrd";
int DomainCheck();

static void create(int x, int y) {
  ::create(0, -10);
  RemoveExit("south");
  RemoveExit("north");
  AddExit("north", FROSTMARCHES_VIRTUAL "frostmarchrd/0,-9");
  AddExit("south", BARIA_VIRTUAL "jungle/-10,10", (: DomainCheck :) );    
  SetupRoom(0,-10);
 }

int DomainCheck() {
  if (!OPEN_BARIA)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_BARIA;  
}
