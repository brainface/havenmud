// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("point");
  SetRules("", "LIV", "STR", "LIV STR", "STR LIV");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb wildly around!",
    "LIV" : "$agent_name $agent_verb at $target_name.",
    "STR" : "$agent_name $adverb $agent_verb.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "at $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "at $target_name.",
  ]) );
}
