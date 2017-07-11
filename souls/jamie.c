
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("jamie");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
        SetMessageVerbs( ([
          ""    : "think",
          "LIV" : ({ "think" }),
          "STR" : "think",
          "STR LIV" : ({ "think",  }),
          "LIV STR" : ({ "think",  }),
          ]) );
        SetMessages( ([
          ""        : "$agent_name $agent_verb up a daring plan that is sure to get $agent_objective killed.",
          "LIV"     : "$agent_name $agent_verb up a daring plan that is sure to get $agent_objective and $target_name killed.",
          "STR"     : "$agent_name $agent_verb up a daring plan that is sure to get $agent_objective killed $adverb.",
          "STR LIV" : "$agent_name $agent_verb up a daring plan that is sure to get $agent_objective and $target_name killed $adverb.",
          "LIV STR" : "$agent_name $agent_verb up a daring plan that is sure to get $agent_objective and $target_name killed $adverb.",
          ]) );
}
