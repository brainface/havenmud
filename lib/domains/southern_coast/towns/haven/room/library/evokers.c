//
// The Evokers' Training Hall
// Filename: evokers.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include "../haven.h"
#include <lib.h>

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(45);
   SetShort("the Evokers' Training Hall");
   SetLong("This is the training hall of the Evokers. Scattered about "
           "the room are the tools and wares of the School of Evokation. ");
   SetExits( ([
      "east" : "south_library",
   ]) );
   SetItems( ([
      ({ "tool", "tools", "ware", "wares" }) :
         "These many tools and wares scattered about the room are used by "
         "the School of Evokation to carry out their teachings.",
   ]) );
   SetListen( ([
      "default" : "The chants of students fill the air.",
   ]) );
   SetSmell( ([
      "default" : "The scents of spell components taint the room.",
   ]) );
   SetInventory( ([
      H_NPC + "evoker" : 1,
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 19:20:41 1999. */
