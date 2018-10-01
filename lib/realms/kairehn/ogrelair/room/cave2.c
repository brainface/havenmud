/* Ogre Lair, Estergrym
   Kairehn (17/01/2008) */

#include <lib.h>
#include "../ogrelair.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(30);
  SetShort("in a foul smelling cave");
  SetExits( ([  "south" : LAIR_ROOMS + "cave1", ]) );
  SetSmell( ([ "default" : "The cave smells damp and mouldy.", ]) );
  SetListen( ([ "default" : "The flickering flame of a nearby torch crackles." ]) );
  SetLong("This part of the cave is slightly tidier than the other, "
          "and at least some attempt at decoration, however basic, seems to have "
          "been made. Various books are scattered over a large pile of filthy "
          "rugs on the floor, which probably serves as some kind of primitive "
          "place to sleep.");  
  SetItems( ([ 
    "cave" : "The cave smells utterly repulsive.",
    ({ "pile", "rugs" }) : "The rugs on the floor are damp, and smell mouldy.",
    ({ "book", "books", "symbols" }) : "The books are covered with strange-looking "
      "symbols, which seem to have been drawn crudely. The language is "
      "incomprehensible.",
    "torch" : "A torch, fixed to the wall of the cave, provides some illumination.",    
  ]) );
  SetItemAdjectives( ([ 
    "pile" : "large",
    "rugs" : "filthy",   
    "books" : "old",
    "symbols" : "strange-looking",    
  ]) );
  SetInventory( ([
    LAIR_NPC "strongogre" : 1,
    LAIR_NPC "weakogre" : 2,    
  ]) );  
}
