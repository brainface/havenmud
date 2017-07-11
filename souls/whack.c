// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("whack");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "look",
    "STR" : "look",
    "LIV" : "whack",
    "LIV STR" : "whack",
    "STR LIV" : "whack",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb around for someone to whack.",
    "STR" : "$agent_name $adverb $agent_verb around for someone "
    "to whack.",
    "LIV" : "$agent_name $agent_verb $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb $target_name.",
  ]) );
}
