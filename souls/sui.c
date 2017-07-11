#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("sui");
  SetMessageVerbs( ([
    "" : ({ "say" }),
    "LIV" : ({ "say" }),
  ]) );
  SetRules("", "LIV");
  SetMessages( ([
    "" : "$agent_name $agent_verb, \"Suicide is the answer.\"",
    "LIV" : "$agent_name $agent_verb to $target_name, \"Suicide is the answer.\"",
    ]) );
}
