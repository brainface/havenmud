#include <lib.h>
#include "parva.h"
inherit LIB_BARKEEP;

static void create() {
   barkeep::create();
   SetProperty("parvanoleave",1);
   SetKeyName("Poisa");
   SetShort("Poisa, the storekeeper");
   SetTown("Parva");
   SetId( ({ "poisa","storekeeper" }) );
   SetAdjectives( ({ "the","poisa","storekeeper" }) );
   SetLong("Poisa is a human female of medium hieght with "
           "shoulder-length brown hair that is pulled back "
           "in a pony-tail.  She carefully prevents any "
           "and all strands from coming loose, so none can "
           "fall into her sea creatures.  She looks strong "
           "and determined.");
   SetGender("female");
   SetRace("human");
   SetClass("rogue");
   SetLevel(20);
   SetSkill("bargaining",20,1);
   SetLocalCurrency("oros");
   SetMenuItems( ([
                    "salmon" : P_OBJ + "/ksalmon",
                    "mackerel" : P_OBJ + "/mackerel",
                    "crab" : P_OBJ + "/kcrab",
                    "tuna" : P_OBJ + "/tuna",
                    "prawn" : P_OBJ + "/prawn",
                    "squid" : P_OBJ + "/squid",
                    "oyster" : P_OBJ + "/oyster",
                    "clam" : P_OBJ + "/clam",
                    "anchovy" : P_OBJ + "/anchovy"
               ]) );
   SetMorality(250);
   SetInventory( ([
                    P_OBJ + "/dress_fst" : "wear dress",
                    P_OBJ + "/belt_fst" : "wear belt",
                    P_OBJ + "/hat_fst" : "wear hat",
               ]) );
  SetAction(5, ({ "!speak in Enlan Step right up!",
                   "!say Come get some of our fresh fish, "
                   "we catch it new each day!","!speak "
                   "in Enlan Smell this fish!  Ain't it "
                   "just a sweet sea yummy smell?  Shows "
                   "your how totally fresh and good it is!",
                   "!speak in Enlan Oysters are good just "
                   "plain raw!  You just pick 'em up and "
                   "slide 'em down.","!speak in enlan "
                   "My mackerel is the most succulent "
                   "around.","!speak in enlan Ever tried "
                   "smoked king salmon?  Mmm mmmm good, "
                   "I tell ya!","!speak in enlan Just "
                   "think of the succulent cooking you "
                   "could get out of all this fresh "
                   "seafood!  Now it's all gotta be "
                   "sold today or I have to deal with "
                   "salting and smoking and all that "
                   "so I can eat it when the fresh "
                   "stuff comes slow.","!speak in enlan "
                   "!Com'on up here!  We have the best "
                   "seafood in all Kailie!","!speak in "
                   "enlan Now if you all will just please "
                   "spread the word about my nice store, "
                   "I'd appreciate it greatly.  Just "
                   "buy some to taste.  I know you'll "
                   "absolutely fall in love with this food!" }) );
   SetCombatAction(10, ({ "!yell Help!","!yell Help me!  Help!",
                          "!yell Someone come and help me, please!",
                          "!speak Stop this!  Get away from me!",
                          "!speak I'm a respectable business "
                          "owner, get away from me!","!speak Help!",
                          "!speak I haven't broken the law, what "
                          "are you trying to do to me!",
                          "!speak Help!  Help!","!trip", }) );
}
