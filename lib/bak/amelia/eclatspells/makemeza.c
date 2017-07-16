#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("create meza");
   SetRules("");
   SetSpellType(SPELL_OTHER);
   SetSkills( ([
                 "faith" : 7,
                 "enchantment" : 7,
            ]) );
   SetMagicCost(10,7);
   SetRequiredMagic(17);
   SetDifficulty(5);
   SetConjure("/spells/obj/meza");
   SetMessages( ({ ({ ({ "create" }), "$agent_name $agent_verb a "
                                      "cup of meza." }) }) );
   SetHelp("Syntax:  <cast create meza>\n\n"
           "A cup of steaming hot meza is created through this spell.");
}