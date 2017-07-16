
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("showoff");
        SetRules("", "LIV", "STR", "STR LIV", "LIV STR");
        SetMessageVerbs( ([ 
          "" : ({ "show" }), 
          "LIV" : ({ "show" }), 
          "STR" : ({ "show" }),
          "LIV STR" : ({ "show" }),
          "STR LIV" : ({ "show" })
]) );    
        SetMessages( ([
          ""        : "$agent_name $agent_verb off.",
          "LIV"     : "$agent_name $agent_verb off to $target_name.",
          "STR"     : "$agent_name $agent_verb off $adverb.",
          "STR LIV" : "$agent_name $agent_verb off $adverb to $target_name.",
          "LIV STR" : "$agent_name $agent_verb off $adverb to $target_name.",
          ]) );
}
