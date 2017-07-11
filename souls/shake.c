// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("shake");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_possessive head.",
    "LIV" : "$agent_name $agent_verb $agent_possessive "
   "head at $target_name.",
    "STR" : "$agent_name $adverb $agent_verb "
    "$agent_possessive head.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "$agent_possessive head at $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "$agent_possessive head at $target_name.",
  ]) );
}
