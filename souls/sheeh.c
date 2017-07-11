// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("sheeh");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "say",
    "STR" : "say",
    "LIV" : "say",
    "STR LIV" : "say",
    "LIV STR" : "say",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb \"%^BOLD%^CYAN%^Sheeh!%^RESET%^\" ",
    "STR" : "$agent_name $adverb  $agent_verb \""
    "%^CYAN%^%^BOLD%^Sheeh!%^RESET%^\"",
    "LIV" : "$agent_name $agent_verb \"%^BOLD%^CYAN%^Sheeh!%^RESET%^\" "
    "to $target_name.",
    "STR LIV" : "$agent_name $adverb  $agent_verb \""
    "%^BOLD%^%^CYAN%^Sheeh!%^RESET%^\" to $target_name.",
    "LIV STR" : "$agent_name $adverb  $agent_verb \""
    "%^BOLD%^CYAN%^Sheeh!%^RESET%^\" to $target_name.",
  ]) );
}
