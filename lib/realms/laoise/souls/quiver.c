// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("quiver");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb in fear.",
    "STR" : "$agent_name $adverb $agent_verb in fear.",
    "LIV" : "$agent_name $agent_verb in fear of $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb in fear of $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb in fear of $target_name.",
  ]) );
}
