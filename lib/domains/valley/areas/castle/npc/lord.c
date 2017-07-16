#include <lib.h>
inherit LIB_SENTIENT;
#include "../castle.h"

static void create() {
   sentient::create();
   SetKeyName("Vale Lord");
   SetShort("the Vale Lord");
   SetId( ({ "lord","vale lord","lord of the castle","lord of castle",
             "castle lord" }) );
   SetAdjectives( ({ }) );
   SetLong("A distinguished look of importance is shaped into this "
           "man's face.  A well-trimmed beard fills out his face, and "
           "he stands tall, with pride and confidence.  "
           "He commands a presence worthy of the Lord of the Castle.");
   SetGender("male");
   SetRace("dwarf");
   SetClass("fighter");
   SetLevel(30);
   SetAction(1, ({ "!drink beer" }) );
   SetInventory( ([
                    VC_OBJ + "/club" : "wield club",
                    VC_OBJ + "/beer" : 2+random(2),
                    VC_OBJ + "/ring_gld" : "wear ring on left hand",
               ]) );
   SetCurrency("nuggets",8 + random(30));
   SetMorality(100);
}
