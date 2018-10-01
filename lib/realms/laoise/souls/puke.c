// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("puke");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb loudly!",
    "LIV" : "$agent_name $agent_verb all over $target_name (ewwwwwww).",
    "STR" : "$agent_name $agent_verb $adverb!",
    "LIV STR" : "$agent_name $agent_verb $adverb all over $target_name (ewwwwwww).",
    "STR LIV" : "$agent_name $agent_verb $adverb all over $target_name (ewwwwwww).",
  ]) );
}
