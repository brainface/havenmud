// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("quirk");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb an eyebrow.",
    "STR" : "$agent_name $adverb $agent_verb an eyebrow.",
    "LIV" : "$agent_name $agent_verb an eyebrow at "
    "$target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb an "
    "eyebrow at $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb an "
    "eyebrow at $target_name.",
  ]) );
}
