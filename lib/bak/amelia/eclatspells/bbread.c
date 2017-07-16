// Spell for the Eclat Religion by Amelia@Haven
// Makes banana bread.  Replaces "divine mana"

#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("create banana bread");
   SetRules("");
   SetSpellType(SPELL_OTHER);
   SetSkills( ([
                 "faith" : 2,
                 "enchantment" : 2,
            ]) );
   SetMagicCost(5,5);
   SetRequiredMagic(10);
   SetDifficulty(3);
   SetConjure("/spells/obj/bbread");
   SetMessages( ({ ({ ({ "create" }), "$agent_name $agent_verb a "
                                      "loaf of banana bread." }) }) );
   SetHelp("Syntax:  <cast create banana bread>\n\n"
           "A loaf of banana bread is created through this spell.");
}