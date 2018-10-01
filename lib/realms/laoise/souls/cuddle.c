// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("cuddle");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "look",
    "LIV" : "cuddle",
    "STR" : "look",
    "LIV STR" : "cuddle",
    "STR LIV" : "cuddle",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb for someone "
    "to cuddle with.",
    "LIV" : "$agent_name $agent_verb with $target_name.",
    "STR" : "$agent_name $adverb $agent_verb for "
    "someone to cuddle with.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "with $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "with $target_name.",
  ]) );
}
