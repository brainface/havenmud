// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("pat");
  SetRules("", "LIV", "STR", "LIV STR", "STR LIV");
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_reflexive "
    "on the back.",
    "LIV" : "$agent_name $agent_verb $target_name "
    "on the back.",
    "STR" : "$agent_name $adverb $agent_verb $agent_reflexive "
    "on the back.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "$target_name on the back.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "$target_name on the back.",
  ]) );
}
