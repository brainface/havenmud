#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("kiss");
  SetRules("LIV","STR LIV","LIV STR");
  SetErrorMessage("Kiss whom?");
  SetMessages( ([
     "LIV"     : "$agent_name $agent_verb $target_name on the lips.",
     "STR LIV" : "$agent_name $agent_verb $target_name $adverb on the lips.",
     "LIV STR" : "$agent_name $agent_verb $target_name $adverb on the lips.",
  ]) );
}
