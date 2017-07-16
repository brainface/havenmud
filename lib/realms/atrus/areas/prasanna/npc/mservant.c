#include <lib.h>
#include "prasanna.h"
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("male servant");
   SetId( ({ "male servant" }) );
   SetAdjectives( ({ "male" }) );
   SetShort("a male servant");
   SetRace("human");
   SetGender("male");
   SetClass("enchanter");
   SetLevel(20);
   SetMorality(15);
   SetFriends( ({ "maeralin","servant girl" }) );

   SetLong(" This man is a servant of the al-Ishraq household. "
           "Wearing a leather vest and pants, his every motion is "
           "full of a mechanical, almost drugged grace. His body "
           "is lanky and toned, since muscle is the only tissue "
           "under his skin. His hands are soft and his fingers "
           "show no signs of a hard work.");
   SetCurrency("imperials",150);
   SetSpellBook( ([ "paralysis" : 50, 
                    "aura" : 100 ]) );
   SetAction(1, ({ "The servant glances around." }) ); 
   SetCombatAction(45, ({ "!cast paralysis", 
                                        "!cast aura" })); 
   SetInventory( ([ PR_OBJ +  "/sandals" : "wear sandals" ,
      ]) );
}
