#include <lib.h>
inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("dragonfly");
  SetId( ({"dragonfly"}) );
  SetMorality(200);
  SetShort("a dragonfly with wings of emerald hue");
  SetLong("A slender insect with huge eyes and two sets of wings zigs"
    " and zags through the air.  It is dark black with emerald green wings"
    " and eyes of crimson red, it has six slender black legs.",
);
  SetAdjectives( ({"slender","emerald"}) );
  SetRace("insect");
  SetClass("animal");
  SetLevel(1);
  SetGender("neuter");
  SetAction(10, ({
             "The dragonfly zips through the air on his wings of emerald hue.",
             "The dragonfly lands on a rotting log.",
}) );
  SetCombatAction(10, ({
      "The dragonfly buzzes around furiously.",
}) );
}
