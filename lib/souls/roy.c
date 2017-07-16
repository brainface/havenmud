#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("roy");
  SetRules("", "LIV", "STR", "LIV STR", "STR LIV");
  SetMessageVerbs( ([
    ""    : ({ "think", "are" }),
    "STR" : ({ "think", "are" }),
    "LIV" : ({ "think", "are" }),
    "STR LIV" : ({ "think", "are" }),
    "LIV STR" : ({ "think", "are" }),
    ]) ); 
  SetMessages( ([
    ""    : "$agent_name $agent_verb $agent_nominative $agent_verb about to die horribly.",
    "STR"    : "$agent_name $agent_verb $agent_nominative $agent_verb about to die $adverb.",
    "LIV" : "$agent_name $agent_verb that $target_name $target_verb about to die horribly.",
    "LIV STR" : "$agent_name $agent_verb that $target_name $target_verb about to die $adverb.",
    "STR LIV" : "$agent_name $agent_verb that $target_name $target_verb about to die $adverb.",
    ]) );
  SetErrorMessage("Who is about to pull a Roy?");
}
