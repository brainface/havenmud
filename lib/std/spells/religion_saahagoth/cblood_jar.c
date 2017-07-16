// Thoin@Haven

#include <lib.h>
#include <std.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("create blood jar");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetRequiredHealth(270);
  SetSkills( ([
    "faith" : 70,
    "necromancy" : 70,
  ]) );
  SetHealthCost(150, 40);
  SetMagicCost(75, 40);
  SetReligions("Saahagoth");
  SetMorality(0);
  SetConjure(STD_SPELLS "obj/blood_jar_ob");
  SetMessages( ({ 
    ({ "slit", "$agent_name $agent_verb $agent_possessive hand and as the "
      "blood mingles with $agent_possessive own magical energies a small "
      "blood jar is formed." })
  }) );
  SetHelp(
    "An unusual necromancy spell, one that combines the life and magical "
    "energies of the caster to create a blood jar. The blood jar can then "
    "be used to heal any who drink from it. Mind you some do not like or "
    "enjoy the taste of blood."
  );
}

