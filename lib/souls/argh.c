// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("argh");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : ({ "scream", "tear" }),
    "STR" : ({ "scream", "tear" }),
    "LIV" : ({ "scream", "tear" }),
    "LIV STR" : ({ "scream", "tear" }),
    "STR LIV" : ({ "scream", "tear" }),
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb \"ARGH!!\" and violently "
    "$agent_verb out $agent_possessive hair.",
    "STR" : "$agent_name $agent_verb \"ARGH!!\" and $adverb "
    "$agent_verb out $agent_possessive hair.",
    "LIV" : "$agent_name $agent_verb \"ARGH!!\" at $target_name "
    "and violently $agent_verb out $agent_possessive hair.",
    "STR LIV" : "$agent_name $agent_verb \"ARGH!!\" at $target_name "
    "and $adverb $agent_verb out $agent_possessive hair.",
    "LIV STR" : "$agent_name $agent_verb \"ARGH!!\" at $target_name "
    "and $adverb $agent_verb out $agent_possessive hair.",
  ]) );
}
