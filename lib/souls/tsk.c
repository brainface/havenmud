#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
 
  SetVerb("tsk");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb.",
    "LIV" : "$agent_name $agent_verb at $target_name.",
    "STR" : "$agent_name $agent_verb $adverb.",
    "STR LIV" : "$agent_name $agent_verb $target_name $adverb.",
    "LIV STR" : "$agent_name $agent_verb at $target_name $adverb.",
  ]) );
}
