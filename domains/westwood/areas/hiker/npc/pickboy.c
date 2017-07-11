#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetKeyName("blueberry picker");
   SetShort("a young blueberry picker");
   SetId( ({ "picker","boy","male","human" }) );
   SetAdjectives( ({ "young","blueberry","male" }) );
   SetLong("This young boy grins a hearty grin of blue stained teeth.  "
           "More blue stains around his mouth and all over his fingers "
           "mark him as one who doesn't just pick berries for cooking "
           "back home, but as one who eats them straight off the "
           "bushes.");
   SetGender("male");
   SetClass("rogue");
   SetRace("human");
   SetLevel(5+random(2));
   SetInventory( ([
                    H_OBJ + "pail" : 1,
                    H_OBJ + "blueberries" : 1+random(3),
                    H_OBJ + "blueleaf" : 4+random(2),
               ]) );
   SetAction(2, ({ "!emote eats some berries secretively.",
                   "!emote munches on some leaves between berries.",
                   "!put first berries in pail",
              }) );
   SetMeleeAttackString("fists");
   SetMeleeDamageType(BLUNT);
   SetMorality(300);
}
