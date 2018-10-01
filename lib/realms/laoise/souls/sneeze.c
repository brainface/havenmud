// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("sneeze");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb.",
    "LIV" : "$agent_name $agent_verb on $target_name.",
    "STR" : "$agent_name $adverb $agent_verb.",
    "LIV STR" : "$agent_name $adverb $agent_verb on $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb on $target_name.",
  ]) );
}
