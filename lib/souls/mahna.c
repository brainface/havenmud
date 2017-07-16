
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("mahna");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
        SetMessageVerbs( ([
          ""    : "sing",
          "LIV" : ({ "sing" }),
          "STR" : "sing",
          "STR LIV" : ({ "sing" }),
          "LIV STR" : ({ "sing" }),
          ]) );
        SetMessages( ([
          ""        : "$agent_name quietly $agent_verb, \"Mahna Mahna\".",
          "LIV"     : "$agent_name quietly $agent_verb, \"Mahna Mahna\" to $target_name.",
          "STR"     : "$agent_name $adverb $agent_verb, \"Mahna Mahna\".",
          "STR LIV" : "$agent_name $adverb $agent_verb, \"Mahna Mahna\" to $target_name.",
          "LIV STR" : "$agent_name $adverb $agent_verb, \"Mahna Mahna\" to $target_name.",
          ]) );
}
