#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("shrug");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
        SetMessages( ([
          ""        : "$agent_name $agent_verb $agent_possessive "
                        "shoulders.",
          "LIV"     : "$agent_name $agent_verb $agent_possessive "
                        "shoulders at $target_name.",
          "STR"     : "$agent_name $agent_verb $agent_possessive "
                        "shoulders $adverb.",
          "STR LIV" : "$agent_name $agent_verb $agent_possessive "
                        "shoulders $adverb at $target_name.",
          "LIV STR" : "$agent_name $agent_verb $agent_possessive "
                        "shoulders $adverb at $target_name."
          ]) );
}
