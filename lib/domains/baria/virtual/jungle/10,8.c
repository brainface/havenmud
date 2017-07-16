/*  The connection room for the jungle */
#define JUNGLE_ROAD "/domains/valley/virtual/valley/-20,0"
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;
int DomainCheck();

static void create() {
  room::create();
  SetClimate("tropical");
  SetShort("in a sweltering jungle");
  SetExits( ([     
     "west" : "/domains/baria/virtual/jungle/9,8",
     "south" : "/domains/baria/virtual/jungle/10,7",
     "north" : "/domains/baria/virtual/jungle/10,9",
    ]) );
  AddExit("east", JUNGLE_ROAD, (: DomainCheck :) );
  SetLong("The jungle thins here, with a road seeming to lead up and into "
          "the jungle from the east. As far as the eye can see in the other "
          "directions are jungle.");
  SetInventory( ([
     "/domains/baria/virtual/sign" : 1,
      ]) );
  }

int DomainCheck() {
  if (!OPEN_VALLEY)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_VALLEY;  
}
