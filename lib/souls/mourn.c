#include  <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("mourn");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Mourn what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb.",
    "LIV" : "$agent_name $agent_verb for $target_name.",
    "STR"  : "$agent_name $agent_verb $adverb.",
    "STR LIV" : "$agent_name $agent_verb $adverb for $target_name.",
    "LIV STR" : "$agent_name $agent_verb $adverb for $target_name.",
  ]) );
}
