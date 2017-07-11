#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("slush");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetMessageVerbs( ([
     ""        : ({ "are" }),
     "LIV"     : ({ "are" }),
     "STR"     : ({ "are" }),
     "LIV STR" : ({ "are" }),
     "STR LIV" : ({ "are" }),
  ]) );
  SetMessages( ([
     ""        : "$agent_name $agent_verb not sure why $agent_nominative blurted that out.",
     "LIV"     : "$agent_name $agent_verb not sure why $agent_nominative blurted that out to $target_name.",
     "STR"     : "$agent_name $agent_verb not sure why $agent_nominative blurted that out so $adverb.",
     "STR LIV" : "$agent_name $agent_verb not sure why $agent_nominative blurted that out so $adverb to $target_name.",
     "LIV STR" : "$agent_name $agent_verb not sure why $agent_nominative blurted that out so $adverb to $target_name.",
  ]) );
}

