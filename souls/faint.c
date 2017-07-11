// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("faint");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessages( ([
    "" : "$agent_name $agent_verb dead away.",
    "LIV" : "$agent_name $agent_verb into "
    "$target_possessive_noun arms.",
    "STR" : "$agent_name $adverb $agent_verb.",
    "LIV STR": "$agent_name $adverb $agent_verb "
    "into $target_possessive_noun arms.",
    "LIV STR": "$agent_name $adverb $agent_verb "
    "into $target_possessive_noun arms.",
  ]) );
}
