#include <lib.h>
#include <std.h>
#include "../underland.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("nightstalker");
  SetRace("gnome");
  SetGender("male");
  SetShort("Nightstalker the Rogue");
  SetId( ({ "gnome", "rogue", "nightstalker" }) );
  SetAdjectives( ({ }) );
  SetLong(
    "Nightstalker is the Guildermaster of Thieves here in the Underland. "
    "Although his status is known, he avoids any proof that he is the "
    "mastermind behind all crime in the Valley. Those interested in the "
    "shady life may wish to <greet> him."
    );
  SetTown("Underland");
  SetClass("rogue");
  SetLevel(50);
  SetFreeEquipment( ([
    STD_KNIFE "freeknife" : 1,
    ]) );
  SetCurrency("rupies", 5000);
}
