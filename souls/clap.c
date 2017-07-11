
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("clap");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
        SetMessages( ([
          ""        : "$agent_name $agent_verb $agent_possessive hands "
                      "wildly.",
          "LIV"     : "$agent_name $agent_verb $agent_possessive hands "
                      "wildly at $target_name.",
          "STR"     : "$agent_name $agent_verb $agent_possessive hands "
                      "$adverb.",
          "STR LIV" : "$agent_name $agent_verb $agent_possessive hands "
                      "$adverb at $target_name.",
          "LIV STR" : "$agent_name $agent_verb $agent_possessive hands "
                      "$adverb at $target_name."
          ]) );
}
