// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("cry");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb pathetically.",
    "LIV" : "$agent_name $agent_verb pathetically to $target_name.",
    "STR" : "$agent_name $agent_verb $adverb.",
    "LIV STR" : "$agent_name $agent_verb $adverb "
    "to $target_name.",
    "STR LIV" : "$agent_name $agent_verb $adverb "
    "to $target_name.",
  ]) );
}
