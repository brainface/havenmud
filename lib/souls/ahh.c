// Proximo@Via Imperialis (Adam S Haye)
// 06/04/2003

#include <lib.h>

inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("ahh");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetMessageVerbs( ([
     ""        : ({ "go" }),
     "LIV"     : ({ "go" }),
     "STR"     : ({ "go" }),
     "LIV STR" : ({ "go" }),
     "STR LIV" : ({ "go" }),
  ]) );
  SetMessages( ([
     ""        : "$agent_name $agent_verb, \"%^CYAN%^BOLD%^Ahhhhh.%^RESET%^\"",
     "STR"     : "$agent_name $adverb $agent_verb, \"%^CYAN%^BOLD%^Ahhhhh.%^RESET%^\"",
     "LIV"     : "$agent_name $agent_verb, \"%^CYAN%^BOLD%^Ahhhhh%^RESET%^\" at $target_name. ",
     "LIV STR" : "$agent_name $adverb $agent_verb, \"%^CYAN%^BOLD%^Ahhhhh%^RESET%^\" at $target_name. ",
     "STR LIV" : "$agent_name $adverb $agent_verb, \"%^CYAN%^BOLD%^Ahhhhh%^RESET%^\" at $target_name. ",
  ]) );
}
