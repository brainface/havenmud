// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("hi5");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "slap",
    "LIV" : "slap",
    "STR" : "slap",
    "LIV STR" : "slap",
    "STR LIV" : "slap",
  ]) );
  SetMessages( ([
     "" : "$agent_name pathetically $agent_verb "
    "the air.",
     "LIV" : "$agent_name $agent_verb $target_name "
     "a hi-five!",
     "STR" : "$agent_name $adverb $agent_verb "
    "the air.",
     "STR LIV" : "$agent_name $adverb $agent_verb "
    "$target_name a hi-five!",
     "LIV STR" : "$agent_name $adverb $agent_verb "
    "$target_name a hi-five!",
  ]) );
}
