// Laoise@Haven

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("muah");
  SetRules("", "LIV", "STR LIV", "LIV STR");
  SetErrorMessage("Do what?");
  SetMessageVerbs( ([
    "" : "cackle",
    "LIV" : "cackle",
    "STR" : "cackle",
    "STR LIV" : "cackle",
    "LIV STR" : "cackle",
  ]) );
  SetMessages( ([
    "" : "$agent_name $agent_verb maniacally \"Muahahahahahahahah!!\"",
    "LIV" : "$agent_name $agent_verb maniacally at "
    "$target_name \"Muahahahahahahahah!!\"",
    "STR" : "$agent_name $agent_verb $adverb "
    "\"Muahahahahahahahah!!\"",
    "STR LIV" : "$agent_name $agent_verb $adverb at "
    "$target_name \"Muahahahahahahahah!!\"",
    "LIV STR" : "$agent_name $agent_verb $adverb at "
    "$target_name \"Muahahahahahahahah!!\"",
  ]) );
}
