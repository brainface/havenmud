// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("whistle");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb to $agent_reflexive.",
    "LIV" : "$agent_name $agent_verb at $target_name.",
    "STR" : "$agent_name $agent_verb $adverb to $agent_reflexive.",
    "LIV STR" : "$agent_name $agent_verb $adverb at $target_name.",
    "STR LIV" : "$agent_name $agent_verb $adverb at $target_name.",
  ]) );
}
