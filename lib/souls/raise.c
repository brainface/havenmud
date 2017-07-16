// Laoise@Haven raises an eyebrow

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("raise");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_possessive "
    "eyebrow.",
    "LIV" : "$agent_name $agent_verb $agent_possessive "
    "eyebrow at $target_name.",
    "STR" : "$agent_name $adverb $agent_verb "
    "$agent_possessive eyebrow.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "$agent_possessive eyebrow at $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "$agent_possessive eyebrow at $target_name.",
  ]) );
}
