#include <lib.h>

inherit LIB_SOUL;

static void create()
{
  ::create();
  SetVerb("doh");
  SetRules("", "LIV");
  SetMessages( ([
     "" : "$agent_name $agent_verb d'oh! ",
     "LIV" : "$agent_name $agent_verb d'oh at $target_name.",
  ]) );
  SetMessageVerbs( ([
    "" : ({ "shout" }),
    "LIV" : ({ "shout" }),
  ]) );
}
