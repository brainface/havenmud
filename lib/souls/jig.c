// Artanis@Haven (July 2, 2004)

#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("jig");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetMessageVerbs( ([
     ""        : ({ "do" }),
     "LIV"     : ({ "do" }),
     "STR"     : ({ "do" }),
     "LIV STR" : ({ "do" }),
     "STR LIV" : ({ "do" }),
  ]) );
  SetMessages( ([
     ""        : "$agent_name $agent_verb a little jig. ",
     "LIV"     : "$agent_name $agent_verb a little jig with $target_name. ",
     "STR"     : "$agent_name $adverb $agent_verb a little jig. ",
     "LIV STR" : "$agent_name $adverb $agent_verb a little jig with $target_name. ",
     "STR LIV" : "$agent_name $adverb $agent_verb a little jig with $target_name. ",
  ]) );
}
