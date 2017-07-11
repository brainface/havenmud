// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("wiggle");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_possessive bottom.",
    "STR" : "$agent_name $adverb $agent_verb $agent_possessive "
    "bottom.",
    "LIV" : "$agent_name $agent_verb $agent_possessive "
    "bottom at $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "$agent_possessive bottom at $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "$agent_possessive bottom at $target_name.",
  ]) );
}
