#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("pet");
        SetRules("LIV", "STR LIV", "LIV STR");
        SetErrorMessage("Pet whom?");
        SetMessages( ([
          "LIV"     : "$agent_name $agent_verb $target_name fondly.",
          "STR LIV" : "$agent_name $agent_verb $target_name $adverb.",
          "LIV STR" : "$agent_name $agent_verb $target_name $adverb.",
          ]) );
}
