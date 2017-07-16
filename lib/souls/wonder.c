
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("wonder");
        SetRules("", "LIV");
        SetMessages( ([
          ""        : "$agent_name $agent_verb.",
          "LIV"     : "$agent_name $agent_verb about $target_name.",
          ]) );
}

