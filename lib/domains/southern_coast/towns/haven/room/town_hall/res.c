//
// The Town Hall Residence
// Filename: res.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(40);
   SetShort("the residence");
   SetExits( ([
      "down" : "town_hall",
   ]) );
   SetInventory( ([
       H_NPC + "astara" : 1,
   ]) );
   SetDayLong("The residence is well lit and cheerful during the \n"
              "day, which gives rise to a feeling of overall well \n"
              "being and contentment.  Books lay scattered around \n"
              "in an orderly fashion.");
   SetNightLong("The residence is dimly lit at night, yet still \n"
                "there are books arranged in a fashion that seems \n"
                "to indicate that visitors are always welcome.");
   SetItems( ([
      ({ "residence" }) :
         (: GetLong :),
      ({ "book", "books" }) : 
         "These books are on human culture and language. Perhaps "
         "someone that lives here takes an avid interest in that?",
      ({ "visitor", "visitors" }) :
         "The residence gives off a feeling that visitors are "
         "always welcome.",
   ]) );
   SetItemAdjectives( ([
      "book" : ({ "culture", "human", "language" }),
   ]) );
}


/* Approved by Duuktsaryth on Tue Apr 27 21:19:56 1999. */
