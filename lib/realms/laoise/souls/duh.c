// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("duh");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : ({ "point", "say" }),
    "STR" : ({ "point", "say" }),
    "LIV" : ({ "point", "say" }),
    "LIV STR" : ({ "point", "say" }),
    "STR LIV" : ({ "point", "say" }),
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb at $agent_possessive forehead and "
    "$agent_verb \"%^BOLD%^CYAN%^Duh.%^RESET%^\"",
    "STR" : "$agent_name $agent_verb $adverb at $agent_possessive "
    "forehead and $agent_verb \"%^BOLD%^CYAN%^Duh.%^RESET%^\"",
    "LIV" : "$agent_name $agent_verb at $agent_possessive forehead "
    "and $agent_verb \"%^BOLD%^CYAN%^Duh.%^RESET%^\" to $target_name.",
    "LIV STR" : "$agent_name $agent_verb $adverb at $agent_possessive "
    "forehead and $agent_verb \"%^BOLD%^CYAN%^Duh.%^RESET%^\" to $target_name.",
    "STR LIV" : "$agent_name $agent_verb $adverb at $agent_possessive "
    "forehead and $agent_verb \"%^BOLD%^CYAN%^Duh.%^RESET%^\" to $target_name.",
  ]) );
}
