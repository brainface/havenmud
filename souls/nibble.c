#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("nibble");
  SetRules("LIV", "STR LIV", "LIV STR");
  SetErrorMessage("Nibble on Someone?");
  SetMessages( ([
     "LIV"     : "$agent_name $agent_verb on $target_possessive_noun ear.",
     "STR LIV" : "$agent_name $agent_verb $adverb on $target_possessive_noun ear.",
     "LIV STR" : "$agent_name $agent_verb $adverb on $target_possessive_noun ear.",
  ]) );
}
