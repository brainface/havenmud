// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("comfort");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "look",
    "STR" : "look",
    "LIV" : "comfort",
    "STR LIV" : "comfort",
    "LIV STR" : "comfort",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb for comfort.",
    "STR" : "$agent_name $adverb $agent_verb for comfort.",
    "LIV" : "$agent_name $agent_verb $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb $target_name.",
  ]) );
}
