#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("waber");
  SetMessageVerbs( ([
     ""        : ({ "spasm" }),
     "LIV"     : ({ "spasm" }),
     "STR"     : ({ "spasm" }),
     "LIV STR" : ({ "spasm" }),
     "STR LIV" : ({ "spasm" }),
  ]) );     

  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetMessages( ([
    ""        : "$agent_name $agent_verb uncontrollably.",
    "LIV"     : "$agent_name $agent_verb uncontrollably towards $target_name.",
    "STR"     : "$agent_name $agent_verb uncontrollably and $adverb.",
    "STR LIV" : "$agent_name $agent_verb uncontrollably and $adverb at $target_name.",
    "LIV STR" : "$agent_name $agent_verb uncontrollably and $adverb at $target_name.",
    ]) );
}
                                                                    
