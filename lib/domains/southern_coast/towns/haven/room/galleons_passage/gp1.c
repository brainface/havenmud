//
// Filename: gp1.c
// Part of Galleon's Passage
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("Galleon's Passage");
   SetExits( ([
      "north" : H_ROOM + "galleons_passage/gp2",
      "south" : H_ROOM + "merchants_way/mw1",
   ]) );
   SetLong("To the south the road continues on towards the Ruined Sea, "
           "leading into the wharf district and the warehouses of the "
           "shipping companies.  To the north the road meets up with "
           "the main road of Haven Town. A small stable sits by the roadside, "
           "fully capable of selling mules to the citizens of Haven."
           );
   SetItems( ([
      ({ "road" }) : 
         (: GetLong :),
      ({ "sea" }) :
         "To the south of here lies the Ruined Sea.",
      ({ "district" }) :
         "The wharf district of Haven is located south of here.",
      ({ "company", "companies" }) :
         "The wharf district to the south is the home to many "
         "shipping companies.",
      ({ "stable" }) : "The stable boasts a sign proclaiming it to be Alpacha's Stable.",
   ]) );
   SetItemAdjectives( ([
      "sea" : ({ "ruined" }),
      "district" : ({ "wharf" }),
      "company" : ({ "shipping" }),
   ]) );
   SetEnters( ([
     "stable" : H_ROOM "shops/stable",
     ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 18:50:53 1999. */
