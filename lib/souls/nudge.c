// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("nudge");
  SetRules("LIV", "LIV STR", "STR LIV");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "LIV" : "$agent_name $agent_verb $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "$target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "$target_name.",
  ]) );
}
