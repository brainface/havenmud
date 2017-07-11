// Amelia@Haven

#include <lib.h>
inherit LIB_FISHING;
#include "../soleil.h"

static void create() {
   fishing::create();
   SetTown("Soleil");
   SetShort("a small pool");
   
   SetLong("Beneath all the great trees that hold up Soleil above, there "
           "is a clear pool that serves as Soleil's water supply.  From "
           "other little clues, one can assume that the muezzins fish "
           "here, as well.  Around the pool to the north a bit is a ladder "
           "heading up into the trees.  A broad path heads to the "
           "west, while a smaller, less used trail heads to the "
           "north.  The inn and tavern of Soleil has an entrance "
           "here; it is off to the east side of the pool.");
   SetItems( ([
                ({ "great trees","great tree","tree","trees" }) :
                   "The trees are large around here, larger than "
                   "they normally are on Kailie.  Down here, the "
                   "underside of trees is more prevailent:  the roots "
                   "and moss.",
                ({ "roots and moss","moss","root" }) :
                   "Roots from the trees cover the paths, and moss covers "
                   "those roots.",
/*
                ({ "clear pool","pool","water supply","water","river" }) :
                   "The water sparkles in the light with a nice clear "
                   "color that speaks of how clean it is.  A river "
                   "feeds it coming from the northwest, but it must "
                   "drain underground.",
*/
                ({ "north ladder","ladder" }) :
                   "The ladder is strong, but it speaks of age.  It "
                   "doesn't have the same timeless look as some of the "
                   "other structures in Soleil did.  It seems to be "
                   "getting old.  It leads up.",
                ({ "broad path","path","trail" }) :
                   "The path to the west has been tread by many, " 
                   "it is firm and cleared of obstructions.",
                ({ "small trail","less used trail","trail","path" }) :
                   "Small tufts of grass grow on this small, unused "
                   "trail.  It heads off to the north.",
                ({ "soleil inn","soleil tavern","inn","tavern" }) :
                   "The inn is a basic, wooden structure, made sturdy "
                   "so that it will stand up.  It can be entered "
			"from here.",
           ]) );
   SetExits( ([
                "up" : S_ROOM + "tree_b",
                "west" : S_ROOM + "barracks",
                "north" : S_ROOM + "cemetery",
           ]) );
   SetEnters( ([
                 "inn" : S_ROOM + "inn",
            ]) );
   SetInventory( ([
                    S_OBJ + "pool" : 1,
                    S_NPC + "citizenf" : 1,
                    S_NPC + "ranger_foret" : 1,
                    S_NPC + "trainer_nascima" : 1,
               ]) );
   SetSpeed(3);
   SetFish( ([ 
               S_OBJ + "fish_a" : 110,
               S_OBJ + "fish_b" : 50,
          ]) );
   SetChance(45);
   SetMaxFishing(25);
}
