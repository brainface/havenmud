
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("think");
        SetRules("", "STR");
        SetMessages( ([
          ""        : "$agent_name $agent_verb.",
          "STR"     : "$agent_name $agent_verb $adverb ",
          ]) );
}

