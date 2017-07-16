#include <lib.h>
#include <size.h>
#include "../vergoth.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("wood golem");
  SetRace("golem");
  SetId( ({ "golem","wood golem" }) );
  SetAdjectives( ({ "wood","wooden" }) );
  SetClass("rogue");
  SetGender("male");
  SetShort("a wooden golem");
  SetLevel(6);
  SetSize(SIZE_LARGE);
  SetLong(
     "The golem is made of a dark wood.  It stands about seven feet tall "
     "and appears to be very well built by a master mage.  Its body "
     "is rounded out and its head has carved facial features.  The "
     "hands of the golem have fingers carved into them, and the feet "
     "have finely detailed toes.");
  SetMorality(-300);
  SetNoCorpse(1);
  SetCombatAction(30, ({ 
     "!emote stomps around.",
     "!emote attempts to crush its enemies.",
     }) );
  SetAction(10, ({
     "!emote turns its head looking around.",
     "!emote creaks as it glances about the room.",
     }) );
  SetDie( "The wood golem makes the tower tremble as it falls." );
 }
