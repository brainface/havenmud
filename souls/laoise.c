#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("laoise");
        SetRules("", "LIV", "STR", "LIV STR");
        SetMessageVerbs( ([ 
          ""    : ({ "twitch", "foam" }), 
          "LIV" : ({ "twitch", "foam" }),
          "STR" : ({ "twitch", "foam" }),
          "LIV STR" : ({ "twitch", "foam" }),
          ]) );
        SetMessages( ([
          ""        : "$agent_name $agent_verb and $agent_verb at the mouth.",
          "LIV"     : "$agent_name $agent_verb and $agent_verb at the mouth because of $target_name.",
          "LIV STR"     : "$agent_name $adverb $agent_verb and $agent_verb at the mouth because of $target_name.",
          "STR"     : "$agent_name $adverb $agent_verb and $agent_verb at the mouth.",
          ]) );
}
