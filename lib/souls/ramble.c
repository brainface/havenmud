
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("ramble");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
        SetMessages( ([
          ""        : "$agent_name $agent_verb.",
          "LIV"     : "$agent_name $agent_verb to $target_name.",
          "STR"     : "$agent_name $agent_verb $adverb.",
          "STR LIV" : "$agent_name $agent_verb $adverb to $target_name.",
          "LIV STR" : "$agent_name $agent_verb $adverb to $target_name.",
          ]) );
}
