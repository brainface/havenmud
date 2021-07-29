// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("stare");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name sincerely $agent_verb.",
    "STR" : "$agent_name $adverb $agent_verb.",
    "LIV" : "$agent_name sincerely $agent_verb at $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb at $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb at $target_name.",
  ]) );
}
