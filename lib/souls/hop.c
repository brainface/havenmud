
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("hop");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
        SetMessages( ([
          ""        : "$agent_name $agent_verb.",
          "LIV"     : "$agent_name $agent_verb around $target_name.",
          "STR"     : "$agent_name $agent_verb $adverb.",
          "STR LIV" : "$agent_name $agent_verb $adverb around    $target_name.",
          "LIV STR" : "$agent_name $agent_verb $adverb around $target_name.",
          ]) );
}
