#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("wait");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetMessages( ([
     ""        : "$agent_name $agent_verb patiently.",
     "LIV"     : "$agent_name $agent_verb patiently for $target_name.",
     "STR"     : "$agent_name $agent_verb $adverb.",
     "STR LIV" : "$agent_name $agent_verb $adverb for $target_name.",
     "LIV STR" : "$agent_name $agent_verb $adverb for $target_name.",
  ]) );
}
