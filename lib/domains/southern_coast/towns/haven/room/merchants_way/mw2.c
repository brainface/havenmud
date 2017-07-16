//
// Part of Merchant's Way
// Filename: mw2.c
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
      "west" : H_ROOM + "merchants_way/mw3",
      "east" : H_ROOM + "merchants_way/mw1",
   ]) ); 
   SetLong("To the east is an intersection of roads.  From there, it "
           "appears that the road meets an end, but turns north and "
           "south in a \"T\" shape.  Directly east is a large building. "
           "To the west, Merchant's Way leads into the crowded business "
           "district of the town.");
   SetItems( ([
      ({ "intersection", "road", "roads" }) :
         "This small intersection of roads can be seen to the east.",
      ({ "district", "way" }) :
         "Merchant's Way leads off to the west from here into the business "
         "district of town.",
      ({ "building" }) :
         "This large building can be seen to the east. However, what its "
         "purpose is cannot be seen.",
   ]) );
   SetItemAdjectives( ([
      "district" : ({ "business", "crowded" }),
      "building" : ({ "large" }),
      "way" : ({ "merchant's" }),
   ]) );
}


/* Approved by Duuktsaryth on Tue Apr 27 21:06:51 1999. */
