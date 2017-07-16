// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("swoon");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb dramatically to the ground.",
    "STR" : "$agent_name $agent_verb $adverb to the ground.",
    "LIV" : "$agent_name $agent_verb dramatically at "
      "$target_possessive_noun feet.",
    "STR LIV" : "$agent_name $agent_verb $adverb at $target_possessive_noun "
      "feet.",
    "LIV STR" : "$agent_name $agent_verb $adverb at $target_possessive_noun "
      "feet.",
  ]) );
}
