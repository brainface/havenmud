#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("huggle");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
        SetErrorMessage("Huggle someone?");
        SetMessageVerbs( ([
        ""        : ({ "look","need" }),
        "STR"     : ({ "look","need" }),
        ]) );
        SetMessages( ([
          "" : "$agent_name $agent_verb like $agent_nominative $agent_verb a "
            "huggle.",
          "LIV"     : "$agent_name $agent_verb $target_name.",
          "STR"     : "$agent_name $agent_verb $adverb like $agent_nominative "
                      "$agent_verb a huggle.",
          "STR LIV" : "$agent_name $agent_verb $target_name $adverb.",
          "LIV STR" : "$agent_name $agent_verb $target_name $adverb.",
          ]) );
}
