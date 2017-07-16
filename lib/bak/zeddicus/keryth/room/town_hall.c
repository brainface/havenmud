#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;
 
static void create()
{
  room::create();
  SetTown("Keryth");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetShort("the Town Hall");
  SetLong("Wooden planks enclose this one room building.  It is the "
          "communial place for all town gatherings and also the workplace of "
          "the mayor.  It is very open, with a high ceiling that stretches "
          "up into the rafters.  There is a large stone hearth to one side "
          "that houses a roaring fire to heat the building.  To the north, "
          "there is a small library, and there is an exit back out to the "
          "street.");

  SetItems( ([
    ({ "town hall", "hall", "building", "workplace", "room" }) :
       (: GetLong :),
    ({ "high ceiling", "ceiling" ,"rafters" }) :
	     "The high ceiling creates the illusion that this room is much larger "
	     "than it is.",
	  ({ "large stone hearth", "stone hearth", "large hearth", "hearth",
	     "huge stone hearth", "huge stone fireplace", "stone fireplace",
	     "fireplace" }) :
	     "The huge stone fireplace juts away from the wall and a warm place to "
	     "sit and watch the fire.  Next to it there is a stack of chopped wood.",
	  ({ "neat stack of chopped wood", "stack of wood", "wood", "chopped wood",
	     "neat stack", "stack", "damp wood" }) :
       "There is a neat stack of wood next to the fireplace.", 
    ({ "roaring fire", "fire" }) :
       "The fire glows red and crackles as it burns through damp wood.  Its "
       "heat warms the room and makes it very comfortable.",
    ({ "wooden planks", "planks", "walls" }) :
       "Dark, stained wooden planks surround the room and protect it from "
       "the bitter cold outside.",
    ({ "small town library","library","room","small library",
       "town library" }) :
       "There is the town libary to the north.",
	]) );

  SetExits( ([ 
    "out"   : K_ROOM "main_03",
    "west"  : K_ROOM "p_office",
    "south" : K_ROOM "th_back"
	]) );

  SetListen( ([
    "default" : "The fire roars in the backround.",
    "fire" : "The fire pops and crackles as it dries and burns the damp "
             "wood."
  ]) );

  SetNewsgroups( ({ "town.keryth" }) );
  SetProperty("keryth_town_hall", 1);
}
