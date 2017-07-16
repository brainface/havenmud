#include <lib.h>
#include <std.h>
#include "../grymxoria.h"
#include <vendor_types.h>
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("gesar");
  SetShort("Gesar Bloodaxe, the Apprentice Armourer");
  SetLong( "Gesar, Berton's son, is being trained by his father.  "
           "Berton has high hopes for his son, but Gesar does not "
           "have his father's talents as an armourer.  Gesar does "
           "have a few items he is willing to part with.");
  SetRace("nosferatu");
  SetClass("merchant");
  SetLevel(8); 
  SetGender("male");
  SetTown("Grymxoria");
  SetMorality(-1000);
  SetInventory(  ([
     ]) );
  SetLevelLimit(10);
  SetFreeEquipment( ([
     "vest"   : STD_ARMOUR + "free_armour/medium/oldvest",
     "pants"  : STD_ARMOUR + "free_armour/medium/oldpants",
     "boots"  : STD_ARMOUR + "free_armour/medium/oldboots",
     "glove"  : STD_ARMOUR + "free_armour/medium/oldglove",
     "helmet" : STD_ARMOUR + "free_armour/medium/oldhelmet", 
     ]) );
  SetAction(5, ({
  	 "!say I do not need some of this armour I have made."
  	 }) );
}
