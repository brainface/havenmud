// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("confused");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "look",
    "STR" : "look",
    "LIV" : "look",
    "STR LIV" : "look",
    "LIV STR" : "look",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb confused.",
    "STR" : "$agent_name $agent_verb $adverb confused.",
    "LIV" : "$agent_name $agent_verb confused at "
    "$target_name.",
    "STR LIV" : "$agent_name $agent_verb $adverb confused "
    "at $target_name.",
    "LIV STR" : "$agent_name $agent_verb $adverb confused "
    "at $target_name.",
  ]) );
}
