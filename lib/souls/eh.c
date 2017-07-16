// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("eh");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : ({ "raise", "mumble" }),
    "STR" : ({ "raise", "mumble" }),
    "LIV" : ({ "raise", "mumble" }),
    "STR LIV" : ({ "raise", "mumble" }),
    "LIV STR" : ({ "raise", "mumble" }),
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb $agent_possessive eyebrow and "
      "$agent_verb \"Eh?\"",
    "STR" : "$agent_name $agent_verb $agent_possessive eyebrow and "
      "$adverb $agent_verb \"Eh?\"",
    "LIV" : "$agent_name $agent_verb $agent_possessive eyebrow at "
      "$target_name and $agent_verb \"Eh?\"",
    "STR LIV" : "$agent_name $agent_verb $agent_possessive eyebrow at "
      "$target_name and $adverb $agent_verb \"Eh?\"",
    "LIV STR" : "$agent_name $agent_verb $agent_possessive eyebrow at "
      "$target_name and $adverb $agent_verb \"Eh?\"",
  ]) );
}
