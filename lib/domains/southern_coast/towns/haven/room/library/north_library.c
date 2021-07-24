
//
// The Northern End of the Training Hall
// Filename: north_library.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(45);
   SetShort("the northern end of the training hall");
   SetExits( ([
      "south" : "training_hall",
      "east"  : "necromancers",
   ]) );
   SetLong("This section of the training hall appears to be dedicated to "
           "a type of magic which deals more with living organisms than "
           "with the raw energies of magic. To the east lies the hall "
           "of the necromancers. "
           "Further south, the hall leads back into the main sections of "
           "the library.");
   SetItems( ([
      ({ "necromancer", "necromancers" }) :
         "The hall of the necromancers lies to the east.",
      ({ "section", "sections" }) :
         "The main sections of the library can be found to the south.",
   ]) );
   SetItemAdjectives( ([
      "section" : ({ "main" }),
   ]) );
   SetSmell( ([
      "default" : "An odd scent of death is on the air.",
   ]) );
   SetListen( ([
      "default" : "Soft chants come from the east.",
   ]) );
   SetInventory( ([
      H_NPC + "dancer" : 1,
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 19:33:00 1999. */

