#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("shoo");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
        SetMessages( ([
          ""        : "$agent_name $agent_verb everyone away impatiently.",
          "LIV"     : "$agent_name $agent_verb $target_name away impatiently.",
          "STR"     : "$agent_name $agent_verb everyone away $adverb.",
          "LIV STR" : "$agent_name $agent_verb $target_name away $adverb.",
          ]) );
}

