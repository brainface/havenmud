// Laoise@Haven laughs out loud

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("lmao");
  SetRules("", "LIV", "STR", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "laugh",
    "LIV" : "laugh",
    "STR" : "laugh",
    "STR LIV" : "laugh",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_possessive ass off.",
    "LIV" : "$agent_name $agent_verb $agent_possessive ass off "
    "at $target_name.",
    "STR" : "$agent_name $adverb $agent_verb $agent_possessive ass off.",
    "LIV STR" : "$agent_name $adverb $agent_verb $agent_possessive "
    "ass off at $target_name.",
  ]) );
}
