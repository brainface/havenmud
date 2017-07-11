#include <lib.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetKeyName("ugly grub");
   SetShort("an ugly grub");
   SetId( ({ "grub" }) );
   SetAdjectives( ({ "ugly" }) );
   SetLong("The grub is fat and squishy, and looks like he might actually "
           "be enjoying his puny life on the underside of rotting logs.  "
           "The white thing is wrinkly and could almost be a tasty "
           "snack--if you were half starved.");
   SetGender("male");
   SetRace("insect",1);
   SetClass("animal");
   SetLevel(1);
   SetNoCorpse(1);
   AddLimb("body",0,1,({ }) );
   AddLimb("head","body",1,({ }));
}

void eventDie(object killer) {
   object blah;
   blah = new(H_OBJ + "grubfood");
   blah->eventMove(environment(this_object()));
   ::eventDie(killer);
}

