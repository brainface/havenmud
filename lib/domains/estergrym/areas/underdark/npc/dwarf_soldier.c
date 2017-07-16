#include <lib.h>
#include "../underdark.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("soldier");
  SetId( ({ "dwarf", "soldier" }) );
  SetAdjectives( ({ "dwarf", "dwarven" }) );
  SetShort("a dwarven soldier");
  SetLong(
    "A standard infantryman of the dwarven armies. He looks "
    "a little tired and uneasy."
  );
  SetRace("dwarf");
  SetClass("cavalier");
  SetLevel(20);
  SetGender("male");
    
  SetCurrency("imperials", 35);
  SetMorality(250);    
  SetAction(4, ({ 
  	"!speak Beware of the great evil that lurks below.",
    "!speak We have lost so many already, we may be forced to "
    "abandon the caves all together."
  }) );
  SetCombatAction(10, ({
  	"!speak Traitor! Fight the evil not me!",
    "!speak I am to tired to fight anymore.",
    "!speak Help me! Help me my brothers!" 
  }) );
  SetInventory( ([ 
    U_OBJ + "short_spear" : "wield spear in right hand",
    U_OBJ + "steel_chain" : "wear chainmail"
  ]) );

}
