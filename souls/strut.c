// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("strut");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_possessive "
    "stuff.",
    "LIV" : "$agent_name $agent_verb $agent_possessive "
    "stuff, trying to impress $target_name.",
    "STR" : "$agent_name $adverb $agent_verb "
    "$agent_possessive stuff.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "$agent_possessive stuff, trying to impress "
    "$target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "$agent_possessive stuff, trying to impress "
    "$target_name.",
  ]) );
}
