// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("pfft");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "say",
    "LIV" : "say",
    "STR" : "say",
    "STR LIV" : "say",
    "LIV STR" : "say",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb 'ppppffffffffttttt.'",
    "LIV" : "$agent_name $agent_verb 'ppppffffffffttttt.' "
    "to $target_name.",
    "STR" : "$agent_name $adverb $agent_verb "
    "'ppppffffffffttttt.' ",
    "LIV STR" : "$agent_name $adverb $agent_verb "
    "'ppppffffffffttttt.' to $target_name. ",
    "STR LIV" : "$agent_name $adverb $agent_verb "
    "'ppppffffffffttttt.' to $target_name. ",
  ]) );
}
