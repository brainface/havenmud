// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("lick");
	SetRules("", "STR", "LIV", "LIV STR", "STR LIV");
        SetErrorMessage("Do what??");
        SetMessages( ([
          "" : "$agent_name $agent_verb $agent_possessive lips.",
          "LIV"     : "$agent_name $agent_verb $target_name.",
          "STR" : "$agent_name $adverb $agent_verb $agent_possessive lips.",
          "STR LIV" : "$agent_name $agent_verb $target_name $adverb.",
          "LIV STR" : "$agent_name $agent_verb $target_name $adverb.",
          ]) );
}
