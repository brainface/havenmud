// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("dryad");
   SetShort("an energetic dryad");
   SetId( ({ "dryad" }) );
   SetAdjectives( ({ "effusive" }) );
   SetLong("Dainty in body, yet possessive some muscular strength, the lively "
           "dryad overflows with movement and energy.");
   SetGender("female");
   SetRace("dryad");
   SetSkill("knife attack",1,1);
   SetSkill("knife defense",1,1);
   SetLevel(9);
   SetInventory( ([
                    FOREST_OBJ + "dryadknife" : "wield knife",
               ]) );
   SetCurrency("ducats",10);
}
