// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("gulp");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb nervously.",
    "STR" : "$agent_name $agent_verb $adverb.",
    "LIV" : "$agent_name $agent_verb nervously at $target_name.",
    "LIV STR" : "$agent_name $agent_verb $adverb at $target_name.",
    "STR LIV" : "$agent_name $agent_verb $adverb at $target_name.",
  ]) );
}
