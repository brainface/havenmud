#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetNoCorpse(1);
   SetKeyName("brown doe");
   SetShort("a brown doe");
   SetId( ({ "doe","deer" }) );
   SetAdjectives( ({ "brown" }) );
   SetLong("The doe is a beautiful milky brown.  She looks strong, but "
           "weighted down.");
   SetRace("deer");
   SetGender("female");
   SetClass("animal");
   SetLevel(5+random(4));
   SetCorpseItems( ([
     H_OBJ + "doepelt" : 1,
     H_OBJ + "doehoof" : 4,
   ]) );
   SetMeleeAttackString("hooves");
   SetMeleeDamageType(BLUNT);
}
