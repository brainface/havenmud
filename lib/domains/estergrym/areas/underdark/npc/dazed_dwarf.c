#include <lib.h>
#include "../underdark.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("citizen");
  SetId( ({ "dwarf", "citizen" }) );
  SetAdjectives( ({ "dazed", "dwarven", "dwarf" }) );
  SetShort("a dazed dwarven citizen");
  SetLong(
    "He is a small dazed looking dwarf. He wanders about with no apparent "
    "purpose, mumbling to himself."
  );
  SetRace("dwarf");
  SetClass("fighter");
  SetLevel(8);
  
  SetGender("male");
  SetCurrency("imperials", 45);
  SetMorality(250);  
  SetAction(2, ({ 
    "!speak All gone! All gone, destroyed by the great evil.",
    "!speak If you enter the cave, beware!",
    "!speak Woe is me, Woe is me!"
  }) );
  SetCombatAction(10, ({
    "!speak Why are you attacking me, haven't I been hurt enough already?" }) );
  SetInventory( ([ 
    U_OBJ + "wood_axe" : "wield axe" 
  ]) );
  }
