#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("fduh");
        SetRules("", "LIV");
        SetMessageVerbs( ([
    "" : "say",
    "LIV" : "say",
    "STR" : "say",
    "STR LIV" : "say",
    "LIV STR" : "say",
    ]) );
        SetMessages( ([
  "" : "$agent_name $agent_verb, \"Fucking Duh.\"",
  "LIV" : "$agent_name $agent_verb to $target_name, \"Fucking Duh.\"",
          ]) );
}


