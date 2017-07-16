//You pervert
#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("grope");
  SetRules("", "STR", "LIV", "STR LIV", "LIV STR");
  SetErrorMessage("Grope whom?");
  SetMessageVerbs( ([
    "" : ({ "say", "grope" }),
    "STR" : ({ "say", "grope" }),
     "LIV"     : ({ "say","grope" }),
     "STR LIV" : ({ "say","grope" }),
     "LIV STR" : ({ "say","grope" }),
  ]) );
  SetMessages( ([
     ""     : "$agent_name $agent_verb \"%^CYAN%^BOLD%^Ohhh...%^RESET%^\" "
                  "as $agent_nominative $agent_verb $agent_reflexive.",
     "STR"     : "$agent_name $agent_verb \"%^CYAN%^BOLD%^Ohhh...%^RESET%^\" "
                  "as $agent_nominative $agent_verb $agent_reflexive $adverb.",
     "LIV"     : "$agent_name $agent_verb \"%^CYAN%^BOLD%^Ohhh...%^RESET%^\" "
                 "as $agent_nominative $agent_verb $target_name.",
     "STR LIV" : "$agent_name $agent_verb \"%^CYAN%^BOLD%^Ohhh...%^RESET%^\" "
                 "as $agent_nominative $agent_verb $target_name $adverb.",
     "LIV STR" : "$agent_name $agent_verb \"%^CYAN%^BOLD%^Ohhh...%^RESET%^\" "
                 "as $agent_nominative $agent_verb $target_name $adverb.",
  ]) );
}
