//Artanis@Haven smacks you.
#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("smack");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_reflexive "
    "on the forehead.",
     "LIV"     : "$agent_name $agent_verb $target_name.",
    "STR" : "$agent_name $adverb $agent_verb "
    "$agent_reflexive on the forehead.",
     "STR LIV" : "$agent_name $agent_verb $target_name $adverb.",
     "LIV STR" : "$agent_name $agent_verb $target_name $adverb.",
  ]) );
}
