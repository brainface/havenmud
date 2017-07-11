// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("sob");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb quietly "
    "to $agent_reflexive.",
    "LIV" : "$agent_name $agent_verb quietly "
    "to $target_name.",
    "STR" : "$agent_name $agent_verb $adverb.",
    "LIV STR" : "$agent_name $agent_verb $adverb "
    "to $target_name.",
    "STR LIV" : "$agent_name $agent_verb $adverb "
    "to $target_name.",
  ]) );
}
