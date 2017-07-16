
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("rofl");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "roll",
    "LIV" : "roll",
    "STR" : "roll",
    "STR LIV" : "roll",
    "LIV STR" : "roll",
  ]) );
        SetMessages( ([
          ""        : "$agent_name $agent_verb on the floor laughing.",
          "LIV"     : "$agent_name $agent_verb on the floor laughing at $target_name.",
          "STR"     : "$agent_name $agent_verb on the floor laughing $adverb.",
          "STR LIV" : "$agent_name $agent_verb on the floor laughing $adverb at $target_name.",
          "LIV STR" : "$agent_name $agent_verb on the floor laughing $adverb at $target_name.",
          ]) );
}
