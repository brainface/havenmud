#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <dirs.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("create stamina potion");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  //SetRequiredMagic(30);
  SetSkills( ([
    "natural magic" : 10,
    "enchantment" : 10,
  ]) );
  SetMagicCost(50, 10);
  SetStaminaCost(230,40);
  SetDifficulty(15);
  SetConjure(DIR_SPELLS "/test_spells/obj/stamina_potion");
  SetMessages( ({ ({ 
      "summon", 
      "$agent_name $agent_verb a dark yellow potion out of thin air."
  }) }) );
  SetHelp(
    "This prayer allows the caster to create a potion of stamina. "
    "The healer may use the potion to relieve his own fatigue, or it "
    "may be passed on to aid another. Be warned creating the elixir "
    "is a very tiring process."
  );
}

