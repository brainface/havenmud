// Spell for the Eclat Religion by Amelia@Haven
// Makes honey milk.  Replaces "blessed water"

#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("create honey milk");
   SetRules("");
   SetSpellType(SPELL_OTHER);
   SetSkills( ([
                 "faith" : 3,
                 "enchantment" : 3,
            ]) );
   SetMagicCost(6,5);
   SetRequiredMagic(11);
   SetDifficulty(5);
   SetConjure("/spells/obj/honeym");
   SetMessages( ({ ({ ({ "create" }), "$agent_name $agent_verb a "
                                      "cup of honey milk." }) }) );
   SetHelp("Syntax:  <cast create honey milk>\n\n"
           "A cup of honey milk is created through this spell.");
}