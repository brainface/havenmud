#include <lib.h>
#include <domains.h>
inherit "/domains/havenwood/virtual/havenwoodroad.c";
int DomainCheck();

static void create(int x, int y) {
  ::create(126, 126);  
  AddExit("southwest", "/domains/southern_coast/virtual/havenroad/0,0", (: DomainCheck :) );
}

int DomainCheck() {
  if (!OPEN_SOUTHERN_COAST)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_SOUTHERN_COAST;  
}
