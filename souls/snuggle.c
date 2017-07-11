// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("snuggle");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "look",
    "LIV" : "snuggle",
    "STR" : "look",
    "LIV STR" : "snuggle",
    "STR LIV" : "snuggle",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb for someone "
    "to snuggle with.",
    "LIV" : "$agent_name $agent_verb with $target_name.",
    "STR" : "$agent_name $adverb $agent_verb for "
    "someone to snuggle with.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "with $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "with $target_name.",
  ]) );
}
