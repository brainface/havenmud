// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("groan");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb loudly.",
    "LIV" : "$agent_name $agent_verb loudly "
    "at $target_name.",
    "STR" : "$agent_name $agent_verb $adverb.",
    "LIV STR" : "$agent_name $agent_verb $adverb "
    "at $target_name.",
    "STR LIV" : "$agent_name $agent_verb $adverb "
    "at $target_name.",
  ]) );
}
