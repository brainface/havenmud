// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("hate");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
/*
  SetMessageVerbs( ([
    "" : "look",
    "LIV" : "snuggle",
    "STR" : "look",
    "LIV STR" : "snuggle",
    "STR LIV" : "snuggle",
  ]) );
*/
  SetMessages( ([
    "" : "$agent_name $agent_verb you all.",
    "LIV" : "$agent_name $agent_verb $target_name with fiery passion.",
    "STR" : "$agent_name $adverb $agent_verb you all.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "$target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "$target_name.",
  ]) );
}
