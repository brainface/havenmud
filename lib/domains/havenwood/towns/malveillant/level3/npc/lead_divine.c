/*   Portia  12-20-98
     The diviner leader.
     Modified by Gaby 08/16/99 to add spheres
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_LEADER;

 static void create() {
 leader::create();
 SetKeyName("westeran");
 SetShort("Westeran, the Diviner");
 SetId( ({"westeran", "diviner"}) );
 SetLong("Westeran has a definite aura about him. "
   "It is almost as if he can see what is in the "
   "future and refuses to share his knowledge. "
   "He will however, share the secrets of his "
   "trade.");
 SetNoJoin(1);
  SetRace("dark-elf");
  SetGender("male");
 SetClass("evoker");
 SetSkill("blunt combat",1,2);
 SetLevel(30);
 SetTown("Malveillant");

 SetReligion("Soirin","Soirin");
 SetMorality(-250);
 SetFreeEquip( ([
    "/std/weapon/blunt/mace" : 1,
    ]) );
 SetInventory( ([
   	MAL_OBJ3 + "lead_robe" : "wear robe",
   	MAL_OBJ3 + "lead_mace" : "wield mace",
   	]) );
 SetSpellBook( ([
    "fireball" : 100,
    "shock"    : 100,
    "sphere"   : 100,
   ]) );
  SetCombatAction(50, ({
    "!cast fireball",
    "!cast shock",
    "!cast sphere",
    }) );
 SetAction(5, ({
    "!say I could teach you to see like I see."}) );
 SetPlayerTitles( ([
    "newbie" : "the Apprentice Diviner of Malveillant",
    "mortal" : "the Diviner of Malveillant",
    "hm" : "the High Lord of Divination",
    "legend" : "the Bringer of Knowledge",
    "avatar" : "the Keeper of Knowledge",
    ]) );
 SetTaughtSpheres( ({ }) );

 }
