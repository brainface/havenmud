#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("choo");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetMessageVerbs( ([
     ""        : ({ "go","pump" }),
     "LIV"     : ({ "go","pump" }),
     "STR"     : ({ "go","pump" }),
     "LIV STR" : ({ "go","pump" }),
     "STR LIV" : ({ "go","pump" }),
  ]) );
  SetMessages( ([
     ""        : "$agent_name $agent_verb, \"%^CYAN%^BOLD%^Choo! Choo!%^RESET%^\" "
                 "and $agent_verb $agent_possessive arm.",
     "LIV"     : "$agent_name $agent_verb, \"%^CYAN%^BOLD%^Choo! Choo!%^RESET%^\" "
                 "and $agent_verb $agent_possessive arm at $target_name.",
     "STR"     : "$agent_name $agent_verb, \"%^CYAN%^BOLD%^Choo! Choo!%^RESET%^\" "
                 "and $agent_verb $agent_possessive arm $adverb.",
     "STR LIV" : "$agent_name $agent_verb, \"%^CYAN%^BOLD%^Choo! Choo!%^RESET%^\" "
                 "and $agent_verb $agent_possessive arm $adverb at $target_name.",
     "LIV STR" : "$agent_name $agent_verb, \"%^CYAN%^BOLD%^Choo! Choo!%^RESET%^\" "
                 "and $agent_verb $agent_possessive arm $adverb at $target_name.",
  ]) );
}


