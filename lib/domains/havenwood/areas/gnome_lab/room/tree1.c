#include <lib.h>
#include "../gnome_lab.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("main room of a tree house");
  SetAmbientLight(30);
  SetClimate("indoors");
  SetLong(
	  "This large round room has a spiral staircase carved into the "
	  "trunk heading upward, deeper into the branches of this tree. "
	  "The base of the stairs start off in the southern section of this "
	  "chamber. A ladder, through a rather enormous hole which could fit a "
	  "large ogre, is in opposite corner as the base of the stairs.  "
	  "Several lanterns have been placed around the room at equal "
	  "intervals, just above the average human reach.");
  SetItems( ([ 
	  ({"branch","branches"}) :
      "This large round room has a spiral staircase carved into the "
	  "trunk heading upward, deeper into the branches of this tree.",
	  ({"lantern","lanterns"}) : 
	  "Several oil lanterns light up this room as it was high noon.",
	  ({"staircase","stairs","base","tree","trunk"}) :
      "A staircase has been carved into the trunk of this tree.",
	  "hole" :
	  "Though the rather enormous hole is a long wooden ladder. ",
	  ({"room","chamber"}) :
	  "The room is large enough to hold a dozen ogres comfortablely.",
	  ]) );
  SetItemAdjectives( ([
	  "lanterns" : "several",
      "room" : ({"large","round"}),
      "tree" : ({"tall","very tall"}),
	  "hole" : ({"large","enormous"}),
	  "staircase" : "spiral"
	  ]) );
  SetListen( ([
      "default" : 
	  "The rustling of the wind hitting the house can be heard.",
      ]) );
  SetSmell( ([
      "default" :
	  "The scent of burning oil fills the air.",
      ]) );
  SetInventory( ([
	  G_OBJ + "ladder" : 1,
	  ]) );
  SetExits( ([
	  "up" : G_ROOM + "tree2",
	  ]) );
}
