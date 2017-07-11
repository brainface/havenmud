#include <lib.h>
#include <magic.h>
#include <std.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
    spell::create();
    SetSpell("create poisoned food");
    SetRules("");
    SetSpellType(SPELL_OTHER);
  SetSkills( ([
    "faith" : 35,
    "necromancy" : 35,
    ]) );
    SetMagicCost(100, 100);
    SetDifficulty(90);
    SetMorality(-5);
  SetConjure(STD_SPELLS "obj/poison_loaf_ob.c");
  SetMessages( ({ 
    ({ "summon", "$agent_name $agent_verb a loaf of bread from black smoke." }),
         }) );
  SetHelp(
    "This spell allows a powerful thorian cleric to create a diseased piece "
    "of bread. "
  );
}
