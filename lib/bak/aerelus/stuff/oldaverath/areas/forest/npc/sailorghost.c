// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("sailor");
   SetShort("a sailor ghost");
   SetId( ({ "ghost","sailor" }) );
   SetAdjectives( ({ "ghost","sailor" }) );
   SetLong("A wicked grin covers the weathered face of the sailor ghost.  His body "
           "moves slower than it did in living, but still has some strength to it.");
   SetGender("male");
   SetRace("human");
   SetClass("fighter");
   SetLevel(7);
   SetInventory( ([
                    FOREST_OBJ + "sailorsword" : "wield sword",
                    FOREST_OBJ + "sailorboots" : "wear boots",
                    FOREST_OBJ + "sailorpants" : "wear pants",
                    FOREST_OBJ + "sailorshirt" : "wear shirt",
//                    FOREST_OBJ + "sailorgloves" : "wear gloves",
               ]) );
   SetCurrency("ducats",20);
   SetMorality(-300);
   SetUndead(1);
}
