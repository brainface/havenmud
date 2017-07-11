/*  cave two of oni threat area in Tairi
 *  Coded by Pyrial@Haven
 */

#include <lib.h>
#include "../area.h" 

inherit LIB_ROOM;  

static void create() 
  {
  room::create();
  SetShort("a small cave");
SetClimate("underground");
  SetAmbientLight(10);
  SetLong(
    "This is a the interior of a cave, far enough past the entrance that little light "
    "penetrates the area.  A small river of water flows down, deeper into cave.  "
    "Hanging down from the ceiling of the cave are stalactites.  The walls of the "
    "cave glisten with moisture that has dripped for centuries, etching large "
    "rivulets for the water to follow.  Sand is pushed up against the edges of "
    "wall, enclosing the small river and creating a path to walk upon.");
  SetItems( ([
    ({"moisture","rivulets","rivulet"}) : "The moisture has condensed on the walls "
      "and ceiling for ages, carving rivulets into the wall.",
    ({"wall","walls"}) : "The walls of the cave are rough, having never been touched "
      "by humanoid hands.  They have been carved into the bedrock through centuries "
      "of water flow.",
    "floor" : "The floor of the cave is covered in a fine sand that has been pushed to "
      "the sides by years of use.  Alone the channel formed in the center, a small "
      "river of water flows deeper into the caves.",
    ({"stalactites","stalactite","ceiling"}) : "The ceiling of the cave is covered in "
      "many small stactites that are in the very early stages of formation.  Even "
      "small formations such as this point to the cave being very old.",
    ({"stone","cave","bedrock"}) : "The cave has been carved into the bedrock under "
      "Tairi through ages of water flow.",
    "river" : "A small river has formed down the middle of the floor of the cave."
      "  It flows down into the depths of the cave.",
    ({"sand","path"}) : "A fine grained sand lines the sides of the floor, pushed up "
      "against the walls from moderate use.  A path has formed alone one wall.",
  ]) );
  SetItemAdjectives( ([
    "cave" : ({"small","dark"}),
    "river" : ({"small"}),
  ]) );
  SetListen( ([
    "default" : "A quiet gurgling of the river can be heard.",
  ]) );
  SetSmell( ([
    "default" : "The air smells dank and very humid.",
  ]) );
  SetInventory( ([
     NPC + "oni" : 2,
  ]) );
  SetExits( ([
    "west" : ROOM "cave_1",
    "north"  : ROOM "cave_3",
  ]) );
}

/** Approved by Laoise at Tue Sep  7 22:22:18 2004. **/
