// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("sneer");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "curl",
    "STR" : "curl",
    "LIV" : "sneer",
    "STR LIV" : "sneer",
    "LIV STR" : "sneer",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_possessive lip "
    "up in a sneer.",
    "STR" : "$agent_name $adverb $agent_verb $agent_possessive "
    "lip up in a sneer.",
    "LIV" : "$agent_name $agent_verb at $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb at $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb at $target_name.",

  ]) );
}
