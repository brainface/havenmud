/*   Portia  12-20-98
     The diviner leader.
     Modified by Gaby 08/16/99 to add spheres
     
     Modified to be newbie_equipper
     Zalbar 11/22/07
     
     Modified to not be retarded
     Melchezidek
 */

#include <lib.h>
#include <std.h>
#include "../mal.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("westeran");
  SetShort("Westeran, the Charitable");
  SetId( ({"westeran", "equipper"}) );
  SetLong("For years Westeran has been dismissed as a loon"
         " by his fellow dark-elves. His charitable nature"
         " is one that does not fit well into the society"
         " of the Soirin, but his sin can be your benefit. He"
         " is willing to provide items for those new to the"
         " world of adventuring.");

  SetRace("dark-elf");
  SetGender("male");
  SetClass("evoker");
  SetSkill("blunt combat",1,2);
  SetLevel(30);
  SetTown("Malveillant");
  SetReligion("Soirin","Soirin");
  SetMorality(-250); 
  SetLevelLimit(10);
  SetFreeEquipment( ([
    "shirt" : STD_CLOTHING "shirt",
    "shoes" : STD_CLOTHING "shoes",
    "pants" : STD_CLOTHING "pants",
    "coat"  : STD_CLOTHING "coat",
    "fishing pole"  : STD_FISHING "pole",
    "sword" : STD_WEAPON "sword",
    "club"  : STD_WEAPON "newbie_club",
    "epee"  : STD_PIERCE "epee",
    "knife" : STD_KNIFE "hunting_knife",
    "staff" : STD_WEAPON "staff",
    "fife"  : STD_INSTRUMENTS "fife",
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
    "!say I could help you if you are in need.",
    }) );

 }
