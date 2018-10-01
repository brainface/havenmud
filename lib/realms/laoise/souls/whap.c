// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("whap");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_reflexive upside the head.",
    "STR" : "$agent_name $adverb $agent_verb $agent_reflexive upside "
    "the head.",
    "LIV" : "$agent_name $agent_verb $target_name upside the head!",
    "LIV STR" : "$agent_name $adverb $agent_verb $target_name upside the head!",
    "STR LIV" : "$agent_name $adverb $agent_verb $target_name upside the head!",
  ]) );
}
