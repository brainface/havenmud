// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("tap");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_possessive "
    "foot impatiently.",
    "LIV" : "$agent_name $agent_verb $target_name "
    "on the shoulder.",
    "STR" : "$agent_name $adverb $agent_verb "
    "$agent_possessive foot.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "$target_name on the shoulder.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "$target_name on the shoulder.",
  ]) );
}
