#include <lib.h>
#include <std.h>
#include "../haven.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Targeryan");
  SetShort("Targeryan the Shadow");
  SetId( ({ "targeryan", "shadow" }) );
  SetAdjectives( ({ }) );
  SetClass("rogue");
  SetRace("half-elf");
  SetLevel(40);
  SetMorality(-250);
  SetCurrency( ([
     "imperials" : random(100),
     ]) );
  SetInventory( ([
     STD_KNIFE "stiletto" : "wield stiletto",
     ]) );
  SetTown("Haven");
  SetFreeEquip( ([
      STD_KNIFE "freeknife" : 1,
      ]) );
  SetPlayerTitles( ([
     "newbie" : "the Slinker",
     "mortal" : "the Sneak",
     "hm"     : "the Shadow",
     "legend" : "the Knife",
     "avatar" : "the Darkness",
     "priest"    : "the Sinner",
     "merchant"  : "the Fence",
     "enchanter" : "the Curse",
     "fighter"   : "the Killer",
     "evoker"    : "the Torch",
     "sailor"    : "the Storm",
     ]) );
  SetLong(
    "Targeryan the Shadow spends most of his time hiding from the Templars in "
    "Haven Town. His chosen profession is one which the Holy Authorities hope "
    "to stamp out for all time. Asking him to <join rogues> would be a foolish "
    "way to get killed by the Town Guard."
    );
  SetGender("male");
  SetAction(10, ({
    "!speak Remember! Keep to the shadows!",
    "!speak Only the brave... or stupid... join rogues.",
    }) );
}

