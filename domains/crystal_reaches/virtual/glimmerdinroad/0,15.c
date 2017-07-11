#include <lib.h>
#include <domains.h>

inherit LIB_ROOM;
int DomainCheck();

static void create()
{
  room::create();
  SetShort("the intersection of Glimmerdin Road and Valley Road");
  SetLong(
    "From here Glimmerdin Road runs south towards Lloryk "
    "and northwest, to the dwarven stronghold of Glimmerdin. "
    "West of here lies the Valley including the road to "
    "Jidoor. Many miles to the west is the Barian Jungle."
  );
  SetItems( ([
    ({"path","road","trail","intersection"}) : (:GetLong():),
  ]) );
  SetExits( ([
     "northwest" :  "/domains/crystal_reaches/virtual/glimmerdinroad/-1,16",
     "west" : "/domains/valley/virtual/valley/20,0",
     "south" : "/domains/crystal_reaches/virtual/glimmerdinroad/0,14",
          ]) );
  SetInventory( ([
    CRYSTAL_REACHES_VIRTUAL "sign/glimmerdinroad015" : 1,
  ]) );

}

int DomainCheck() {
  if (!OPEN_VALLEY)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_VALLEY;  
}

