#include <lib.h>
#include <domains.h>
inherit "/domains/gurov/virtual/gurovrd";
int DomainCheck();

static void create(int x, int y) {
  ::create(58, 0);
  RemoveExit("east");
  AddExit("east", ESTERGRYM_VIRTUAL "northroad/1,40", (: DomainCheck :) );    
  SetupEncounters(58,0);
}

int DomainCheck() {
  if (!OPEN_ESTERGRYM)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_ESTERGRYM;  
}