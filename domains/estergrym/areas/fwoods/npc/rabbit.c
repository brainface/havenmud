#include <lib.h>  // Needs to be included in all files
#include "../vaashan.h"
inherit LIB_NPC;
static void create() {
  ::create();

  SetKeyName("rabbit");
  SetId( "rabbit" );
  SetAdjectives( ({ "savage", "brown" }) );
  SetShort("a savage brown rabbit");
  SetLong(
    "Blood red eyes stare out over the bright pink nose of this creature "
    "as it hops about. His fluffy tail wiggles with each movement, and "
    "his hops have an ominous predatory air to it. His teeth look sharp "
    "and he appears to be rather dangerous."
    );
  SetRace("rodent");
  SetClass("animal");
  SetLevel(50);
  SetGender("male");
  SetAction(5, ({
    "The rabbit hops ominously about.",
    "!growl",
    "!sniff",
    }) );
  SetMeleeAttackString("teeth");
  SetCombatAction(10, ({
    "The rabbit HOPS foward at you.",
    "The rabbit attempts to nibble on you!",
    "!ram", // mahk 2013
    }) );
  SetCorpseItems( ([VAAS_OBJ + "tail" : 1]) );
}

