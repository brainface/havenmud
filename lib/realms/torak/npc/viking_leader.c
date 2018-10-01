// Torak@Haven 2017

#include <lib.h>
#include "/domains/crystal_reaches/towns/gwonish/gwonish.h"
#include <std.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetTown("Gwonish");
  SetLimit(1);
  SetRace("lizardman");
  SetGender("male");
  SetClass("viking");
  SetMorality(-100);
  SetLevel(210 + random(12) + random(12) +random(12));
  SetKeyName("zlatkrox");
  SetId( ({ "zlatkrox", "lizardman", "sailor", }) );
  SetAdjectives( ({ "of", "the", "sea" }) );
  SetShort("Zlatkrox of the Sea");
  SetLong(
    "This weathered old lizardman holds himself well. "
    "His leathery skin is lined with scars of "
    "battles long passed. "
    "His gaze appears to stray beyond the horizon. "
    );
  SetPlayerTitles( ([
    "newbie"  : "the Rower",
    "mortal"  : "of the Ruined Sea",
    "hm"      : "Captain $N",
    "legend"  : "the Coastal Ravager",
    "avatar"  : "the Sea King",
    "demigod" : "Admiral $N",
    "necromancer" : "of the Plagued Waters",
    ]) );
  SetCurrency("rounds", 300 + random(100) + random(100) );
  SetInventory( ([
    "/std/clothing/tail_wrap" : "wear wrap",
    "std/clothing/shirt" : "wear shirt",
    "std/clothing/pants" : "wear pants",
    "/std/clothing/shoes" : "wear shoes",
    GWONISH_OBJ + "serrated" : "wield sword",
    "/std/weapon/knife/hunting_knife" : "wield knife",
    ]) );
  SetReligion("Kuthar");
  SetLimit(1);
  SetSkill("knife combat",1,1);
  SetSkill("disorient",1,1);
  SetAction(10, ({
    "!emote sways gently as if he were riding a wave.",
    "!emote tastes the air with a flick of his tongue.",
    "!say remember to bring a shovel.",
    "!say those halflings make good stew, if you know how to cook them.",
    "!trevor",
    "!kitten",
    "!look",
    "!wink",
    "!stretch",
    "!emote sharpens his blades.",
    "!chuckle",
    }) );
  SetFreeEquipment( ([ 
    GWONISH_OBJ "serrated_newbie" : 1,
    "/std/weapon/knife/freeknife" : 1,
    "/std/clothing/body/loin" : 1,	
    ]) );
  SetUniqueSkills( ([
    ]) );
  SetCombatAction(20, ({
    "!disorient",
    }) );
}
