// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("strangle");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : ({ "grab", "strangle" }),
    "STR" : ({ "grab", "strangle" }),
    "LIV" : ({ "grab", "strangle" }),
    "LIV STR" : ({ "grab", "strangle" }),
    "STR LIV" : ({ "grab", "strangle" }),
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb ahold of $agent_possessive throat and "
    "$agent_verb $agent_reflexive!",
    "STR" : "$agent_name $adverb $agent_verb ahold of $agent_possessive "
    "throat and $agent_verb $agent_reflexive!",
    "LIV" : "$agent_name $agent_verb ahold of $target_possessive_noun "
    "throat and $agent_verb $target_objective!",
    "STR LIV" : "$agent_name $adverb $agent_verb ahold of "
    "$target_possessive_noun throat and $agent_verb $target_objective.",
    "LIV STR" : "$agent_name $adverb $agent_verb ahold of "
    "$target_possessive_noun throat and $agent_verb $target_objective.",
  ]) );
}
