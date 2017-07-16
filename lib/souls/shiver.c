// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("shiver");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb in fear.",
    "LIV" : "$agent_name $agent_verb at $target_name.",
    "STR" : "$agent_name $agent_verb $adverb.",
    "LIV STR" : "$agent_name $agent_verb $adverb "
    "at $target_name.",
    "STR LIV" : "$agent_name $agent_verb $adverb "
    "at $target_name.",
  ]) );
}
