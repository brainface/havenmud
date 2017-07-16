// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("pose");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "strike",
    "STR" : "strike",
    "LIV" : "strike",
    "STR LIV" : "strike",
    "LIV STR" : "strike",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb a pose.",
    "STR" : "$agent_name $adverb $agent_verb a pose.",
    "LIV" : "$agent_name $agent_verb a pose at $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb a "
    "pose at $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb a "
    "pose at $target_name.",
  ]) );
}
