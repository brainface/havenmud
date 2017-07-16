#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Prasanna");
  SetDomain("Valley");
   SetClimate("indoors");
   SetAmbientLight(50);
   SetShort("an empty house");
   SetLong("This small house doesn't look as though it has been lived in for "
           "quite some time. The room is bare, dull, and drab. It looks as if "
           "the occupants left in a great hurry. ");
   SetItems( ([ 
      ({ "house","small house" }) : 
         "This is a small house. You're standing in it.",
      ({ "room" }) : 
         "This room is tiny, barely enough space for two people to live in.",
   ]) );
   SetExits( ([ 
      "out" : PR_ROOM "/talver2", 
   ]) );
   SetInventory( ([
      PR_NPC + "/piglet" : 2 
   ]) );
   SetSmell( ([ 
      "default" : "There is a musty, stale smell here, like that of dust. ",
   ]) );
}

