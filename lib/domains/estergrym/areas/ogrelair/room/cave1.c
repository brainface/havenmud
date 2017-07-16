/* Ogre Lair, Estergrym
   Kairehn (17/01/2008) */

#include <lib.h>
#include "../ogrelair.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(10);
  SetShort("in a foul smelling cave");
  SetExits( ([  "north" : LAIR_ROOMS + "cave2", 
                "out" : LAIR_ROOMS + "clearing2", ]) );
  SetSmell( ([ "default" : "There is a distinct smell of rotting flesh here.", ]) );
  SetListen( ([ "default" : "The wind whistles as it passes the cave opening." ]) );
  SetLong("The cave smells repulsive, probably due to the pile of animal "
          "carcasses in a corner. There are some crude wooden tables here, "
          "held together by string. Upon them lie various old books, most of "
          "which are covered with strange-looking symbols. The cave continues "
          "to the north, where the light of what is probably a torch flickers "
          "upon the walls. An opening leads out of the cave, to a clearing.");  
 SetItems( ([ 
    "cave" : "The cave smells utterly repulsive.",
    ({ "pile", "carcasses" }) : "This pile comprises of the remains of various "
      "animals.",
    ({ "table", "tables" }) : "These tables are barely standing, being held together "
      "merely by string. There are various books scattered on top of them.",
    ({ "book", "books", "symbols" }) : "The books are covered with strange-looking "
      "symbols, which seem to have been drawn crudely. The language is "
      "incomprehensible.",
    "torch" : "To the north, the flickering of what is probably a torch illuminates "
      "the cave.",    
  ]) );
  SetItemAdjectives( ([ 
    "carcasses" : "animal",
    "table" : ({"crude", "wooden"}), 
    "books" : "old",
    "symbols" : "strange-looking",    
  ]) );  
  SetInventory( ([    
    LAIR_NPC "weakogre" : 1,    
  ]) );
}
