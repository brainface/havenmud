// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("john");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    ""        : ({ "look", "scream" }),
    "STR"     : ({ "look", "scream" }),
    "LIV"     : ({ "look", "scream" }),
    "LIV STR" : ({ "look", "scream" }),
    "STR LIV" : ({ "look", "scream" }),
  ]) );
  SetMessages( ([
    ""        : "$agent_name $agent_verb over $agent_possessive shoulder and $agent_verb!",
    "STR"     : "$agent_name $agent_verb over $agent_possessive shoulder and $adverb $agent_verb!",
    "LIV"     : "$agent_name $agent_verb over $agent_possessive shoulder and $agent_verb at $target_name!",
    "STR LIV" : "$agent_name $agent_verb over $agent_possessive shoulder and $adverb $agent_verb at $target_name!",
    "LIV STR" : "$agent_name $agent_verb over $agent_possessive shoulder and $adverb $agent_verb at $target_name!",
  ]) );
}
