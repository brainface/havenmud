//Selket@Haven
//2006
#include <lib.h>
#include "../lisht.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("sefet");
  SetShort("Sefet, the War-Hawk");
  SetId( ({ "sefet", "warrior", "hawk", "trainer" }) );
  SetAdjectives( ({ "war" }) );
  SetLong(
    "Sefet, whose very name means sword, is a large gnoll "
    "of deep strength and bravery. His garb is not the simple "
    "shenti of a scholar but the armour of a great general. "
    "His stern eyes tell you that he does not, in no way, "
    "mess around. At all.");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetClass("fighter");
  SetLevel(50);
  SetGender("male");
  SetTown("Lisht");
  SetAction(5, ({
    "!speak Fight alongside me, for the glory of Selket.",
    "!speak Better to die in battle than an old man in bed.",
    "!speak If you are too afraid to fight, someone who is "
    "not will kill you.",
    "!emote hefts his weapons with a silent grace.",
    }) );
  SetPlayerTitles( ([
      "newbie" : "the Sentry of Lisht",
      "mortal" : "the Soldier of Lisht",
      "hm" : "the Captain of Lisht",
      "legend" : "the Lord Commander of Lisht",
      "avatar" : "the War-Hawk of Lisht",
       ]) );
   SetRestrictRace(1);
  SetFreeEquip( ([
     "/std/weapon/hack/hand-axe" : 1,
    ]) );
  SetInventory( ([
    LISHT_OBJ "b_sandals" : "wear sandals",
    LISHT_OBJ "b_armour" : "wear armour",
    LISHT_OBJ "bl_cloak" : "wear cloak on torso",
    LISHT_OBJ "b_sword" : "wield sword",
  ]) );
}
