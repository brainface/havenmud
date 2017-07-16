#include <lib.h>
#include "../durgoroth.h"


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic"); 
  SetShort("before the cave");
  SetLong("A large opening in the rock face is just north"
          " of here. The area has been cleared of the rubble"
          " that is present throughout the rest of the city."
          " A light blue glow eminates from the cave providing"
          " an eerie atmosphere. To the south what passes"
          " for a cemetery can be seen.");
  SetItems( ([
          ({ "cave", "light", "mouth", "opening", "rock face" }) :
             "A eerie blue light eminates from the cave"
             " giving a hint of magical forces at work.",
          ({ "cemetery", "graveyard", "boneyard" }) :
             "A clearing to the south is where the dead"
             " that are not devoured are taken to rot.",
          ]) );
  SetSmell( ([ 
          "default" : "The smell of rotting flesh lingers.", 
          ]) );
  SetListen( ([ 
          "default" : "A slight humming comes from the cave.", 
          ]) );
  SetInventory( ([ 
          DURG_NPC "horror"        : 1,
          DURG_NPC "toughcitizen2" : 2,
          ]) );
  SetExits( ([
          "southwest" : DURG_ROOM "road04",
          "southeast" : DURG_ROOM "road06",
          "south" : DURG_ROOM "cemetery",
          ]) );
  SetEnters( ([
          "cave" : DURG_ROOM "cave1",
          ]) );
}
