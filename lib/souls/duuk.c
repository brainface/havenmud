// Laoise @ Haven
// Take that, Duuk

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("duuk");
  SetRules("", "LIV", "STR", "LIV STR");
  SetMessageVerbs( ([ 
    ""    : ({ "nod", "smile", "pretend" }), 
    "LIV"    : ({ "nod", "smile", "pretend" }), 
    "STR"    : ({ "nod", "smile", "pretend" }), 
    "LIV STR"    : ({ "nod", "smile", "pretend" }),
    "STR LIV"    : ({ "nod", "smile", "pretend" }),
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb and $agent_verb as $agent_nominative "
      "$agent_verb to understand.",
    "LIV" : "$agent_name $agent_verb and $agent_verb at $target_name as "
      "$agent_nominative $agent_verb to understand.",
    "STR" : "$agent_name $adverb $agent_verb and $agent_verb as "
      "$agent_nominative $agent_verb to understand.",
    "LIV STR" : "$agent_name $adverb $agent_verb and $agent_verb at "
      "$target_name as $agent_nominative $agent_verb to understand.",
    "STR LIV" : "$agent_name $adverb $agent_verb and $agent_verb at "
      "$target_name as $agent_nominative $agent_verb to understand.",
  ]) );
}
