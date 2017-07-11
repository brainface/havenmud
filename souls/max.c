#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("max");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetMessageVerbs( ([
     ""        : ({ "are" }),
     "LIV"     : ({ "think", "are" }),
     "STR"     : ({ "are" }),
     "LIV STR" : ({ "think", "are" }),
     "STR LIV" : ({ "think", "are" }),
  ]) );                
  SetMessages( ([
  ""        : "$agent_name $agent_verb the very definition of squishy.",
  "LIV"     : "$agent_name $agent_verb $target_name $target_verb the very definition of squishy.",
  "STR"     : "$agent_name $agent_verb $adverb the very definition of squishy.",
  "STR LIV" : "$agent_name $agent_verb $target_name $target_verb $adverb the very definition of squishy.",
  "LIV STR" : "$agent_name $agent_verb $target_name $target_verb $adverb the very definition of squishy.",
  ]) );                            
}
                                                                  
