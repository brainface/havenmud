// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("seduce");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "lick",
    "STR" : "lick",
    "LIV" : "lean",
    "STR LIV" : "lean",
    "LIV STR" : "lean",
  ]) );
  SetMessages( ([
    "" : "$agent_name seductively $agent_verb $agent_possessive "
      "lips.",
    "STR" : "$agent_name $adverb $agent_verb $agent_possessive "
      "lips.",
    "LIV" : "$agent_name $agent_verb over to whisper in "
      "$target_possessive_noun ear, seducing $target_objective "
      "with sensual promises.",
    "STR LIV" : "$agent_name $agent_verb over to whisper in "
      "$target_possessive_noun ear, $adverb seducing $target_objective "
      "with sensual promises.",
    "LIV STR" : "$agent_name $agent_verb over to whisper in "
      "$target_possessive_noun ear, $adverb seducing $target_objective "
      "with sensual promises.",
  ]) );
}
