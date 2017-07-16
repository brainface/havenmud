// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("stagger");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb drunkenly.",
    "STR" : "$agent_name $agent_verb $adverb.",
    "LIV" : "$agent_name $agent_verb into $target_name.",
    "LIV STR" : "$agent_name $agent_verb $adverb "
    "into $target_name.",
    "STR LIV" : "$agent_name $agent_verb $adverb "
    "into $target_name.",
  ]) );
}
