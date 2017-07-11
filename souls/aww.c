// Laoise@Haven goes Aww..

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("aww");
  SetRules("", "LIV", "STR", "LIV STR", "STR LIV");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "go",
    "LIV" : "go",
    "STR" : "go",
    "LIV STR" : "go",
    "STR LIV" : "go",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb \"%^BOLD%^CYAN%^Awwwwww.....%^RESET%^\"",
    "LIV" : "$agent_name $agent_verb \"%^BOLD%^CYAN%^Awwwwww.....%^RESET%^\" "
    "at $target_name.",
    "STR" : "$agent_name $adverb $agent_verb \""
    "%^BOLD%^CYAN%^Awwwwww.....%^RESET%^\"",
    "LIV STR" : "$agent_name $adverb $agent_verb \""
    "%^BOLD%^CYAN%^Awwwwww.....%^RESET%^\" at $target_name.",
    "STR LIV" : "$agent_name $adverb $agent_verb \""
    "%^BOLD%^CYAN%^Awwwwww.....%^RESET%^\" at $target_name.",
  ]) );
}
