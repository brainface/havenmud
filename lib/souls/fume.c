// Laoise@Haven fumes

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("fume");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name quietly $agent_verb.",
    "LIV" : "$agent_name quietly $agent_verb "
    "at $target_name.",
    "STR" : "$agent_name $adverb $agent_verb.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "at $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "at $target_name.",
  ]) );
}
