/* priest.c - Duhoc Feb.99 */

#include <lib.h>
#include "../glim.h"
inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("eredos");
   SetId( ({"eredos"}) );
   SetAdjectives( ({"stern"}) );
   SetShort("Eredos, War Priest of Kylin");
   SetLong("Eredos is a stern dwarf with a grim look upon his face.  "
     "He serves as the High Priest for Glimmerdin's Kylin Church by "
     "overseeing the induction of new clerics into the religious order and "
     "providing guidance for the people of Glimmerdin.  He seems to embody the "
     "very principles he represents. ");
  SetRace("dwarf");
  SetRestrictRace(1);
  SetRestrictRace(1);
  SetClass("cleric");
  SetGender("male");
  SetMorality(600);
  SetReligion("Kylin");
  SetTown("Glimmerdin");
  SetUniqueSkills( ([
    "blunt attack"   :  1,
    "healing"        :  1,
    "blunt defense"  :  2,
    "melee attack"   :  2,
    "hack defense"   :  3,
    "multi-hand"     :  3,
    "slash defense"  :  3,
    "bargaining"     :  4,
    "fishing"        :  4,
  ]) );
  SetLevel(75);
  SetAction(1, ({"!say The Truth of Kylin is greater than us "
     "all."}));
  SetCombatAction(6, ({"!cast touch of death", }) );
  SetInventory( ([
    G_OBJ + "leader_weapon"  :  "wield hammer",
    ]) );
  SetTaughtSpheres( ({ 
  	"religion kylin",
    "healing", 
    "faith",
     }) );
  SetSpellBook( ([
    "wall of force"    :   100,
    "touch of death"   :   100,
    ]) );
  SetPlayerTitles( ([
    "newbie"     :  "the Dwarven Kylin Acolyte",
    "mortal"     :  "the Dwarven Priest of Kylin",
    "legend"     :  "the Legendary Dwarven Priest of Balance",
    "avatar"     :  "the Supreme Dwarven Priest of Balance",
    "fighter"    :  "the Patriot of Kylin",
    ]) );
  SetFreeEquipment( ([ 
    G_OBJ "war_hammer"  :  1,
    ]) );
}
