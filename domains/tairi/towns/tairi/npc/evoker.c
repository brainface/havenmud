
/* An evoker leader */
#include <lib.h>
#include <std.h>
#include "../tairi.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("giu");
  SetShort("Huang Giu, the daimyo's magician");
  SetLong("Huang Giu is the Daimyo's chief magician. "
          "He would be willing to teach the young "
            "the arts of magic. His appearance is "
         "one of pure power and authority, and "
        "his black robes symbolize him in Tairi "
         "as a magician to be feared.");
  SetId( ({ "huang", "giu", "magician", "citizen", "seer" }) );
  SetAdjectives( ({ "huang", "daimyo's" }) );
  SetRace("human");
  SetGender("male");
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetInventory( ([
     STD_CLOTHING "body/black_robe" : "wear robe",
     STD_POLE "staff" : "wield staff",
    ]) );
  SetFreeEquip( ([
    STD_POLE "staff" : 1,
    STD_CLOTHING "body/black_robe" : 1,
    ]) );
  SetClass("evoker");
  SetNoMulti(1);
  SetTown("Tairi");
  SetRestrictRace(1);
  SetPlayerTitles( ([
    "newbie" : "the Apprentice Magician of Tairi",
    "mortal" : "the Magician of Tairi",
    "hm"     : "the High Magician of Tairi",
    "legend" : "the Legendary Magician of Tairi",
    "avatar" : "the Truly Godlike Magician of Tairi",
    ]) );
/*
  SetTaughtSpheres( ({
    "magical evokation", "magical enchantment",
    "magical planar magic", "magical divination",
    }) );
*/
  SetSpellBook( ([
    "chain lightning" : 75,
    "enhanced buffer" : 100,
    "capsule" : 100,
    "fireball" : 100,
    ]) );
  SetAction(5,
    ({ "!cast enhanced buffer",
       "!speak You seek knowledge?",
       "!sigh deeply",
       "!emote closes his eyes, lost in thought.",
       }) );
  SetLevel(40);
  SetCurrency("koken", random(2000));
  SetCombatAction(60, ({
    "!cast chain lightning",
    "!cast enhanced buffer",
    "!cast fireball",
    "!cast capsule",
    }) );
}
