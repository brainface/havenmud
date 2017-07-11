#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("aggressive mold");
  SetId( ({ "mold" }) );
  SetAdjectives( ({ "aggressive" }) );
  SetShort("an aggressive mold");
  SetLong("This is some random mold growing along the floor.");
  SetRace("mold", 1);
  AddLimb("body", 0, 1, 0);
  SetStat("strength", 5, 1);
  SetStat("durability", 5, 1);
  SetStat("agility", 0, 5);
  SetStat("coordination", 0, 5);
  SetStat("wisdom", 0, 5);
  SetStat("charisma", 0, 5);
  SetStat("luck", 0, 5);
  SetStat("intelligence", 0, 5);
  SetClass("animal");
  SetLevel(2);
  SetResistance(DISEASE, "immune");
  SetInvis(1);
  SetMorality(-15);
  SetAction(10, ({
    "Some mold seems to ooze along the floor.",
    "Some mold bubbles.",
    "Some mold dispenses spores into the air.",
  }) );
  SetDie("The mold finally drops into a puddle on the floor.");
  SetNoCorpse(1);
  
}
