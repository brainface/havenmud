#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("fbog");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
        SetMessageVerbs( ([
    "" : "bog",
    "LIV" : "bog",
    "STR" : "bog",
    "STR LIV" : "bog",
    "LIV STR" : "bog",
    ]) );
        SetMessages( ([
          ""        : "$agent_name fucking $agent_verb.",
          "LIV"     : "$agent_name fucking $agent_verb at $target_name.",
          "STR"     : "$agent_name fucking $agent_verb $adverb.",
          "STR LIV" : "$agent_name fucking $agent_verb $adverb at $target_name.",
          "LIV STR" : "$agent_name fucking $agent_verb $adverb at $target_name.",
          ]) );
}


