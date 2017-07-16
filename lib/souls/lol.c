// Laoise@Haven laughs out loud

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("lol");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "laugh",
    "LIV" : "laugh",
    "STR" : "laugh",
    "STR LIV" : "laugh",
    "LIV STR" : "laugh",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb out loud.",
    "LIV" : "$agent_name $agent_verb out loud "
    "at $target_name.",
    "STR" : "$agent_name $adverb $agent_verb out loud.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "out loud at $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "out loud at $target_name.",
  ]) );
}
