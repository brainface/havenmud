#include <lib.h>
#include <std.h>
#include "../underland.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("oswold");
  SetRace("gnome");
  SetGender("male");
  SetShort("Oswold the Evoker");
  SetId( ({ "gnome", "oswold", "evoker" }) );
  SetAdjectives( ({ }) );
  SetLong(
    "Oswold is the Chief Evoker for the Underland. His demeanor suggests that "
    "he is one gnome that takes life seriously. Those interested in the magical "
    "arts of evokation should <greet> Oswold."
    );
  SetClass("evoker");
  SetLevel(55);
  SetTown("Underland");
  SetSpellBook( ([
    "fireball" : 100,
    "sphere"   : 100,
    "shock"    : 100,
    "mesmer barrier" : 100,
    ]) );
  SetCombatAction(40, ({
    "!cast shock",
    "!cast fireball",
    "!cast sphere",
    "!cast shock",
    "!cast fireball",
    "!cast shock",
    "!cast shock",
    "!cast mesmer barrier",
  }) );
  SetFreeEquipment( ([
    STD_POLE "staff" : 1,
   ]) );
  SetInventory( ([
    STD_POLE "staff" : "wield staff",
    STD_CLOTHING "body/dgreen_small" : "wear robe",
    ]) );
  SetFirstCommands( ({
    "cast mesmer barrier", "cast mesmer barrier",
  }) );
  SetPlayerTitles( ([
    "newbie" : "the Apprentice Evoker",
    "mortal" : "the Minor Magius",
    "hm"     : "the Adeptus Magius",
    "legend" : "the Superior Seer",
    ]) );
}
