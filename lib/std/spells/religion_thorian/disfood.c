#include <lib.h>
#include <magic.h>
#include <std.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
    spell::create();
    SetSpell("create diseased food");
    SetRules("");
    SetSpellType(SPELL_OTHER);
  SetSkills( ([
    "faith" : 85,
    "necromancy" : 85,
    ]) );
    SetMagicCost(75, 75);
    SetDifficulty(90);
    SetMorality(-5);
  SetConjure(STD_SPELLS "obj/disease_loaf_ob.c");
  SetMessages( ({ 
    ({ "summon", "$agent_name $agent_verb a loaf of bread from black smoke." }),
         }) );
  SetHelp(
    "This spell allows a powerful thorian cleric to create a diseased piece "
    "of bread. "
  );
}
