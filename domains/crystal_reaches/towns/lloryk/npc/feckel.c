#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("feckel");
  SetShort("Feckel, the Grand Evoker of Llorykshire");
  SetId( ({ "feckel", "evoker" }) );
  SetAdjectives( ({ "feckel", "grand" }) );
  SetRace("halfling");
  SetClass("evoker");
  SetSkill("melee combat",1,2);
  SetGender("male");
  SetLevel(60);
  SetFriends( ({"tandemor vinyok"}) );
  SetLong("Feckel, once the apprentice of the archmage Alhana of Haven"
          " has set up shop in Llorykshire, prefering the quiet "
          "serenity of the small village to the bustling cities of the "
          "east for his work");
  SetSpellBook( ([
    "mesmer barrier" : 100,
    "disintegrate"   : 100,
    "paralysis" : 100,
    "chain lightning" : 100,
    "bolt" : 100,
    ]) );
  SetCombatAction(75, ({
    "!cast mesmer barrier",
    "!cast disintegrate",
    "!cast chain lightning",
    "!cast paralysis",
    "!cast bolt",
    }) );
  SetPlayerTitles( ([
    "newbie" : "the Aspiring Adeptus",
    "mortal" : "the Adeptus",
    "hm"     : "the Greater Adeptus",
    "avatar" : "the Master Adeptus",
    "fighter": "the Sorceror of Llorykshire",
    "rogue"  : "the Shadow Mage",
    ]) );
  SetTown("Lloryk");
  SetFreeEquip( ([
    STD_WEAPON "/pole/staff" : 1,
    ]) );
}
