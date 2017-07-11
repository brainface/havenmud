#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();

  SetVerb("shoe");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetMessageVerbs( ([
     ""        : ({ "throw" }),
     "LIV"     : ({ "throw" }),
     "STR"     : ({ "throw" }),
     "LIV STR" : ({ "throw" }),
     "STR LIV" : ({ "throw" }),
  ]) );
  SetErrorMessage("You are a moron, try it again.");
  SetMessages( ([
     ""        : "$agent_name angrily $agent_verb $agent_possessive shoe at the ground!",
     "LIV"     : "$agent_name angrily $agent_verb $agent_possessive shoe at $target_name!",
     "STR"     : "$agent_name $adverb $agent_verb $agent_possessive shoe at the ground!",
     "STR LIV" : "$agent_name $adverb $agent_verb $agent_possessive shoe at $target_name!",
     "LIV STR" : "$agent_name $adverb $agent_verb $agent_possessive shoe at $target_name!",
  ]) );
}

