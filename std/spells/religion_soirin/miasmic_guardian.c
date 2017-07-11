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
   "evokation" : 200,
   ]) );
SetDifficulty(125);
SetHelp(
       "The miasmic guardian shield spell allows a Soirin priest to"
       " summon forth a dense cloud of poisonous gas to enshroud"
       " them providing protection from all types of damage for"
       " a limited amount of time. This shield can only be cast"
       " upon oneself."
       );
 SetMessages( ({
    ({ ({"call"}),
     "$agent_name $agent_verb forth a %^BLACK%^%^BOLD%^miasmic guardian%^RESET%^ to"
     " enshroud $agent_reflexive."}),
    ({ ({"condense", "strike"}),
     "The %^BLACK%^%^BOLD%^miasmic guardian%^RESET%^ around $agent_name $agent_verb"
    " as $target_name $target_verb it."}),
    ({ ({ "disperse" }),
     "The %^BLACK%^%^BOLD%^miasmic guardian%^RESET%^ around $agent_name $agent_verb"
    " into the air.",}),
   }) );
  }
