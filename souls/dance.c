#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("dance");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetMessages( ([
     ""        : "$agent_name $agent_verb around. ",
     "LIV"     : "$agent_name $agent_verb with $target_name.",
     "STR"     : "$agent_name $agent_verb around $adverb. ",
     "STR LIV" : "$agent_name $agent_verb $adverb with $target_name.",
     "LIV STR" : "$agent_name $agent_verb $adverb with $target_name.",
  ]) );
}
