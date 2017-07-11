//
// Filename: enchanters.c
// The Enchanters' Training Hall
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
   SetShort("the Enchanters' Training Hall");
   SetLong("This is the training hall of the Enchanters. Scattered about "
           "the room are the tools and wares of the School of Enchantment.");
   SetItems( ([
      ({ "tool", "tools", "ware", "wares" }) :
         "Scattered about the room in many locations are these many tools "
         "and wares of the School of Enchantment.",
   ]) );
   SetExits( ([
      "west" : "south_library",
   ]) );
   SetListen( ([
      "default" : "The chants of students fill the air.",
   ]) );
   SetSmell( ([
      "default" : "The scents of spell components taint the room.",
   ]) );
   SetInventory( ([
      H_NPC + "enchanter" : 1,
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 19:20:07 1999. */
