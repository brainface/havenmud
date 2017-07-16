#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("fondle");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetMessageVerbs( ([
     ""        : ({ "want" }),
     "STR"     : ({ "want" }),
  ]) );
  SetMessages( ([
     ""        : "$agent_name $agent_verb someone to fondle $agent_objective.",
     "LIV"     : "$agent_name $agent_verb $target_name.",
     "STR"     : "$agent_name $agent_verb $adverb for someone to fondle "
                 "$agent_objective.",
     "STR LIV" : "$agent_name $agent_verb $target_name $adverb.",
     "LIV STR" : "$agent_name $agent_verb $target_name $adverb.",
  ]) );
}
