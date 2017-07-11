// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("perk");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb up $agent_possessive ears.",
    "STR" : "$agent_name $adverb $agent_verb up $agent_possessive ears.",
    "LIV" : "$agent_name $agent_verb up $agent_possessive ears "
    "at $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb up $agent_possessive "
    "ears at $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb up $agent_possessive "
    "ears at $target_name.",
  ]) );
}
