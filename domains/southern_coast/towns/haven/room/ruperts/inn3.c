//
// An apartment in Rupert's Hole
// Filename: inn3.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
   SetProperty("no bump", 1);
   SetShort("a large apartment");
   SetAmbientLight(55);
   SetLong("This posh apartment seems to be the home of someone important, "
           "but still frugal enough to save money when possible.  A lifetime "
           "of achievements are documented in tapestries and prizes. "
           "The room's sparse furniture is pleasant and comfortable, "
           "without excessive cost showing.");
   SetItems( ([
      ({ "prizes", "prize", "tapestry", "tapestries" }) : 
         "These prizes and tapestries depict the life of a merchant.",
      ({ "furniture", "furnishings", "furnishing" }) : 
         "These furnishings look very comfortable.",
      ({ "apartment" }) :
         (: GetLong :),
   ]) );
   SetItemAdjectives( ([
      "furniture" : ({ "pleasant", "comfortable" }),
      "apartment" : ({ "posh" }),
   ]) );
   SetInventory( ([
      H_NPC + "timmy" : 1,
      H_NPC + "pithian" : 1,
   ]) );
   SetExits( ([
      "down" : "inn2",
   ]) );
}


/* Approved by Duuktsaryth on Tue Apr 27 21:15:12 1999. */
