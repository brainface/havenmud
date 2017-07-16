//
// The Forge!
// Filename: forge.c
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include <damage_types.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetNoClean(1);
   SetShort("inside the forge");
   SetExits( ([
      "out" : "smithy",
   ]) );
   SetLong("The forge is burning with heat!");
   set_heart_beat(3);
}


void heart_beat() {
   object *inv;
   ::heart_beat();
   inv = filter(all_inventory(this_object()), (: living :));
   if(sizeof(inv)) {
      foreach(object cookee in inv) {
         message("system", "%^RED%^BOLD%^The heat from the "
                 "forge sears into you!%^RESET%^", cookee);
         cookee->eventReceiveDamage(0, HEAT, random(400), 0);
      }
   }
   if(!sizeof(inv)) set_heart_beat(0);
}

void init() {
   ::init();
   set_heart_beat(3);
   heart_beat();
}

int CanReceive(object ob) {
   if (living(ob) && !userp(ob)) return 0;
   return 1;
}


/* Approved by Haun on Tue Apr 27 21:16:22 1999. */