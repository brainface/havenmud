// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("taunt");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "look",
    "STR" : "look",
    "LIV" : "taunt",
    "LIV STR" : "taunt",
    "STR LIV" : "taunt",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb around for someone "
    "to taunt.",
    "STR" : "$agent_name $adverb $agent_verb around "
    "for someone to taunt.",
    "LIV" : "$agent_name $agent_verb $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "$target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "$target_name.",
  ]) );
}
