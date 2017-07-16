
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("reno");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
        SetMessageVerbs( ([
          ""        : "find",
          "LIV"     : "find",
          "STR"     : "find",
          "STR LIV" : "find",
          "LIV STR" : "find",
          ]) );
        SetMessages( ([
          ""        : "$agent_name $agent_verb something to be unhappy about.",
          "LIV"     : "$agent_name $agent_verb something about $target_name to be unhappy about.",
          "STR"     : "$agent_name $agent_verb something to be $adverb unhappy about.",
          "STR LIV" : "$agent_name $agent_verb something about $target_name to be $adverb unhappy about.",
          "LIV STR" : "$agent_name $agent_verb something about $target_name to be $adverb unhappy about.",
          ]) );
}
