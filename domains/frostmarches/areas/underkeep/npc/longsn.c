//
// A medium-sized snake
// created by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
#include <damage_types.h>
 inherit LIB_SENTIENT;

static void create () {
  sentient::create();
  SetShort("a long snake");
  SetLong
    ("This snake is a full six feet long, and has slitted red eyes "
    "and a set of fangs dripping with venom. His scales look slick and "
    "green.");
  SetKeyName("snake");
    SetAdjectives("long");
  SetId( ({"snake", "serpent"}) );
  SetRace("snake");
  SetClass("animal");
  SetGender("male");
  SetLevel(3);
  SetCurrency("crystals",10);
  SetWander(35);
  SetAction(5,("The snake hisses in anger."));
  SetMeleeAttackString("fangs");
  SetMeleeDamageType(POISON);
  SetDie("The snake gives a final hiss of anger before collapsing, "
    "limp. The tail continues to twitch for a few minutes.");

  SetAction(10,
     ({"!emote hisses.",
     "!twitch"}) );
  SetCombatAction(5,
     ({"!emote rears up to strike."}) );
}
