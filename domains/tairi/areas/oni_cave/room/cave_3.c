/*  cave two of oni threat area in Tairi
 *  Coded by Pyrial@Haven
 */

#include <lib.h>
#include "../area.h" 

inherit LIB_ROOM;  

static void create() 
  {
  room::create();
  SetShort("a large opening");
SetClimate("underground");
  SetAmbientLight(10);
  SetLong(
    "This is a large opening at the end of a small cave.  It is very dark and a sense "
    "of evil prevails throughout.  The walls of the cave glisten with moisture that has "
    "dripped for centuries, etching large rivulets for the water to follow.  Hanging "
    "down from the ceiling of the cave, large stalactites can be seen, reaching down "
    "like claws to meet the stalagmites forming on the ground.  The air is very humid, "
    "condensing along the ceiling and walls, then running down into a small cave lake.");
  SetItems( ([
    ({"moisture","rivulets","rivulet","lake"}) : "The moisture in this "
      "cave perpetuates itself by condensing on the ceiling and walls then dripping "
      "down large rivulets formed in the walls over the ages.  From there, it flows "
      "down into the small cave lake.",
    ({"wall","walls"}) : "The walls of the cave are rough, having never been touched "
      "by humanoid hands.  They are cut from the stone below the ground.",
    ({"floor","stalagmite","stalagmites"}) : "The floor is cut right into rock itself.  "
      "Centuries of water flow have started to form small stalagmites on the floor."
      "the sides by years of use.  Alone the channel formed in the center, a small "
      "river of water flows deeper into the caves.",
    ({"stalactites","stalactite","ceiling"}) : "The ceiling of the cave is covered in "
      "many large stactites that are reach down like claws to the waiting stalagmites.",
    ({"stone","cave","bedrock"}) : "The cave has been carved into the bedrock under "
      "Tairi through ages of water flow.",
    "lake" : "A small cave lake has formed here from all the cave moisture.",
  ]) );
  SetItemAdjectives( ([
    "stactite" : ({"large"}),
    "cave" : ({"small"}),
    "lines" : ({"fine"}),
    "opening" : ({"large"}),
    "lake" : ({"small"}),
    "stalagmite" : ({"small"}),
  ]) );
  SetListen( ([
    "default" : "A quiet gurgling of a river flowing into the lake can be heard.",
  ]) );
  SetSmell( ([
    "default" : "The air smells dank and very humid.",
  ]) );
  SetInventory( ([
     NPC + "gozu" : 1,
  ]) );
  SetExits( ([
    "south" : ROOM "cave_2",
  ]) );
}

/** Approved by Laoise at Tue Sep  7 22:22:24 2004. **/
