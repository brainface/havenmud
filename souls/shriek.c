
#include <lib.h>
inherit LIB_SOUL;
static void create() {
        ::create();
        SetVerb("shriek");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
        SetMessages( ([
          ""        : "$agent_name $agent_verb dramatically.",
          "LIV"     : "$agent_name $agent_verb dramatically at $target_name.",
          "STR"     : "$agent_name $agent_verb $adverb.",
          "STR LIV" : "$agent_name $agent_verb $adverb at $target_name.",
          "LIV STR" : "$agent_name $agent_verb $adverb at $target_name.",
          ]) );
}
