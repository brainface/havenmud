#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("bat");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_possessive eyelashes.",
    "LIV" : "$agent_name $agent_verb $agent_possessive "
    "eyelashes at $target_name.",
    "STR" : "$agent_name $agent_verb $agent_possessive eyelashes "
    "$adverb.",
    "STR LIV" : "$agent_name $agent_verb $agent_possessive "
    "eyelashes $adverb at $target_name.",
    "LIV STR" : "$agent_name $agent_verb $agent_possessive "
    "eyelashes $adverb at $target_name.",
  ]) );
}
