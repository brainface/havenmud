// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("raz");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "blow",
    "STR" : "blow",
    "LIV" : "blow",
    "LIV STR" : "blow",
    "STR LIV" : "blow",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb a big, wet "
    "raspberry. 'Thpbppbbbttt!'",
    "LIV" : "$agent_name $agent_verb a big, wet "
    "raspberry at $target_name. 'Thpbppbbbttt!'",
    "STR" : "$agent_name $adverb $agent_verb a "
    "big, wet raspberry. 'Thpbppbbbttt!'",
    "STR LIV" : "$agent_name $adverb $agent_verb a "
    "big, wet raspberry at $target_name. 'Thpbppbbbttt!'",
    "LIV STR" : "$agent_name $adverb $agent_verb a "
    "big, wet raspberry at $target_name. 'Thpbppbbbttt!'",
  ]) );
}
