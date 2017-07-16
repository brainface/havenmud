#include <lib.h>
#include <std.h>
#include "../averath.h"

inherit LIB_EQUIPPER;

static void create() {
   ::create();
   SetKeyName("Porthos");
   SetId( ({ "Porthos" }) );
   SetShort("Porthos the Armourer");
   SetLong(
     "Porthos is an old veteran of the city watch. His gray hair is long and "
     "unkept, and his once handsome face is lined with scars. However, his "
     "arms and chest display muscles cultivated from years of exercise. "
     "Though too old for active duty guarding the city, he still serves "
     "the watch by supplying them with arms and armour from his forge."
   );
   SetRace("human");
   SetGender("male");
   SetMorality(50);
   SetClass("fighter");
   SetLevel(10);
   SetBaseLanguage("Avera");
   SetReligion("Aetarin");

   SetInventory( ([
     "/std/clothing/body/black_robe" : "wear robe",
     STD_SLASH "longsword" : "wield sword",
   ]) );

   SetFreeEquipment( ([
     "vest" : STD_ARMOUR + "free_armour/medium/oldvest",
     "pants" : STD_ARMOUR + "free_armour/medium/oldpants",
     "boots" : STD_ARMOUR + "free_armour/medium/oldboots",
     "glove" : STD_ARMOUR + "free_armour/medium/oldglove",
     "helmet" : STD_ARMOUR + "free_armour/medium/oldhelmet",
   ]) );

   SetLevelLimit(10);
   SetAction(10, ({
     "!say Don't go out in the wilderness with the dwarves and witches unarmoured!",
     "!say I have a small supply of spare armour, for the young of Averath."
   }) );
}
