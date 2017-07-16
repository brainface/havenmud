#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("mook");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetMessages( ([
     ""        : "$agent_name $agent_verb around wide-eyed from behind $agent_possessive cereal box fort.", 
     "LIV"     : "$agent_name $agent_verb wide-eyed at $target_name from behind $agent_possessive cereal box fort.",
     "STR"     : "$agent_name $adverb $agent_verb around from behind $agent_possessive cereal box fort.",
     "STR LIV" : "$agent_name $adverb $agent_verb at $target_name from behind $agent_possessive cereal box fort.",
     "LIV STR" : "$agent_name $adverb $agent_verb at $target_name from behind $agent_possessive cereal box fort.",
  ]) );
}

