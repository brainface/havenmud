//
// Part of Merchant's Way
// Filename: mw1.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("Merchant's Way and Galleon's Passage");
   SetExits( ([
      "west" : H_ROOM + "merchants_way/mw2",
      "south" : H_ROOM + "wharf",
      "north" : H_ROOM + "galleons_passage/gp1",
   ]) );
   SetLong("The roads meet here in an intersection that leads off in three "
           "directions.  To the west is the Merchant's Way, which is one "
           "of the business roads in the town.  To the south is the wharf, "
           "which is the center of shipping for Haven Town and the entire "
           "Southern Coast.  Directly to the east is a large building.");
   SetItems( ([
      ({ "road", "intersection", "roads" }) :
         (: GetLong :),
      ({ "way" }) :
         "Merchant's Way continues off to the west.",
      ({ "wharf" }) :
         "To the south of here lies the wharf. The wharf is the center "
         "of shipping of Haven Town.",
      ({ "building", "warehouse", "shipping", "companies", "company" }) : 
         "This is the warehouse for Avery Shipping, one of the "
         "largest companies in Haven.",
   ]) );
   SetItemAdjectives( ([
      "way" : ({ "merchant's" }),
      "building" : ({ "large" }),
      "road" : ({ "business" }),
   ]) );
   SetEnters( ([
      "warehouse" : H_ROOM + "shops/warehouse",
   ]) );
}

/* Approved by Duuktsaryth on Tue Apr 27 21:06:09 1999. */
