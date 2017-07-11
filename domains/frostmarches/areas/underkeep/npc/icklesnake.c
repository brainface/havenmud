//
// A small snake
// created by Ranquest@Haven
//
#include <lib.h>
#include <damage_types.h>
#include "main.h"
 inherit LIB_NPC;

static void create () {
  npc::create();
  SetKeyName("snake");
    SetAdjectives("small");
  SetShort("a small snake");
  SetLong("The snake is only three feet from head to tip. His "
          "back is green and red, cross-hatched. His malevolent red "
          "eyes glare as he hisses.");
  SetId( ({"snake","serpent"}) );
  SetRace("snake");
  SetClass("animal");
  SetGender("male");
  SetLevel(1);
  SetAction(5,({"The snake hisses in anger."}));
  SetMeleeAttackString("fangs");
  SetMeleeDamageType(PIERCE);
  SetDie("The snake gives a final hiss of anger before collapsing, "
    "limp. The tail continues to twitch for a few minutes.");
}
