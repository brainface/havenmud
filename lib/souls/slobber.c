// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("slobber");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb on $agent_reflexive.",
    "LIV" : "$agent_name lovingly $agent_verb all over $target_name.",
    "STR" : "$agent_name $agent_verb $adverb "
    "on $agent_reflexive.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "all over $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "all over $target_name.",
  ]) );
}
