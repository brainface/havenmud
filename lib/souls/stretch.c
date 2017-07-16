// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("stretch");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "stretch",
    "LIV" : ({ "stretch", "move"}),
    "STR" : "stretch",
    "STR LIV" : ({"stretch", "move"}),
    "LIV STR" : ({"stretch", "move"}),
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb.",
    "LIV" : "$agent_name $agent_verb out and $agent_verb "
    "a little closer to $target_name.",
    "STR" : "$agent_name $adverb $agent_verb.",
    "LIV STR" : "$agent_name $adverb $agent_verb and "
    "$agent_verb a little closer to $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb and "
    "$agent_verb a little closer to $target_name.",
  ]) );
}
