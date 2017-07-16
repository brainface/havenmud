#include <lib.h>
#include <std.h>
#include "../mal.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("siolyn");
  SetShort("Siolyn the Seductive");
  SetId( ({ "siolyn", "seductive" }) );
  SetAdjectives( ({ "seductive", "great" }) );
  SetRace("dark-elf");
  SetTown("Malveillant");
  SetGender("female");
  SetLong(
    "The thinly clothed Siolyn the Seductive is the dark-elven expert "
    "of the dance. Her training leads many prospective dancers to "
    "bigger and better futures."
    );
  SetMorality(-1000);
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
    MAL_OBJ "zills"  : "wield zills",
    ]) );
  SetFreeEquipment( ([
    MAL_OBJ "zills"    : 1,
    STD_OBJ     "stiletto" : 1,
    ]) );
  SetPlayerTitles( ([
    "newbie" : "$N the Acolyte of the Dance",
    "mortal" : "$N the Seductive",
    "hm"     : "$N the Lithe Writher",
    "legend" : "$N the Passionate Vision",
    "avatar" : "$N the Poisoned Flower",
    ]) );
  SetAction(5, ({
    "!speak I can teach you to dance.",
    "!speak Are you interested in the dance?",
  }) );
  SetLimit(1);
}
    
