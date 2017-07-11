// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("bounce");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb up and down.",
    "STR" : "$agent_name $adverb $agent_verb up and down.",
    "LIV" : "$agent_name $agent_verb over to $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb over to $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb over to $target_name.",
  ]) );
}
