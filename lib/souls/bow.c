
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("bow");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
        SetMessages( ([
          ""        : "$agent_name $agent_verb humbly.",
          "LIV"     : "$agent_name $agent_verb humbly to $target_name.",
          "STR"     : "$agent_name $agent_verb $adverb.",
          "STR LIV" : "$agent_name $agent_verb $adverb to $target_name.",
          "LIV STR" : "$agent_name $agent_verb $adverb to $target_name.",
          ]) );
}
