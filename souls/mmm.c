#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("mmm");
  SetRules("","LIV","STR","STR LIV","LIV STR");
  SetErrorMessage("mmmMmmMmm");
  SetMessageVerbs( ([
     ""        : ({ "go", "lick" }),
     "LIV"     : ({ "go", "lick" }),
     "STR"     : ({ "go", "lick" }),
     "STR LIV" : ({ "go", "lick" }),
     "LIV STR" : ({ "go", "lick" }),
  ]) );
  SetMessages( ([
     ""        : "$agent_name $agent_verb \"MmmMmmMmm\" and $agent_verb "
                 "$agent_possessive lips.",
     "LIV"     : "$agent_name $agent_verb \"MmmMmmMmm\" and $agent_verb "
                 "$target_possessive_noun lips.",
     "STR"     : "$agent_name $agent_verb \"MmmMmmMmm\" $adverb and $agent_verb "
                 "$agent_possessive lips.",
     "STR LIV" : "$agent_name $agent_verb \"MmmMmmMmm\" $adverb and $agent_verb "
                 "$target_possessive_noun lips.",
     "LIV STR" : "$agent_name $agent_verb \"MmmMmmMmm\" $adverb and $agent_verb "
                 "$target_possessive_noun lips.",
  ]) );
}
