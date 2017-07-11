/*  entry room of oni threat area in Tairi
 *  Coded by Pyrial@Haven
 */

#include <lib.h>
#include "../area.h" 

inherit LIB_ROOM;  

static void create() 
  {
  room::create();
  SetShort("a small cave entrance");
SetClimate("underground");
  SetAmbientLight(20);
  SetLong(
    "This is the entrance to a small cave.  It is very dark and a sense of evil "
    "prevails throughout.  The walls of the cave glisten with moisture that has "
    "dripped for centuries, etching fine lines for the rivulets of water to follow.  "
    "Hanging down from the ceiling of the cave, small stalactites can be seen just "
    "starting to form.  The air is very humid, condensing along the ceiling and walls "
    "to perpetuate the cycle of moisture in the cave.");
  SetItems( ([
    ({"moisture","water","rivulets","rivulet","cycle","lines"}) : "The moisture in this "
      "cave perpetuates itself by condensing on the ceiling and walls then dripping "
      "down small rivulets formed in the walls over the ages.  Once it has settled "
      "on the floor again, it evaporates and continues the cycle again.",
    ({"wall","walls"}) : "The walls of the cave are rough, having never been touched "
      "by humanoid hands.  They are cut from the stone below the ground.",
    "floor" : "The floor of the cave is covered in a fine sand that has been pushed to "
      "the sides by years of use.  Alone the channel formed in the center, a small "
      "river of water flows deeper into the caves.",
    ({"stalactites","stalactite","ceiling"}) : "The ceiling of the cave is covered in "
      "many small stactites that are in the very early stages of formation.  Even "
      "small formations such as this point to the cave being very old.",
    ({"stone","cave","bedrock"}) : "The cave has been carved into the bedrock under "
      "Tairi through ages of water flow.",
    "channel" : "A small channel has formed down the middle of the floor of the cave."
      "  A small river flows deeper into the cave.",
    "sand" : "A fine grained sand lines the sides of the floor.",
  ]) );
  SetItemAdjectives( ([
    "stactite" : ({"small"}),
    "cave" : ({"small","dark"}),
    "lines" : ({"fine"}),
  ]) );
  SetListen( ([
    "default" : "A quiet dripping of water can be heard.",
  ]) );
  SetSmell( ([
    "default" : "The air smells dank and very humid.",
  ]) );
  SetInventory( ([
     NPC + "oni" : 1,
  ]) );
  SetExits( ([
    "east" : ROOM "cave_2",
    "out"  : CONNECT,
  ]) );
}

/** Approved by Laoise at Tue Sep  7 22:22:00 2004. **/
