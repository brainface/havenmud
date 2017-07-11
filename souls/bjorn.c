//  Bjorn wanted "facepalm" instead he gets this
//  Aless wants you to know she totally broke the
//  mud making this. Thank god Mahk isn't a moron.

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();

  SetVerb("bjorn");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetMessageVerbs( ([
     ""        : ({ "facepalm","shake" }),
     "LIV"     : ({ "facepalm","shake" }),
     "STR"     : ({ "facepalm","shake" }),
     "LIV STR" : ({ "facepalm","shake" }),
     "STR LIV" : ({ "facepalm","shake" }),
  ]) );
  SetErrorMessage("You are a moron, try it again.");
  SetMessages( ([
     ""        : "$agent_name $agent_verb and $agent_verb $agent_possessive head sadly.",
     "LIV"     : "$agent_name $agent_verb and $agent_verb $agent_possessive head sadly"
                 " at $target_name.",
     "STR"     : "$agent_name $agent_verb and $agent_verb $agent_possessive head"
                 " $adverb.",
     "STR LIV" : "$agent_name $agent_verb and $agent_verb $agent_possessive head"
                 " $adverb at $target_name.",
     "LIV STR" : "$agent_name $agent_verb and $agent_verb $agent_possessive head"
                 " $adverb at $target_name.",
  ]) );
}
