#include <lib.h>
inherit LIB_SOUL;

static void create() {
  ::create();
  SetVerb("whee");
  SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
  SetMessageVerbs( ([
     ""        : ({ "twirl" }),
     "LIV"     : ({ "twirl" }),
     "STR"     : ({ "twirl" }),
     "LIV STR" : ({ "twirl" }),
     "STR LIV" : ({ "twirl" }),
  ]) );
  SetMessages( ([
     ""        : "$agent_name $agent_verb about the room screaming "
                 "\"%^YELLOW%^BOLD%^Wheeeeeeeeee!!%^RESET%^\".",
     "LIV"     : "$agent_name $agent_verb around $target_name screaming "
                 "\"%^YELLOW%^BOLD%^Wheeeeeeeeee!!%^RESET%^\".",
     "STR"     : "$agent_name $agent_verb $adverb about the room screaming "
                 "\"%^YELLOW%^BOLD%^Wheeeeeeeeee!!%^RESET%^\".",
     "STR LIV" : "$agent_name $agent_verb $adverb around $target_name screaming "
                 "\"%^YELLOW%^BOLD%^Wheeeeeeeeee!!%^RESET%^\".",
     "LIV STR" : "$agent_name $agent_verb $adverb around $target_name screaming "
                 "\"%^YELLOW%^BOLD%^Wheeeeeeeeee!!%^RESET%^\".",
  ]) );
}
