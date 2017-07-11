#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("nerf");
  SetRules("", "LIV", "STR", "LIV STR", "STR LIV");
  SetMessageVerbs( ([
    ""        : ({ "feel", }),
    "STR"     : ({ "feel", }),
    "LIV"     : ({ "make", }),
    "STR LIV" : ({ "make", }),
    "LIV STR" : ({ "make", }),
    ]) ); 
  SetMessages( ([
    ""        : "$agent_name $agent_verb much less powerful.",
    "STR"     : "$agent_name $adverb $agent_verb much less powerful.",
    "LIV"     : "$agent_name $agent_verb $target_name feel much less powerful.",
    "LIV STR" : "$agent_name $adverb $agent_verb $target_name feel much less powerful.",
    "STR LIV" : "$agent_name $adverb $agent_verb $target_name feel much less powerful.",
    ]) );
  SetErrorMessage("Hit who with the Nerf[tm] bat?");
}
