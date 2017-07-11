// Laoise@Haven swears. often.

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("swear");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb violently and "
    "profusely.",
    "LIV" : "$agent_name $agent_verb violently and "
    "profusely at $target_name.",
    "STR" : "$agent_name $adverb $agent_verb.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "at $target_name.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "at $target_name.",
  ]) );
}
