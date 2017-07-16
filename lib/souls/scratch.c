// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("scratch");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_possessive head.",
    "STR" : "$agent_name $adverb $agent_verb "
    "$agent_possessive head.",
    "LIV" : "$agent_name $agent_verb $target_name "
    "behind the ear.",
    "LIV STR" : "$agent_name $adverb $agent_verb $target_name "
    "behind the ear.",
    "STR LIV" : "$agent_name $adverb $agent_verb $target_name "
    "behind the ear.",
  ]) );
}
