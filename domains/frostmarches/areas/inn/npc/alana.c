#include "../inn.h"
#include <lib.h>
inherit LIB_NPC;

static void create()
{
  npc::create();
  SetKeyName("alana");
  SetShort("Alana, the innkeeper's wife");
  SetId( ({ "alana" }) );
  SetLong("This is Alana, the beloved wife of Jord.  She is quite beautiful, standing "
          "about five feet, eight inches tall.  She has lovely light brown hair that "
          "cascades down over her shoulders and she wears a light blue dress that "
          "compliments her well formed hips perfectly.");
  SetRace("elf");
  SetGender("female");
  SetClass("enchanter");
  SetMorality(1000);
  SetLevel(10);
  SetCurrency("senones", random(50)+ 50 );
  SetInventory( ([
                 I_OBJ + "/dress" : "wear dress",
                 I_OBJ + "/necklace" : "wear necklace"
                 ]) );
  SetSpellBook( ([
                 "missile" : 100,
                 "ice ball" : 100,
                 ]) );
  SetAction(8,
    ({
     "!speak Thank the gods we finally fixed the stack.  The smoke was terrible."
     }) );
  SetCombatAction(90,
    ({ 
     "!cast missile",
     "!cast ice ball"
     }) );

}
