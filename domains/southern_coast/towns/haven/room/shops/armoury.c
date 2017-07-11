//
// Fidget's Armoury
// Filename: armoury.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(50);
   SetShort("Fidget's Armoury");
   SetExits( ([
      "out" : "../merchants_way/mw5",
   ]) );
   SetInventory( ([ 
      H_NPC + "fidget" : 1,
   ]) );
   SetLong("This business is one that specializes in armour and clothing \n"
           "of all kinds.  Various types of raiment line the room in a way \n"
           "that is designed to show off their style.");
   SetItems( ([
      ({ "room", "armoury", "business" }) : 
         (: GetLong :),
      ({ "raiment", "clothing", "armour", "attire",
         "vestments", "vestment" }) :
         "Various types of attire and vestments are displayed around "
         "the room. It is obvious that the armourer took care in "
         "arranging them. ",
   ]) );
   SetItemAdjectives( ([
      "raiment" : ({ "various" }),
   ]) );
   SetSmell( ([
      "default" : "The room smells of cloth and metal.",
   ]) );
}

/* Approved by Haun on Tue Apr 27 21:15:42 1999. */