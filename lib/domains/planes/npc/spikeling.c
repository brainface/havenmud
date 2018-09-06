/*  i made a baby knife wielding devil youc an't stop me no one can stop me */
// mahk 2018

#include <lib.h>
#include <damage_types.h>
#include <std.h>
#include "../planes.h"
inherit LIB_NPC;
int eventTail();

static void create() {
  npc::create();
  SetKeyName("spikeling");
  SetMorality(-500);
  SetShort("a spikeling");
  SetId( ({ "spikeling", "imp" }) );
  SetAdjectives( ({ "spiked" }) );
  SetRace("imp");
  SetClass("evoker");
  SetLevel(40);
  SetCurrency("imperials", random(800)+1);
  SetGender("female");
  SetLong(
  	"This is a spikeling, a tiny flying thing with a skin full of spikes, a "
  	"mouth full of fangs, and wide, black eyes. It's thought to be something "
  	"like a baby devil, if babies could fly and wield knives in their tail. "
  	"Magic aptitude is distressingly common amongst them."
  );
  SetCombatAction(5, ({
    "!emote stabs wildly at you, missing repeatedly!",
    "!emote yells inarticulate curses.",
    "!cast poison sphere",
    "!cast bolt",
  }) );
  SetInventory( ([
    STD_KNIFE + "small_knife" : 1,
  ]) );
  SetFirstCommands(({"wield knife in tail"}));
}

