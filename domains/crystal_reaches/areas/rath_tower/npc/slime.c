/*  A nasty slime */
#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("green slime");
  SetProperty("no bump", 1);
  SetInvis(1);
  SetRace("slime", 1);
  AddLimb("ooze", 0, 1);
  SetStat("durability", 40, 1);
  SetStat("strength", 40, 1);
  SetStat("luck", 10, 4);
  SetNoCorpse(1);
  SetDie("The ooze drips back onto the floor spent of desire to kill you.");
  SetMeleeDamageType(ACID);
  SetResistance(ALL_DAMAGE, "immune");
  SetResistance(HEAT, "none");
  SetResistance(MAGIC, "none");
  SetResistance(SHOCK, "weakness");
  SetSkill("melee combat", 200, 1);
  SetLevel(25);
  SetShort("a puddle of green slime");
  SetId( ({ "puddle", "slime", "ooze" }) );
  SetAdjectives( ({ "puddle", "of", "green" }) );
  SetLong("This is a large and slick puddle of some type of slime.");
  SetMorality(-1000);
  SetEncounter(101);
  SetAction(10, 
    ({ "The puddle of slime bubbles ominously.",
       "The puddle of slime seems to ooze out and back again."
    }) );
}
