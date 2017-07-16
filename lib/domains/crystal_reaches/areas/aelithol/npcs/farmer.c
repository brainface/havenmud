#include <lib.h>
#include "../aelithol.h"
inherit LIB_NPC;
    static void create() {
    npc::create();
    SetKeyName("farmer");
    SetId( ({ "farmer", "old farmer", "an old farmer" }) );
    SetAdjectives( ({"old"}) );
    SetShort("an old farmer");
    SetLong("The farmer's skin is sun baked from the many years "
      "working the fields.  He has never gained anything "
      "from his many years except age and the happiness "
      "of  living the simple life that his ancestors began "
      "many ages ago.");               
    
    SetRace("human");
    SetClass("rogue");
    SetGender("male");
    SetLevel(10);
    SetMorality(550); 
    SetInventory( ([
      OBJS + "/shirt" : "wear shirt",
      OBJS + "/pants" : "wear pants",
    ]) );    
    SetAction(10, ({
      "!speak I remember the old days back when I was a boy.  "
        "That forest over in the east used to be a right nice place to "
        "walk around in, but lately its gone all freakish and weird!  "
        "I have heard some strange, strange things have come out "
        "of that place!",
      "!speak Of course those little folks aren't concerned.  They "
        "just sit around and smoke and eat and smoke and eat.  "
        "Thats all it ever is with them!",								
    })  );
    SetFriends( ({"cow" }));
}
