/*   Portia  12-20-98
     The enchanter leader.
     Modified by Gaby 08/16/99 to add spheres
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_LEADER;

 static void create() {
 leader::create();
 SetKeyName("marian");
 SetShort("Marian the Enchantress");
 SetId( ({"marian", "enchantress"}) );
 SetLong(
   "Marian is quite obviously a very "
   "powerful woman. Her stature is alluring and "
   "she seems to fear no one."
   );
 SetGender("female");
 SetClass("enchanter");
 SetLevel(30);
 SetTown("Malveillant");
 SetReligion("Soirin","Soirin");
 SetMorality(-250);
 SetRace("dark-elf");
 SetFreeEquip( ([
    "/std/weapon/pole/staff" : 1,
    ]) );
 SetInventory( ([
   MAL_OBJ3 + "lead_robe" : "wear robe",
   MAL_OBJ3 + "lead_pole" : "wield staff",
   ]) );
 SetSpellBook( ([
    "paralysis" : 100,
    "fireball"  : 100,
    "shock"     : 100,
    "sphere"    : 100,
    ]) );
  SetCombatAction(50, ({
    "!cast paralysis",
    "!cast fireball",
    "!cast shock",
    "!cast sphere",
    }) );
 SetAction(5,
   "!say i could teach you the ways of enchantment.");
 SetPlayerTitles( ([
    "newbie" : "the Apprentice Enchanter of Malveillant",
    "mortal" : "the Enchanter of Malveillant",
    "hm"     : "the Master Enchanter of Malveillant",
    "legend" : "the High Enchanter of Malveillant",
    "avatar" : "the High Lord of Enchantment",
    ]) );
 SetTaughtSpheres( ({"magical enchantment","clerical enchantment",
   "natural enchantment"}) );
 }
