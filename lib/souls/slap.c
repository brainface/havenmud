// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("slap");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "slap",
    "LIV" : "slap",
    "STR" : "slap",
    "STR LIV" : "slap",
    "LIV STR" : "slap",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_reflexive silly.",
    "LIV" : "$agent_name $agent_verb $target_name with a "
    "resounding %^YELLOW%^BOLD%^SMACK!%^RESET%^",
    "STR" : "$agent_name $adverb $agent_verb $agent_reflexive.",
    "STR LIV" : "$agent_name $adverb $agent_verb $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb $target_name.",
  ]) );
}
