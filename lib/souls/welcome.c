// Artanis@Haven (August 12, 2004)

#include <lib.h>

inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("welcome");
  SetRules("LIV", "STR LIV", "LIV STR");
  SetErrorMessage("Who do you wish to welcome?");
  SetMessages( ([
     "LIV"     : "$agent_name $agent_verb $target_name.",
     "STR LIV" : "$agent_name $adverb $agent_verb $target_name.",
     "LIV STR" : "$agent_name $adverb $agent_verb $target_name.",
  ]) );
}
