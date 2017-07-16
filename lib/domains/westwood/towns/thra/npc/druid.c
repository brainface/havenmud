/*  Gelfling Druid Leader */

#include <lib.h>
#include "../thra.h"

inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("Sorrowyn");
  SetTown("Thra");
  SetRace("gelfling");
  SetShort("Sorrowyn the Mournful");
  SetId( ({ "sorrowyn", "gelfling" }) );
  SetAdjectives( ({ "mournful" }) );
  SetLong(
    "Sorrowyn is the saddest of the Thra gelflings. Her former home in "
    "the Havenwood was seized by the wild-elves, but she has adapted and "
    "now serves the Westwood equally well. Her natural lore and magical "
    "aura protect the village of Thra from a terrible fate."
  );
  SetMorality(1600);
  SetClass("druid");
  SetSkill("ice magic", 1, 1);
  SetGender("female");
  SetLevel(120);
  SetReligion("Eclat");
  SetFriends( ({ "gelfling" }) );
  SetInventory( ([
      ]) );
  SetSpellBook( ([
    "vermin horde" : 100,
    "wall of wood" : 100,
    "ice storm"    : 100,
    "lunar blast"  : 100,
    ]) );
  SetCombatAction(85, ({ 
    "!cast vermin horde",
    "!cast wall of wood",
    "!cast ice storm",
    "!cast lunar blast",
  }) );
  SetFirstCommands( ({
    "cast wall of wood", "cast wall of wood", "cast wall of wood", "cast wall of wood",
  }) );
  SetPlayerTitles( ([
    "newbie" : "the Seedling",
    "mortal" : "the Blossom",
    "hm"     : "the Growth",
    "legend" : "the Natural Spirit",
    "avatar" : "the Touch of Nature",
    ]) );
}
