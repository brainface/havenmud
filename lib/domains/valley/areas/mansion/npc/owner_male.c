/* the owner of the mansion
      kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"

inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("John Roman");
  SetShort("John Roman");
  SetId( ({"john roman", "john",  "roman", "owner", "man" }) );
  SetLong("John Roman looks like a very rich man and is obviously the "
          "owner of this large mansion. His eyes look as if he is always "
          "thinking of his business, and his cold stare can make even the "
          "toughest guard fear him.");
  SetRace("human");
  SetClass("merchant");
  SetLevel(35);
  SetMorality(-125);
  SetGender("male");
  SetInventory( ([
      MANSION_OBJ + "cer_longsword" : "wield sword",
               ]) );
    
  SetCurrency( ([
           "imperials" : 700,
             ]) );
  SetAction(6,
        ({ "Mr. Roman looks at you as if you don't belong in the room." 
           }) );
  SetCombatAction(9,
         ({"!slice"}) );
  }
