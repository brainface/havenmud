
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("snap");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
        SetMessages( ([
          ""        : "$agent_name $agent_verb $agent_possessive " 
                        "fingers.",
          "LIV"     : "$agent_name $agent_verb $agent_possessive " 
                        "fingers at $target_name.",
          "STR"     : "$agent_name $agent_verb $agent_possessive " 
                        "fingers $adverb.",
          "STR LIV" : "$agent_name $agent_verb $agent_possessive " 
                        "fingers $adverb at $target_name.",
          "LIV STR" : "$agent_name $agent_verb $agent_possessive " 
                        "fingers $adverb at $target_name."
          ]) );
}

