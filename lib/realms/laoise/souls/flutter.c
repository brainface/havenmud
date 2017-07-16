// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("flutter");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name sexily $agent_verb $agent_possessive eyelashes.",
    "LIV" : "$agent_name $agent_verb $agent_possessive eyelashes at "
    	"$target_name.",
    "STR" : "$agent_name $adverb $agent_verb $agent_possessive eyelashes.",
    "STR LIV" : "$agent_name $adverb $agent_verb $agent_possessive eyelashes "
    	"at $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb $agent_possessive eyelashes "
    	"at $target_name.",
  ]) );
}
