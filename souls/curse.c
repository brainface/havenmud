// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("curse");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name vilely $agent_verb $agent_possessive gods and "
      "all the pain they have brought $agent_objective.",
    "STR" : "$agent_name $adverb $agent_verb $agent_possessive gods and "
      "all the pain they have brought $agent_objective.",
    "LIV" : "$agent_name vilely $agent_verb $target_name as well as "
      "$target_possessive_noun race and home.",
    "STR LIV" : "$agent_name $adverb $agent_verb $target_name as well as "
      "$target_possessive_noun race and home.",
    "LIV STR" : "$agent_name $adverb $agent_verb $target_name as well as "
      "$target_possessive_noun race and home.",
  ]) );
}
