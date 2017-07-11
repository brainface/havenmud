#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetKeyName("stag");
   SetShort("a white stag");
   SetId( ({ "stag","deer","male" }) );
   SetAdjectives( ({ "white","pure","blessed","holy","male","great" }) );
   SetLong("The male deer has the purest white fur ever seen on "
           "any stag.  His antlers are huge, as if he has not shed "
           "them yearly as is normal for such creatures.  Clearly, "
           "he has been blessed with abnormal strength and "
           "holiness.");
   SetGender("male");
   SetRace("deer");
   SetClass("animal");
   SetLevel(27);
   SetMeleeAttackString("antlers");
   SetMeleeDamageType(PIERCE|BLUNT);
   SetMorality(15);
}

void eventDie(object killer) {
   object dis, dat;
   dis = new(H_OBJ + "wantlers");
   dat = new(H_OBJ + "wstgpelt");
   dis->eventMove(this_object());
   dat->eventMove(this_object());
   ::eventDie(killer);
}
