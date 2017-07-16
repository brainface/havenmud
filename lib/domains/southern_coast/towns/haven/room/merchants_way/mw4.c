//
// Part of Merchant's Way
// Filename: mw4.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("Merchant's Way");
   SetExits( ([ 
      "west" : H_ROOM + "merchants_way/mw5",
      "east" : H_ROOM + "merchants_way/mw3",
   ]) );
   SetLong("The road continues on to the east and west from here, "
           "but a large number of people are coming and going from "
           "the building to the south, which is Taylor's General Store, "
           "one of the main commercial ventures in Haven Town.  To the "
           "east and west there are more shops. The office of the Elven "
           "Aide Charity lies to the north."
           );
   SetItems( ([
      ({ "shop", "store", "venture" }) : 
         "Taylor's General Store",
      ({ "office", "charity" }) : 
         "The office that sits on the north end of the road "
         "is a place for the young to get free equipment.",
      ({ "people" }) :
         "Many of the people on this road are coming and going from "
         "Taylor's General Store.",
   ]) );
   SetSmell("A pleasant aroma comes from the Charity.");
   SetItemAdjectives( ([
      "shop" : ({ "general", "taylor's", "commercial", "main" }),
      "office" : ({ "elven", "aide", "charity" }),
   ]) );
   SetEnters( ([
      "shop" : H_ROOM + "shops/shop",
      "office" : H_ROOM "misc_buildings/charity",
   ]) );
}


/* Approved by Duuktsaryth on Tue Apr 27 21:07:07 1999. */
