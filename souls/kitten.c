#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("kitten");
  SetMessageVerbs( ([
    "" : ({ "shout" }),
    "LIV" : ({ "shout" }),
  ]) );
  SetRules("", "LIV");
  SetMessages( ([
    "" : "$agent_name $agent_verb, \"WE ARE YOUR... OVERLORDS!\"",
    "LIV" : "$agent_name $agent_verb at $target_name, \"WE ARE YOUR... OVERLORDS!\"",
    ]) );
}
