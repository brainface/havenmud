#include <lib.h>
#include <damage_types.h>
#include "../underland.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetNoClean(1);
   SetShort("inside the mithril forge");
   SetExits( ([
      "north" : "armoury",
   ]) );
   SetLong("The twisting vortex of molten rock melds into a multi-"
           "hued mass that is force fed air through huge vents.");
   SetListen("The deafening roar of the forced lava induction is mind-boggling.");
   SetSmell("Your nostrils are seared and you cannot smell anything.");
   set_heart_beat(3);
}


void heart_beat() {
   object *inv;
   ::heart_beat();
   inv = filter(all_inventory(this_object()), (: living :));
   if(sizeof(inv)) {
      foreach(object cookee in inv) {
         message("system", "%^RED%^BOLD%^The searing vortex of "
                 "molten rock, swells into incandecance as the bellows "
                 "blast forth huge swaths of air needed to super heat a cast "
                 "hot enough to smelt mithril sears your flesh!%^RESET%^", cookee);
         cookee->eventReceiveDamage(0, HEAT, random(4000), 0);
         cookee->eventForce("go north");
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
