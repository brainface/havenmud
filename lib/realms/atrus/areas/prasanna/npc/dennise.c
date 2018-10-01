#include <lib.h>
#include "prasanna.h"
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("dennise");
   SetId( ({ "dennise" }) );
   SetAdjectives( ({ "princess","elven","cute" }) );
   SetShort("Dennise the Elven Princess");
   SetRace("elf");
   SetGender("female");
   SetClass("evoker");
   SetLevel(25);
   SetMorality(15);
   SetLong("This is Dennise, the elven princess. She appears to be "
           "a guest at the palace. A sort of aura of 'cuteness' "
           "surrounds her. She is tall with dark hair. Her eyes "
           "are a dark emerald green, and seem to grin as she smiles. "
           "She has a slight build, with fair skin.");
   SetCurrency("imperials",150);
   SetSpellBook( ([ "fireball" : 100, 
                    "aura" : 100,
                    "buffer" : 100 ]) );
   SetAction(1, ({ "Dennise smiles cutely.",
                   "Dennise summons a cloud and floats around "
                   "on it looking cute." }) );
   SetCombatAction(45, ({ "!cast aura", 
                          "!cast fireball",
                          "!cast buffer" })); 
   SetInventory( ([ PR_OBJ +  "/sandals" : "wear sandals" ,
                    PR_OBJ + "/slinky_dress" : "wear dress" ]) );
}
