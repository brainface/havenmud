
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("smooch");
        SetRules("LIV", "STR LIV", "LIV STR");
        SetErrorMessage("Smooch whom?");
        SetMessages( ([
          "LIV"     : "$agent_name $agent_verb $target_name passionately.",
          "STR LIV" : "$agent_name $agent_verb $target_name $adverb.",
          "LIV STR" : "$agent_name $agent_verb $target_name $adverb."
          ]) );
}
