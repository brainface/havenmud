// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("sniff");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb the air.",
    "STR" : "$agent_name $adverb $agent_verb the air.",
    "LIV" : "$agent_name $agent_verb $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "$target_name.", 
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "$target_name.", 
  ]) );
}
