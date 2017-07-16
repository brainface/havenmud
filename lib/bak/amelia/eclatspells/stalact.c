// Spell for marn religion by Amelia@Haven
// Makes a drink (stalact)

#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("stalact");
   SetRules("");
   SetSpellType(SPELL_OTHER);
   SetSkills( ([
                 "faith" : 2,
                 "enchantment" : 2,
            ]) );
   SetMagicCost(10,5);
   SetRequiredMagic(15);
   SetDifficulty(10);
   SetConjure("/spells/obj/stalact");
   SetMessages( ({ ({ ({ "create" }), "$agent_name $agent_verb a "
                                      "cup of stalact." }) }) );
   SetHelp("Syntax:  <cast stalact>\n\n"
           "A cup of stalact is created through this spell.");
}