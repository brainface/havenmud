#include <lib.h>
#include <std.h>
#include "../gwonish.h"
inherit LIB_EQUIPPER;

static void create() {
   ::create();
   SetKeyName("Tenquax");
   SetId( ({ "tenquax" }) );
   SetShort("Tenquax the Skinner");   
   SetLong(
     "Tenquax the skinner is a dark scaly lizardman with scars covering "     
     "his lean body. In his youth, if you just looked at him, Tenquax "
     "would just kill you.  But now in his old age, he will help those "
     "young ones that need some protection."
   );              
   SetRace("lizardman");
   SetGender("male");
     
   SetMorality(-900);
   SetClass("fighter");
   SetLevel(35);      
   SetFreeEquipment( ([
     "vest"   : STD_ARMOUR + "free_armour/medium/oldvest",
     "pants"  : STD_ARMOUR + "free_armour/medium/oldpants",
     "boots"  : STD_ARMOUR + "free_armour/medium/oldboots",
     "glove"  : STD_ARMOUR + "free_armour/medium/oldglove",
     "helmet" : STD_ARMOUR + "free_armour/medium/oldhelmet",     
   ]) );
   SetLevelLimit(10);   
   SetInventory( ([
     GWONISH_OBJ "serrated"   : "wield sword",
     STD_CLOTHING "body/loin" : "wear loincloth",
     ]) );
   SetAction(1, ({ 
   		"!say Young need my help.",
   		}) );    
}
