// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("bwah");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?"),
  SetMessageVerbs( ([
    "" : ({ "grin", "go"}),
    "LIV" : ({ "grin", "go"}),
    "STR" : ({ "grin", "go"}),
    "STR LIV" : ({ "grin", "go"}),
    "LIV STR" : ({ "grin", "go"}),
  ]) ),
  SetMessages( ([
      "" : "$agent_name $agent_verb diabolically and "
          "$agent_verb \"Bwahahahahahahaha!\"",
    "LIV" : "$agent_name $agent_verb diabolically at "
    "$target_name and $agent_verb \"Bwahahahahahahaha!\"",
    "STR" : "$agent_name $agent_verb $adverb and "
    "$agent_verb \"Bwahahahahahahaha!\"",
    "STR LIV" : "$agent_name $agent_verb $adverb at "
    "$target_name and $agent_verb \"Bwahahahahahahaha!\"",
    "LIV STR" : "$agent_name $agent_verb $adverb at "
    "$target_name and $agent_verb \"Bwahahahahahahaha!\"",
  ]) );
}
