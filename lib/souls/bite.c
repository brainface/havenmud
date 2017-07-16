// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("bite");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_possessive lip.",
    "LIV" : "$agent_name $agent_verb $target_name.",
    "STR" : "$agent_name $adverb $agent_verb "
    "$agent_possessive lip.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "$target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "$target_name.",
  ]) );
}
