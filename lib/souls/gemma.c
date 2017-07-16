// Mahk

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("gemma");
        SetMessageVerbs( ([
          ""        : "kick",
          "LIV"     : "kick",
          "STR"     : "kick",
          "STR LIV" : "kick",
          "LIV STR" : "kick",
          ]) );

  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name punt $agent_verb the air viciously.",
    "STR" : "$agent_name $adverb punt $agent_verb the air.",
    "LIV" : "$agent_name punt $agent_verb $target_name in the man flaps.",
    "LIV STR" : "$agent_name $adverb punt $agent_verb $target_name in the man flaps.",
    "STR LIV" : "$agent_name $adverb punt $agent_verb $target_name in the man flaps.",
  ]) );
}

