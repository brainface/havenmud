// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("nuzzle");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "look",
    "LIV" : "nuzzle",
    "STR" : "look",
    "LIV STR" : "nuzzle",
    "STR LIV" : "nuzzle",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb for someone "
    "to nuzzle.",
    "LIV" : "$agent_name $agent_verb $target_name.",
    "STR" : "$agent_name $adverb $agent_verb for "
    "someone to nuzzle.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "$target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "$target_name.",
  ]) );
}
