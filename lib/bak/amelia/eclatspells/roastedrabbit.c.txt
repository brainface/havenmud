#include <lib.h>
#include <magic.h>
#include <std.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
    spell::create();
    SetSpell("create roasted rabbit");
    SetRules("");
    SetSpellType(SPELL_OTHER);
    SetRequiredMagic(60);
  SetSkills( ([
    "natural magic" : 5,
    "enchantment" : 5,
    ]) );
    SetMagicCost(20, 20);
    SetDifficulty(15);
    SetMorality(0);
  SetConjure(STD_SPELLS "obj/eclat_rabbit.c");
  SetMessages( ({ 
       ({ "create", "$agent_name $agent_verb a roasted rabbit." }),
         }) );
   SetHelp(
          "While a travelling Eclat could easily subsist on the "
	  "local food, the majority prefer a little bounty of "
	  "the forest.  While more difficult that nourishment, "
	  "it provides greater rewards and allows the Eclat the "
	  "joy of a traditional roasted rabbit feast. ");
}
