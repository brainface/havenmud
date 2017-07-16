// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("scoot");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb around in "
    "a little circle.",
    "LIV" : "$agent_name $agent_verb around "
    "$target_name in a little circle.",
    "STR" : "$agent_name $adverb $agent_verb around "
    "in a little circle.",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "around $target_name in a little circle.",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "around $target_name in a little circle.",
  ]) );
}
