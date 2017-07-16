#include <lib.h>
#include <std.h>
inherit LIB_EQUIPPER;

static void create() {
   ::create();
   SetKeyName("Adan");
   SetId( ({ "adan" }) );
   SetShort("Adan the Drunkard");   
   SetLong(
     "Adan is an old balding man with a long grey beard. In his prime "     
     "Adan was a master all things leather. When Adan lost his son to "
     "the sea, he stopped being a tradesman and become this old drunk. "
     "If you ask nice enough, he might part with some of his old "
     "leather goods."
   );              
   SetRace("human");
   SetGender("male");
   SetBaseLanguage("Avera");    
   SetReligion("Aetarin");
     
   SetMorality(900);
   SetClass("merchant");
   SetLevel(10);      
   SetFreeEquipment( ([
     "vest"   : STD_ARMOUR + "free_armour/medium/oldvest",
     "pants"  : STD_ARMOUR + "free_armour/medium/oldpants",
     "boots"  : STD_ARMOUR + "free_armour/medium/oldboots",
     "glove"  : STD_ARMOUR + "free_armour/medium/oldglove",
     "helmet" : STD_ARMOUR + "free_armour/medium/oldhelmet",     
   ]) );
   AddAlcohol(GetStatLevel("durability")/2);
   SetLevelLimit(10);   
   SetAction(1, ({ 
   		"!say Why did he leave me?",
   		"!say I do not need these goods."
   		}) );    
}
