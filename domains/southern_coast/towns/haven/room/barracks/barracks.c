//
// Filename: barracks.c
// Haven Town Barracks v2.0
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
   SetShort("Haven Barracks");
   SetExits( ([
      "out" : H_ROOM "galleons_passage/gp5",
      "north" : "barracks2",
   ]) );
   SetInventory( ([
      H_NPC + "nastarum" : 1,
      H_NPC + "guard" : 1,
   ]) );
   SetItems( ([
      ({ "barracks", "building" }) :
         (: GetLong :),
      ({ "hall" }) :
         "This training hall sits to the north",
   ]) );
   SetItemAdjectives( ([
      "barracks" : ({ "haven", "town", "haven town", "large", "imposing" }),
      "hall" : ({ "training" }),
   ]) );
   SetLong("The Haven Town Barracks is a large and imposing "
           "building dedicated to the martial arts. To the "
           "north is a training hall for recruits of all "
           "rank and level of skill. ");
}


/* Approved by Duuktsaryth on Sun Apr 25 18:36:38 1999. */
