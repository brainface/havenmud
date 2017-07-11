//
// The Haven Post Office
// Filename: office.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_POST_OFFICE;
 
static void create() {
   post_office::create();
   SetClimate("indoors");
   SetAmbientLight(50);
   SetTown("Haven");
   SetShort("Haven's Post Office");
   SetLong("This is the city post office that serves the town of Haven. \n"
           "From here, citizens may send and receive their mail by typing \n"
           "<mail>.  Once in, simply follow the instructions.");
   SetItems( ([
      ({ "office", "facility" }) :
         (: GetLong :),
      ({ "citizen", "citizens" }) :
         "The many citizens of Haven Town can use this facility as a means "
         "to send and receive mail.",
   ]) );
   SetItemAdjectives( ([
      "office" : ({ "city", "post" }),
   ]) );
   SetExits( ([ 
      "out" : "../imperial_road/ir6",
   ]) );
}

/* Approved by Duuktsaryth on Tue Apr 27 21:12:51 1999. */
