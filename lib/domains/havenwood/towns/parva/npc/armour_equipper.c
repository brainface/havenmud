/*   Modified to Armour_newbie_equipper
     Zalbar 11/22/07
 */

#include <lib.h>
#include <std.h>


inherit LIB_EQUIPPER;

 static void create() {
::create();
 SetKeyName("gerardo");
 SetShort("Gerardo Inocencio the Merchant");
 SetId( ({"gerardo", "inocencio", "merchant"}) );
 SetAdjectives( ({"gerardo"}) );
 SetLong("Gerardo is a middle aged dark haired merchant who "
         "\"retired\" recently, due to losing all his goods and "
         "potential income to pirates and vikings.  Gerardo "
         "spends most of his days getting drunk.  If you ask "
         "he may have some armour that he could not sell.");
 SetGender("male");
 SetClass("merchant");
 SetLevel(13);
 SetRace("human");
 SetMorality(150);
 AddAlcohol(GetStatLevel("durability")-10);
 SetInventory( ([
   	]) );
 SetAction(5, ({
   "!yells bring me another Pecunia!",
   "!say I can help you if you need some."
   }) );
 SetLevelLimit(10);
 SetFreeEquipment( ([
     "vest"   : STD_ARMOUR + "free_armour/medium/oldvest",
     "pants"  : STD_ARMOUR + "free_armour/medium/oldpants",
     "boots"  : STD_ARMOUR + "free_armour/medium/oldboots",
     "glove"  : STD_ARMOUR + "free_armour/medium/oldglove",
     "helmet" : STD_ARMOUR + "free_armour/medium/oldhelmet",     
   ]) );
 }
