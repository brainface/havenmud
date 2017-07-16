// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("congrat");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "congratulate",
    "STR" : "congratulate",
    "LIV" : "congratulate",
    "STR LIV" : "congratulate",
    "LIV STR" : "congratulate",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_reflexive.",
    "STR" : "$agent_name $adverb $agent_verb $agent_reflexive.",
    "LIV" : "$agent_name $agent_verb $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "$target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "$target_name.",
  ]) );
}
