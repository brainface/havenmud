#include <lib.h>
#include "../lake.h";

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("Harvey");
    SetId( ({"harvey","human fisherman","human","fisherman","fisher"}) );
    SetShort("Harvey the fisherman");
    SetLong("The fisherman sits on the dock patiently "
            "fishing. His stature is great for such an "
            "old man, and his posture is perfect. He seems "
            "to have an uncanny nack for fishing as he seems "
            "to be a 'master' fisherman.");
   
    SetRace("human");
    SetClass("merchant"); 
    SetLevel(12);
    SetGender("male");
    SetAction(10, ({ 
    		"!fish with pole",
        "!say oh how I love to fish!",
        }) );
    SetCombatAction(10, ({ 
    		"!say go away!",
        "!say release me, leave an old man alone.",
        }) );
    SetDie("Harvey falls to the ground like a rock as "
            "he dies. ");
    SetInventory( ([ 
    		LAKE_OBJ + "/pole" : "wield pole",
        LAKE_OBJ + "/f_hat" : "wear hat",
        LAKE_OBJ + "/f_pants" : "wear pants",
        ]) );
 }
