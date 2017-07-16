// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("tickle");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "look",
    "LIV" : "tickle",
    "STR" : "look",
    "STR LIV" : "tickle",
    "LIV STR" : "tickle",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb around for "
    "someone to tickle.",
    "LIV" : "$agent_name $agent_verb $target_name.",
    "STR" : "$agent_name $adverb $agent_verb around "
    "for someone to tickle.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "$target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "$target_name.",
  ]) );
}
