// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("fart");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb violently!",
    "STR" : "$agent_name $agent_verb $adverb.",
    "LIV" : "$agent_name $agent_verb towards $target_name.",
    "LIV STR" : "$agent_name $agent_verb $adverb "
    "towards $target_name.",
    "STR LIV" : "$agent_name $agent_verb $adverb "
    "towards $target_name.",
  ]) );
}
