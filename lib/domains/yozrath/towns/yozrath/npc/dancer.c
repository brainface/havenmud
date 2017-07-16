#include <lib.h>
#include <std.h>
#include "../yozrath.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("afsoon");
  SetShort("Afsoon the Greater Artist");
  SetId( ({ "afsoon", "artist" }) );
  SetAdjectives( ({ "greater", "great" }) );
  SetRace("human");
  SetBaseLanguage("Padashi");
  SetTown("Yozrath");
  SetGender("female");
  SetLong(
    "The thinly clothed Afsoon the Greater Artist is the reknown expert "
    "musician of Yozrath. Her training leads many prospective dancers to "
    "bigger and better futures."
    );
  SetMorality(-200);
  SetClass("dancer");
  SetLevel(60);
  SetSongBook( ([
    "aural shield" : 100,
    "magical lullaby" : 100,
    "ballad of summer" : 100,
    ]) );
  SetCombatAction(15, ({
    "!sing aural shield",
    "!sing magical lullaby",
    "!sing ballad of summer",
  }) );
  SetInventory( ([
    YOZRATH_OBJ "zills"  : "wield zills",
    ]) );
  SetFreeEquipment( ([
    YOZRATH_OBJ "zills"    : 1,
    STD_OBJ     "stiletto" : 1,
    ]) );
  SetPlayerTitles( ([
    "newbie" : "$N the Student of the Dance",
    "mortal" : "$N the Dancer",
    "hm"     : "$N the Lithe Writher",
    "legend" : "$N the Famed Artist",
    "avatar" : "$N the Desert Rose",
    ]) );
  SetAction(5, ({
    "!speak I can teach you to dance.",
    "!speak Are you interested in the dance?",
  }) );
  SetLimit(1);
}
    