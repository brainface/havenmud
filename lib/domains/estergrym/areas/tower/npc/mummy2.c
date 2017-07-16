#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../defs.h"

inherit LIB_SENTIENT;

static void create() {
  ::create();
  sentient::create();
  SetRace("lamrani");
  SetGender("male");
  SetClass("rogue");
  SetLevel(random(5)+40);
  SetKeyName("mummy");
  SetId( ({ "mummy"}) );
  SetShort("a decaying mummy");
  SetAdjectives( ({ "decaying", "undead" }) );
  SetLong("White wrapping envelopes this humanoid from top to bottom. Dark "
          "green eyes protrude from his wrapping staring out toward his "
          "surroundings. His light blue hands are exposed revealing the "
          "sharp nails on his hands.");
  SetUndead(1);
  SetDie("The mummy releases a sigh and disappears leaving his wrapping in his " 
         "place.");
  SetNoCorpse(1);
  SetMorality(-35);
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
