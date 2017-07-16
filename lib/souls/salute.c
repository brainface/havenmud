// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("salute");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name sharply $agent_verb.",
    "STR" : "$agent_name $adverb $agent_verb.",
    "LIV" : "$agent_name $agent_verb $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb $target_name.",
  ]) );
}
