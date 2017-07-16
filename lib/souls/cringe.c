// Aless 2011
// by request from David/Alan

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();

  SetVerb("cringe");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("You are a moron.");
  SetMessages( ([
    "" 		: "$agent_name $agent_verb in fear.",
    "STR" 	: "$agent_name $agent_verb $adverb.",
    "LIV" 	: "$agent_name $agent_verb away from $target_name in fear.",
    "STR LIV" 	: "$agent_name $agent_verb away from $target_name $adverb.",
    "LIV STR" 	: "$agent_name $agent_verb away from $target_name $adverb.",
  ]) );
}
