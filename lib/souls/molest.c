// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("molest");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "look",
    "STR" : "look",
    "LIV" : "molest",
    "LIV STR" : "molest",
    "STR LIV" : "molest",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb around for someone to molest.",
    "STR" : "$agent_name $adverb $agent_verb around for someone "
    "to molest.",
    "LIV" : "$agent_name seductively $agent_verb $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb $target_name.",
  ]) );
}
