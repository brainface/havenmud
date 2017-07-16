
#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("ruffle");
  SetRules("LIV", "LIV STR", "STR LIV");
  SetErrorMessage("Ruffle someone's hair?");
  SetMessages( ([
    "LIV" : "$agent_name $agent_verb $target_possessive_noun "
    "hair fondly.",
    "LIV STR" : "$agent_name $agent_verb $target_possessive_noun "
    "hair $adverb.",
    "STR LIV" : "$agent_name $agent_verb $target_possessive_noun "
    "hair $adverb."
  ]) );
}
