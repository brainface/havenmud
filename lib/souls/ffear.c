// Laoise@Haven ffears

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("ffear");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
    SetMessageVerbs( ([
    "" : "fear",
    "LIV" : "fear",
    "STR" : "fear",
    "STR LIV" : "fear",
    "LIV STR" : "fear",
  ]) );
  SetMessages( ([
    "" : "$agent_name fucking $agent_verb.",
    "LIV" : "$agent_name fucking $agent_verb $target_name.",
    "STR" : "$agent_name $adverb $agent_verb.",
    "STR LIV" : "$agent_name $adverb $agent_verb $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb $target_name.",
  ]) );
}
