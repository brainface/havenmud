#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("prasanna");
   SetClimate("temperate");
   SetDomain("Valley");
   SetShort("foyer of the royal palace");
   SetLong("Mammoth white steps rise up into the foyer of the estate. "
           "The entire entryway to the palace is built to huge "
           "proportions. Towering marble columns, six feet wide and forty "
          "feet high, dwarf anyone who approaches. A doorway opens " 
           "to the north, granting access to the palace.");
   SetItems( ([ 
      ({ "mammoth white steps","white steps","steps","step" }) :
         "These steps stretch across the entire width of the palace "
         "foyer, yet only a small door leads into the building.",
      ({ "foyer" }) :
         "The foyer is relatively bare, gracefully simple..",
      ({ "estate" }) :
         "This is the palace of Maeralin, it is unparalleled in beauty.",
      ({ "entryway" }) :
         "The entry way to the palace is massive, with marble columns "
         "reaching high into the air.",
      ({ "marble columns","columns" }) :
         "The columns are pure marble, carved by hand. The size and "
         "skill required are almost unimaginable.",
      ({ "palace" }) :
         "The palace of Maeralin is immaculate and beautiful. A warm breeze "
         "drifts through the estate, making it seem almost inviting.",
      ({ "doorway" }) :
         "This doorway is quite normally sized, yet seems tiny compared "
         "to it's surroundings.",
   ]) );
   SetEnters( ([
     "palace" : PA_ROOM "/estatehall", 
           ]) );
   SetExits( ([ 
      "south" : PA_ROOM "/estate1",
   ]) );  
   SetInventory( ([ PR_NPC + "/royalguard" : 2 ]) );
}

