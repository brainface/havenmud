#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("joyous child");
   SetId( ({ "child","joyous child"}) );
   SetShort("a joyous child");
   SetLong("Playing with a joyous ball, the child notices your gaze "
           "and turns her head up to look at you.  Laughing, she "
           "pats your hand and smiles up at you with twinkling blue "
           "eyes, half-hidden beneath a wealth of shining blonde "
           "hair.");
   SetLevel(1);
   SetRace("human");
   SetClass("cleric");
   SetGender("female");
   SetMorality(2000);
   SetDie("The child smiles one last sorrowful smile up at you, pats"
          " your hand for a final time, and peaceful dies with a "
          "small tear.");
   SetAction(5, ({ "The child giggles happily.","The child bounces "
                   "up and down, tossing her ball into the air.",
                   "The child drops the ball and it rolls to your "
                   "feet.  Laughing, she dashes over, grabs the "
                   "ball, and smiles at you." }) );
   SetCurrency( ([ "imperials" : 3 ]) );
}
