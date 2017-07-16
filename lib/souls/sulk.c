// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("sulk");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "sulk",
    "STR" : "sulk",
    "LIV" : ({"sulk", "frown"}),
    "LIV STR" : ({"sulk", "frown"}),
    "STR LIV" : ({"sulk", "frown"}),
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb furiously.",
    "STR" : "$agent_name $agent_verb $adverb.",
    "LIV" : "$agent_name $agent_verb furiously "
    "and $agent_verb at $target_name.",
    "LIV STR" : "$agent_name $agent_verb $adverb "
    "and $agent_verb at $target_name.",
    "STR LIV" : "$agent_name $agent_verb $adverb "
    "and $agent_verb at $target_name.",
  ]) );
}
