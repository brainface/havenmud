#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("woot");
  SetRules("", "LIV");
  SetMessages( ([
     "" : "$agent_name $agent_verb %^YELLOW%^BOLD%^WOOT%^RESET%^! ",
     "LIV" : "$agent_name $agent_verb %^YELLOW%^BOLD%^WOOT%^RESET%^ "
            "at $target_name.",
    ]) );
  SetMessageVerbs( ([
    "" : ({ "scream" }),
    "LIV" : ({ "scream" }),
    ]) );
}
