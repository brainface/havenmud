#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("create golden ball");
   SetRules("");
   SetSpellType(SPELL_OTHER);
   SetSkills( ([
                 "faith" : 1,
                 "enchantment" : 1,
            ]) );
   SetMagicCost(7,7);
   SetRequiredMagic(14);
   SetDifficulty(10);
   SetConjure("/spells/obj/goldball");
   SetMessages( ({ ({ ({ "conjure" }), "$agent_name $agent_verb a "
                                      "shining golden ball." }) }) );
   SetHelp("Syntax:  <cast create golden ball>\n\n"
           "Some of the surrounding light is packed into a small "
           "golden ball and conjured by the caster, providing "
           "some light.");
}