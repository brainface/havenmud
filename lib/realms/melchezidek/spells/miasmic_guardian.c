#include <lib.h>
#include <daemons.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
spell::create();
SetSpell("miasmic guardian");
SetRules("");
SetProtectionTypes(ALL_EXTERNAL);
SetShieldType(SHIELD_TIMED);
SetSpellType(SPELL_DEFENSE);
SetSkills( ([
   "faith" : 200,
   "necromancy" : 200,
   ]) );
SetDifficulty(125);
SetMorality(-10);
SetHelp(
       "The miasmic guardian shield spell allows a Soirin pries to"
       " summon forth a dense cloud of poisonous gas to enshroud"
       " them providing protection from all types of damage for"
       " a limited amount of time."
       );
 SetMessages( ({
    ({ ({"call", "enshroud" }),
     "$agent_name $agent_verb forth a %^BLACK%^miasmic guardian%^RESET%^ to"
     " $agent_verb $agent_reflexive"}),
    ({ ({"condense", "strike"}),
     "The %^BLACK%^miasmic guardian%^RESET%^ around $agent_name $agent_verb"
    " as $target_name $target_verb it."}),
   }) );
  }
