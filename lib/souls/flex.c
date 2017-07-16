// Laoise@Haven flexes. What a hottie!

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("flex");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_possessive "
    "muscles. What a hottie!",
    "LIV" : "$agent_name $agent_verb $agent_possessive "
    "muscles at $target_name.",
    "STR" : "$agent_name $adverb $agent_verb "
    "$agent_possessive muscles.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "$agent_possessive muscles at $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "$agent_possessive muscles at $target_name.",
  ]) );
}
