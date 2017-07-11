#include <lib.h>
#include <domains.h>
inherit SOUTHERN_COAST_VIRTUAL "havenroad";
int DomainCheck();

static void create(int x, int y) {
  ::create(-36, 0);
  RemoveExit("southwest");
  RemoveExit("east");
  AddExit("east", SOUTHERN_COAST_VIRTUAL "havenroad/-35,0");
  AddExit("southwest", CRYSTAL_REACHES_VIRTUAL "llorykroad/15,0", (: DomainCheck :) );    
  SetupRoom(-36,0);  
}

int DomainCheck() {
  if (!OPEN_CRYSTAL_REACHES)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_CRYSTAL_REACHES;  
}
