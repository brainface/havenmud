// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("duuk");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?"),
  SetMessageVerbs( ([
    "" : ({ "shrink", "talk"}),
    "LIV" : ({ "shrink", "talk"}),
    "STR" : ({ "shrink", "talk"}),
    "STR LIV" : ({ "shrink", "talk"}),
    "LIV STR" : ({ "shrink", "talk"}),
  ]) ),
  SetMessages( ([
    "" : "$agent_name $agent_verb down to midget size and "
    "$agent_verb about anal sex a lot.",
    "LIV" : "$agent_name $agent_verb down to midget size and "
    "$agent_verb to $target_name about anal sex a lot.",
    "STR" : "$agent_name $adverb $agent_verb down to midget "
    "size and $agent_verb about anal sex a lot.",
    "LIV STR" : "$agent_name $adverb $agent_verb down to midget "
    "size and $agent_verb to $target_name about anal sex a lot.",
    "STR LIV" : "$agent_name $adverb $agent_verb down to midget "
    "size and $agent_verb to $target_name about anal sex a lot.",
  ]) );
}
