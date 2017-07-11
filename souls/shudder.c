// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("shudder");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb.",
    "LIV" : "$agent_name $agent_verb at $target_name.",
    "STR" : "$agent_name $adverb $agent_verb.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "at $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "at $target_name.",
  ]) );
}
