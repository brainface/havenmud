
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("grovel");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
        SetMessages( ([
          ""        : "$agent_name $agent_verb.",
          "LIV"     : "$agent_name $agent_verb before $target_name.",
          ]) );
}
