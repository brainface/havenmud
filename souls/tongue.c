// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("tongue");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "stick",
    "LIV" : "stick",
    "STR" : "stick",
    "STR LIV" : "stick",
    "LIV STR" : "stick",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_possessive "
    "tongue out.",
    "LIV" : "$agent_name $agent_verb $agent_possessive "
    "tongue out at $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "$agent_possessive tongue out at $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "$agent_possessive tongue out at $target_name.",
    "STR" : "$agent_name $agent_verb $agent_possessive tongue out $adverb.",
  ]) );
}

