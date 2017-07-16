#include <lib.h>
#include <std.h>
#include "../underland.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("Willem Claude");
  SetRace("gnome");
  SetGender("male");
  SetShort("Willem Claude the Illusionist Extraordinaire");
  SetId( ({ "gnome", "willem", "claude", "illusionist", }) );
  SetAdjectives( ({ "willem", "extraordinaire", }) );
  SetLong(
    "Willem Claude is the Chief Illusionist here in the Underland. "
    "His skill with the surreal and not-so-real is famous. Those "
    "wishing to join the ranks of the illusionists should <greet> "
    "him."
    );
  SetTown("Underland");
  SetClass("illusionist");
  SetLevel(25);
  SetSpellBook( ([
    "shimmer" : 100,
    "blinding color" : 100,
    "confusion" : 100,
    ]) );
  SetFirstCommands( ({ 
    "!cast shimmer", "!cast shimmer",
  }) );
  SetInventory( ([
    STD_KNIFE "small_knife" : "wield knife",
    ]) );
  SetCombatAction(30, ({
    "!cast shimmer",
    "!cast blinding color",
    "!cast blinding color",
    "!cast blinding color",
    "!cast confusion",
    "!cast confusion",
  }) );
  SetPlayerTitles( ([
    "newbie" : "the Flash in the Pan",
    "mortal" : "the Illusionist",
    "hm"     : "the Cynical Charlatan",
    "legend" : "the Miracle Mendicant",
    ]) );
  SetFreeEquipment( ([
    STD_KNIFE "freeknife" : 1,
    ]) );
}
