
#include <lib.h>
 inherit LIB_SOUL;

 static void create() {
         ::create();
         SetVerb("oo");
         SetRules("", "LIV");
         SetMessageVerbs( ([ "" : ({ "go" }), "LIV" : ({ "go" }) ]) );
         SetMessages( ([ 
           "" : "$agent_name $agent_verb, \"OoOoOoOOoOOoOO\".",
           "LIV" : "$agent_name $agent_verb, \"OoOoOoOOoOOoOO\" at "
                   "$target_name."
         ]) );
 }

