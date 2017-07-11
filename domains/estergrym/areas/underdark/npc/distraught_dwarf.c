#include <lib.h>
#include "../underdark.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("citizen");
  SetId( ({ "dwarf", "citizen" }) );
  SetAdjectives( ({ "distraught", "dwarven", "dwarf" }) );
  SetShort("a distraught dwarven citizen");
  SetLong(
    "This is an extremely woeful looking dwarf. Ragged clothes hang "
    "off the dwarfs haggard body and it looks underfed."
  );
  SetRace("dwarf");  
  SetClass("rogue");
  SetLevel(12);
  
  if(random(10) > 5) {
  SetGender("male");
  }
  else {
  SetGender("female");
  }
  SetCurrency("imperials", 65);
  SetMorality(250);
  SetAction(2, ({ 
    "!speak All gone! All gone, destroyed by the great evil.",
    "!speak If you go deeper into the cave, beware!",
    "!speak Go away!"
  }) );
  SetCombatAction(10, ({
    "!speak Help! Soldiers!",
    "!speak Why do you attack me, I have done nothing to you or anyone."
  }) );
  }
