// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("tackle");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "look",
    "STR" : "look",
    "LIV" : "tackle",
    "STR LIV" : "tackle",
    "LIV STR" : "tackle",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb around for someone "
    "to tackle.",
    "STR" : "$agent_name $adverb $agent_verb around for "
    "someone to tackle.",
    "LIV" : "$agent_name $agent_verb $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb $target_name.",
  ]) );
}
