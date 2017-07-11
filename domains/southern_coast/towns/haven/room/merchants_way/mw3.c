//
// Part of Merchant's Way
// Filename: mw3.c
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
      "west" : H_ROOM + "merchants_way/mw4",
      "east" : H_ROOM + "merchants_way/mw2",
   ]) );
   SetLong("The road here is more dirty than in other parts of the "
           "town, mostly due to the shop to the south, which is "
           "home to Naythen's Smithy.  To the east, the road leads to "
           "the wharf district, which is where the city's trade comes "
           "and goes."
           );
   SetItems( ([
      ({ "road", "way" }) :
         (: GetLong :),
      ({ "shop", "smithy" }) : 
         "This shop appears to be Naythen's Smithy.",
      ({ "building", "inn" }) : 
         "This building looks somewhat new. It appears to be an inn.",
      ({ "district", "wharf" }) :
         "The wharf, the city's main trading post, is located to the "
         "east.",
      ({ "street", "streets" }) :
         "From here, the street heads west and east.",
   ]) );
   SetItemAdjectives( ([
      "smithy" : ({ "naythen's" }),
      "building" : ({ "new" }),
      "district" : ({ "wharf" }),
      "road" : ({ "dirty", "merchant's" }),
   ]) );
   SetEnters( ([
     
      "shop" : H_ROOM + "shops/smithy",
   ]) );
}


/* Approved by Duuktsaryth on Tue Apr 27 21:07:05 1999. */
