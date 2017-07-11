// Island
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../island.h"

inherit LIB_FISHING;
//inherit LIB_ROOM;

static void create() {
  ::create();
  SetAmbientLight(30);
  SetProperty("coastal", 1);
  SetNoClean(1);
  SetClimate("temperate");
  SetShort("on a small sandy bay");
  SetLong(
    "This small bay is enclosed by towering rock formations, making passage "
    "around the perimeter of the island impossible by foot. The soft white "
    "sand is home to a few pebbles and shells, carried here as the frothy "
    "ocean waves gently wash over the shore. Further inland there is a dense "
    "jungle that looks barely passable in places."    
  );
  SetItems( ([
  ({ "bay" }) : (: GetLong :),
  ({ "formations", "perimiter" }) : 
    "The towering rock formations surround most of this island.",  
  ({ "sand", "pebbles", "shells" }) : 
    "The soft sand is very white. There are some pebbles and shells scattered "
    "over the entire bay.",
  ({ "waves", "shore" }) : 
    "The frothy waves gently wash over the shore, creating a soft noise that "
    "soothes the ears.",
  ({ "jungle" }) : 
    "The jungle to the north looks very thick, almost impassable.",
  ]) );
  SetItemAdjectives( ([     
    "formations" : ({ "rock", "towering" }),
    "sand" : ({ "soft", "white" }),
    "waves" : ({ "ocean", "frothy" }),
    "jungle" : ({ "dense" }),
    "bay" : ({ "small" }),
  ]) );  
  SetListen( ([
    "default" : "The only audible sound is that of the ocean as it sweeps "
      "over the bay.",
  ]) );
  SetSmell( ([
    "default" : "The ocean air is a little salty, but very refreshing.",
  ]) );
  SetExits( ([
    "northwest" : ISLAND_ROOM "island1",
    "northeast" : ISLAND_ROOM "island3",    
    "south" : INNERSEA_VIRTUAL "ocean/-150,-20", 
  ]) );
  SetSpeed(5);
  SetFish( ([
      DIR_STD "fish/guppy" : 100,
      DIR_STD "fish/trout" : 10,
  ]) );
  SetChance(25);
  SetMaxFishing(12);
  SetInventory( ([
    ISLAND_NPC "ferrycaptain" : 1,
    ISLAND_OBJ "ferry" : 1,
    ]) );
}
