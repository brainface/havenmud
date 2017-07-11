
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("nod");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
        SetMessages( ([
          ""        : "$agent_name $agent_verb solemnly.",
          "LIV"     : "$agent_name $agent_verb at $target_name.",
          "STR"     : "$agent_name $agent_verb $adverb.",
          "STR LIV" : "$agent_name $agent_verb $adverb at $target_name.",
          "LIV STR" : "$agent_name $agent_verb $adverb at $target_name.",
          ]) );
}

