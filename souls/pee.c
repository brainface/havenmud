//Oh man I really have to pee...
#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("pee");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetMessages( ([
     ""        : "$agent_name $agent_verb on the ground.",
     "LIV"     : "$agent_name $agent_verb on $target_name.",
     "STR"     : "$agent_name $agent_verb $adverb on the ground.",
     "STR LIV" : "$agent_name $agent_verb $adverb on $target_name.",
     "LIV STR" : "$agent_name $agent_verb $adverb on $target_name.",
  ]) );
}
