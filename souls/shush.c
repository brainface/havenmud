#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();

  SetVerb("shush");
  SetRules("LIV","STR LIV","LIV STR");
  SetErrorMessage("Shush whom?");
  SetMessageVerbs( ([
     "LIV" : "shush",
     "STR LIV" : "shush",
     "LIV STR" : "shush",
     ]) );
  SetMessages( ([
     "LIV" : "$agent_name $agent_verb $target_name.",
     "STR LIV" : "$agent_name $agent_verb $target_name $adverb.",
     "LIV STR" : "$agent_name $agent_verb $target_name $adverb.",
     ]) );
}
