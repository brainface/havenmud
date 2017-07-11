
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("trevor");
        SetMessageVerbs( ([
          ""        : "do",
          "LIV"     : "do",
          ]) );
        SetRules("", "LIV");
        SetMessages( ([
          ""        : "$agent_name $agent_verb an ever so clever trick.",
          "LIV"     : "$agent_name $agent_verb an ever so clever trick for $target_name.",
          ]) );
}

