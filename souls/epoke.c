#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("poke");
        SetRules("LIV","STR LIV","LIV STR");
        SetErrorMessage("Poke whom?");
        SetMessageVerbs( ([
        "LIV" : "poke",
        "STR LIV" : "poke",
        "LIV STR" : "poke",
        ]) );
        SetMessages( ([
          "LIV"     : "$agent_name $agent_verb $target_name.",
          "STR LIV" : "$agent_name $agent_verb $target_name $adverb.",
          "LIV STR" : "$agent_name $agent_verb $target_name $adverb.",
        ]) );
}
