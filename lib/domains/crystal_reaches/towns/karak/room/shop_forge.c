// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <damage_types.h>
#include "../karak.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetNoClean(1);
  SetClimate("indoors");
  SetShort("inside the forge");
  SetLong(
    "The forge is burning with heat!"
  );
  SetExits( ([
    "out" : "shop_smithy",
  ]) );
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
