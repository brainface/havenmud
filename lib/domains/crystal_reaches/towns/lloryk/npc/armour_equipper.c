#include <lib.h>
#include <std.h>
inherit LIB_EQUIPPER;

static void create() {
   ::create();
   SetKeyName("Bogdan");
   SetId( ({ "bogdan", "tanner"  }) );
   SetShort("Bogdan, Master of Procurement");   
   SetLong(
     "Bogdan is tall, for a halfling that is, dark haired halfling with "     
     "a small pot belly sticking out from his clothing.  Bogdan "
     "is the self-claimed Master of Procurement of the Shire.  He "
     " \"borrows\" all his leather goods from the goblin village.  "
     "Bogdan is very generous when it comes to the youth of Lloryk."
     );              
   SetRace("halfling");
   SetGender("male");
   SetMorality(100);
   SetClass("rogue");
   SetLevel(10);      
   SetFreeEquipment( ([
     "vest"   : STD_ARMOUR + "free_armour/small/oldvest",
     "pants"  : STD_ARMOUR + "free_armour/small/oldpants",
     "boots"  : STD_ARMOUR + "free_armour/small/oldboots",
     "glove"  : STD_ARMOUR + "free_armour/small/oldglove",
     "helmet" : STD_ARMOUR + "free_armour/small/oldhelmet",     
   ]) );
   SetLevelLimit(10);   
   SetAction(1, ({ 
   	  "!say That goblin leather maker needs to be more careful.",
      "!snicker"
      "!laugh"
      }) );    
}
