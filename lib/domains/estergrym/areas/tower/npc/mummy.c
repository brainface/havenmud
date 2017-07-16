#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../defs.h"

inherit LIB_SENTIENT;

static void create() {
  ::create();
  sentient::create();
  SetRace("human");
  SetGender("male");
  SetClass("rogue");
  SetLevel(random(5)+55);
  SetKeyName("mummy");
  SetId( ({ "mummy"}) );
  SetShort("a decaying mummy");
  SetAdjectives( ({ "decaying", "undead" }) );
  SetLong("The mummy contains a humanoid shape completely enveloped in white "
          "wrapping. His glowing yellow eyes and green skin and teeth are "
          "exposed revealing his decaying body. His stiff arms are horizontal "
          "with the floor and he walks with a slight stagger.");
  SetUndead(1);
  SetDie("The mummy releases a sigh and disappears leaving his wrapping in  " 
         "place.");
  SetNoCorpse(1);
  SetMorality(-55);
  SetStat("charisma", 201, 1);
  SetResistance(ACID, "high");
  SetResistance(GAS, "high");
  SetResistance(HUNGER, "high");
  SetResistance(DISEASE, "high");
}
  varargs int eventDie(object killer) {
  object wrapping;
  wrapping = new(TOWER_OBJ"wrapping");
  wrapping->eventMove(this_object());
  sentient::eventDie(killer);
  }