// Spell for marn religion by Amelia@Haven
// Makes food (stalag, a fungus)

#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("stalag");
   SetRules("");
   SetSpellType(SPELL_OTHER);
   SetSkills( ([
                 "faith" : 1,
                 "enchantment" : 1,
            ]) );
   SetMagicCost(5,5);
   SetRequiredMagic(10);
   SetDifficulty(5);
   SetConjure("/spells/obj/stalag");
   SetMessages( ({ ({ ({ "create" }), "$agent_name $agent_verb a "
                                      "bowl of stalag." }) }) );
   SetHelp("Syntax:  <cast stalag>\n\n"
           "A bowl of stalag is created through this spell..");
}