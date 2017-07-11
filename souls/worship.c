// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("worship");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "wait",
    "STR" : "wait",
     "LIV" : "worship",
    "LIV STR" : "worship",
    "STR LIV" : "worship",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb to be worshipped.",
    "STR" : "$agent_name $agent_verb to be worshipped.",
    "LIV" : "$agent_name $agent_verb $target_name devotedly.",
    "STR LIV" : "$agent_name $agent_verb $target_name $adverb.",
    "LIV STR" : "$agent_name $agent_verb $target_name $adverb.",
  ]) );
}
