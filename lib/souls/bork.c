#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("bork");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetMessageVerbs( ([
     ""        : ({ "go" }),
     "LIV"     : ({ "go" }),
     "STR"     : ({ "go" }),
     "LIV STR" : ({ "go" }),
     "STR LIV" : ({ "go" }),
  ]) );
  SetMessages( ([
     ""        : "$agent_name $agent_verb, \"%^CYAN%^BOLD%^Bork Bork Bork!%^RESET%^\"",
     "LIV"     : "$agent_name $agent_verb, \"%^CYAN%^BOLD%^Bork Bork Bork!%^RESET%^\" "
                 "at $target_name.",
     "STR"     : "$agent_name $agent_verb, \"%^CYAN%^BOLD%^Bork Bork Bork!%^RESET%^\" "
                 "$adverb.",
     "STR LIV" : "$agent_name $agent_verb, \"%^CYAN%^BOLD%^Bork Bork Bork!%^RESET%^\" "
                 "$adverb at $target_name.",
     "LIV STR" : "$agent_name $agent_verb, \"%^CYAN%^BOLD%^Bork Bork Bork!%^RESET%^\" "
                 "$adverb at $target_name.",
  ]) );
}
