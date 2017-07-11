
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("anna");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
        SetMessageVerbs( ([
          ""    : "whine",
          "LIV" : ({ "think", "are" }),
          "STR" : "whine",
          "STR LIV" : ({ "think", "are" }),
          "LIV STR" : ({ "think", "are" }),
          ]) );
        SetMessages( ([
          ""        : "$agent_name $agent_verb about something that is $agent_possessive own damn fault.",
          "LIV"     : "$agent_name $agent_verb that $target_name $target_verb whining about something that is $target_possessive own damn fault.",
          "STR"     : "$agent_name $agent_verb $adverb about something that is $agent_possessive own damn fault.",
          "STR LIV" : "$agent_name $agent_verb that $target_name $target_verb whining $adverb about something that is $target_possessive own damn fault.",
          "LIV STR" : "$agent_name $agent_verb that $target_name $target_verb whining $adverb about something that is $target_possessive own damn fault.",
          ]) );
}
