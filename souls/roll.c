// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("roll");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "roll",
    "LIV" : "roll",
    "STR" : "roll",
    "STR LIV" : "roll",
    "LIV STR" : "roll",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_possessive eyes.",
    "LIV" : "$agent_name $agent_verb $agent_possessive eyes at $target_name.",
    "STR" : "$agent_name $adverb $agent_verb "
    "$agent_possessive eyes.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "$agent_possessive eyes at $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "$agent_possessive eyes at $target_name.",
  ]) );
}
