// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("love");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_reflexive.",
    "STR" : "$agent_name $agent_verb $agent_reflexive $adverb.",
    "LIV" : "$agent_name $agent_verb $target_name madly!",
    "STR LIV" : "$agent_name $agent_verb $target_name $adverb.",
    "LIV STR" : "$agent_name $agent_verb $target_name $adverb.",
  ]) );
}
