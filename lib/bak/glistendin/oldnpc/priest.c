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
     "overseeing "
   "the induction of new clerics into the religious order and providing "
     "guidance for the people of Glimmerdin.  He seems to embody the "
     "very principles he represents. ");

  SetRace("dwarf");
  SetFriends( ({"tembeg", "rancor", "raal", "rallor", 
    "tabitha", "dwarf", "civak", "guard", "patrol", 
    "samik", "gracchus", "eredos", "dorscha", "bralor"}) );
  SetClass("cleric");
  SetGender("male");
  SetMorality(600);
  SetReligion("Kylin", "Kylin");
  SetTown("Glimmerdin");

  SetUniqueSkills( ([
  ]) );
  SetLevel(75);

  SetAction(1, ({"!say The Truth of Kylin is greater than us "
     "all."}));

  SetCombatAction(6, ({"!cast touch of death", }) );

  SetInventory( ([
    G_OBJ + "leader_weapon"  :  "wield hammer",
  ]) );

  SetTaughtSpheres( ({ "religion kylin",
    "clerical healing", "clerical enchantment",
    "clerical evokation" }) );
  SetSpellBook( ([
    "disperse protections"  :   100,
    "mend"                          :   100,
    "smite"   :   100,
    "wrath"    :   100,
    "jolt"              :  100,
    "wall of force"                        :   100,
    "touch of death"           :   100,
    "turning"         :   100,
    "elven touch"  :   100,
    "cure disease"                          :   100,
    "blessed water"            :   100,
    "sanctify"                     :   100,
    "protect"                      :   100,
    "holy shield"                 :  100,
    "protect"         :  100,
    "divine mana"                      :  100,
    "bless"      :  100,
    "empower"      :  100,
    "create sacred candle"             :  100,
  ]) );

  SetGlobalLeader(1);

  SetPlayerTitles( ([
    "newbie"     :  "the Kylin Acolyte",
    "mortal"     :  "the Priest of Kylin",
    "legend"     :  "the Legendary Warrior of Balance",
    "avatar"     :  "the Supreme Priest of Balance",
    "barbarian"  :  "the Crusader of Kylin",
    "fighter" : "the Patriot of Kylin",
  ]) );

  SetFreeEquip( ([ "/std/weapon/hack/hand-axe.c"   :  1  ]) );
}
