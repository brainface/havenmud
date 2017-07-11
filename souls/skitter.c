// Mahkefel@Haven skitters. What a hottie!

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("skitter");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb creepily.",
    "LIV" : "$agent_name $agent_verb neighborly "
    "at $target_name.",
    "STR" : "$agent_name $agent_verb $adverb.",
    "STR LIV" : "$agent_name $agent_verb $adverb"
    " at $target_name.",
    "LIV STR" : "$agent_name $agent_verb $adverb "
    "at $target_name.",
  ]) );
}

