#include <lib.h>
#include "../forest.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("goblin chief");
  SetShort("the goblin chief");
  SetId( ({ "goblin", "chief" }) );
  SetRace("goblin");
  SetLong("This is the chief of the goblins.  He seems more robust than "
          "the other goblins and his scars reveal that he is skilled in "
          "battle.");
  
  SetClass("fighter");
  SetGender("male");
  SetLevel(random(7)+17);
  SetCurrency("imperials", random(17) + 7 );
  SetMorality(-400);
  SetInventory( ([
  			F_OBJ "longsword" : "wield longsword in right hand",
        F_OBJ "rapier"    : "wield rapier in left hand"
       	]) );
}
