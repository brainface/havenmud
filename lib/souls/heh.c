#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("heh");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetMessageVerbs( ([
     ""        : "chuckle",
     "LIV"     : "chuckle",
     "STR"     : "chuckle",
     "STR LIV" : "chuckle",
     "LIV STR" : "chuckle",
  ]) );
  SetMessages( ([
     ""        : "$agent_name $agent_verb out, \"%^CYAN%^Heh Heh Heh%^RESET%^\".",
     "LIV"     : "$agent_name $agent_verb out, \"%^CYAN%^Heh Heh Heh.%^RESET%^\" at "
                 "$target_name.",
     "STR"     : "$agent_name $agent_verb $adverb out, "
                 "\"%^CYAN%^Heh Heh Heh%^RESET%^\".",
     "STR LIV" : "$agent_name $agent_verb $adverb out, "
                 "\"%^CYAN%^Heh Heh Heh.%^RESET%^\" at $target_name.",
     "LIV STR" : "$agent_name $agent_verb $adverb out, "
                 "\"%^CYAN%^Heh Heh Heh.%^RESET%^\" at $target_name.",
  ]) );
}
