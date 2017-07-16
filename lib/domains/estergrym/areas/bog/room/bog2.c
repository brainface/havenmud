// Peat Bog
// Francis
// January 2005

#include <lib.h>
#include <domains.h>
#include <domains.h>
#include "../bog.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(40);
  SetClimate("sub-artic");
  SetShort("Sunken Ruins within the bog");
  SetLong(
   "A large stagnent body of water pools here, the waters are black" 
   " and it more looks like a shallow murky puddle.  Sprouts of" 
   " grass can be seen growing up out of the small stagnent pond."
   "  Skeletal black spruce trees stand guard over the pond in silent"
   " reverence.  Ruins of what look like a paupers residence lay half"
   " sunk within the stagnent soil, only a wall made from fieldstone" 
   " stands erect to mark it was ever there.",
);
  SetItems( ([
   ({"water","puddle","pond"}) : "This large body of stagnent water is guarded" 
   "by black spruce trees there reflections reflect off of the dull black"
   " water.",
   ({"grass"}) : "Thick patches of saw grass sprout out from the shallow" 
   " portions of the pond.",
   ({"trees","tree"}) : "Skeletal black spruce trees stand guard over the"
   " pond in silent reverence.",
   ({"ruins","residence","house"}) : "These ruins looks rather old, there is" 
   " evidence that this house burned down, it now slowly sinks into" 
   " the bog all that is left is a erect wall of fieldstone still" 
   " adhering to the foundation.",
   ({"soil","dirt"}) : "The soil is soft and it reeks of decay.",
   ({"wall"}) : "A wall of fieldstone is all that is left of the paupers"
   " residence.",
   ({"fieldstone"}) : "Thick stones hauled from far away to form the"
   " walls of the paupers house.",
   ({"foundation"}) : "The foundation which was once firm packed"
   " dirt is now soggy and damp, soon it will disolve into the bog aswell.",
   ({"log"}) : "A log which is covered in bog turtle dung lies half"
   " submerged in the stagnent pond.",
   ({"dung"}) : "This is obviously reptilian, it is white and very thick.",
]) );
  SetItemAdjectives( ([
   "water" : ({"large","stagnent","body","black"}),
   "grass" : ({"sprouts"}),
   "trees" : ({"black","spruce","skeletal"}),
   "soil" : ({"stagnent"}),
   "wall" : ({"fieldstone"}),
   "residence" : ({"paupers"}),
]) );
  SetListen( ([
   "default" : "The whistle of the wind and the chatter of the insects is" 
   " all that can be heard.",
]) );
  SetSmell( ([
   "default" : "It reeks of decay and stagnent water here.",
]) );
  SetInventory( ([
   BOG_NPC "bogturtle" : 5,
   BOG_NPC "dragonfly" : 2,
]) );
  SetExits( ([
   "west" : BOG_ROOM "bog3",
   "north" : BOG_ROOM "bog1",
   "south" : ESTERGRYM_AREAS "lake/room/lake5",
]) );
}
