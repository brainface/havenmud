/*Whap!*/
#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("spank");
  SetRules("LIV","STR LIV","LIV STR");
  SetErrorMessage("Spank whom?");
  SetMessages( ([
     "LIV"     : "$agent_name $agent_verb $target_name hard.",
     "STR LIV" : "$agent_name $agent_verb $target_name $adverb.",
     "LIV STR" : "$agent_name $agent_verb $target_name $adverb.",
  ]) );
}
