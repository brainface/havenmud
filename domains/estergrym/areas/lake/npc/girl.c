#include <lib.h>
#include "../lake.h";
inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("A human girl");
    SetId( ({"girl","human girl","elf"}) );
    SetShort("a human girl");
    SetLong("This young human is about four feet and three inches tall, and weighs " 
            "about eighty pounds. She seems not to have a care in the world as "
            "she wanders aimlessly about.");
    
    SetRace("human");
    SetClass("rogue");
    SetLevel(7);
    SetGender("female");
    SetMorality(100);
    SetAction(10, ({ 
    	"!emote dances around the area.",
      "!go east",
      "!go west",
      "!go north",
      "!go south",
      "!go northeast",
      "!go southeast",
      "!go northwest",
      "!go southwest", }) );
    SetDie("The girl looks at you with a frown.");
    SetInventory( ([ 
    	LAKE_OBJ + "/smallknife" : "wield knife", 
    	]) );
}

