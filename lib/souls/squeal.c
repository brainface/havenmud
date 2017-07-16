// Aerelus

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("squeal");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb like a dolphin!",
    "LIV" : "$agent_name $agent_verb like a dolphin at $target_name!",
    "STR" : "$agent_name $agent_verb $adverb like a dolphin!",
    "STR LIV" : "$agent_name $agent_verb $adverb like a dolphin"
    "at $target_name!",
    "LIV STR" : "$agent_name $agent_verb $adverb like a dolphin"
    "at $target_name!",
  ]) );
}
