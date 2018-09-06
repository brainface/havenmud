#include <lib.h>  // Needs to be included in all files
#include "../vaashan.h"
inherit LIB_NPC;
static void create() {
  ::create();

  SetKeyName("wolf");
  SetId( "wolf" );
  SetAdjectives( ({ "large", "grey" }) );
  SetShort("a large grey wolf");
  SetLong(
    "Golden-yellow eyes stare out over the long muzzle of this creature, "
    "mercilessly tracking for any possible prey. His narrow chest flows "
    "back into a powerful back and legs, and he is covered in a thick coat "
    "of fur. He is clearly a predator near the top of his food chain, "
    "and a dangerous opponent if provoked."
    );
  SetRace("wolf");
  SetClass("animal");
  SetLevel(60);
  SetGender("male");
  SetAction(5, ({
    "The wolf tilts his head back and howls loudly.",
    "!growl",
    "!sniff"
    }) );
SetMeleeAttackString("teeth");
  SetCombatAction(10, ({
    "The wolf LUNGES foward at you.",
    "The wolf attempts to tear into you!",
    }) );
  SetCorpseItems( ([VAAS_OBJ + "teeth" : 1]) );
}

