#include <lib.h>
#include <domains.h>
inherit AVERATH_LIB;

varargs static void create(int x, int y) {
  ::create(-1,1);

  SetTown("Averath");
  SetShort("a residential area");
  SetLong("Tall trees provide an ample amount of shade for the small " 
     "house that rests on the northern part of the road. To the east the "
     "paved road heads back to the Duke's Road and into the heart of Averath. "
     "The small house is obviously old and a small wood fence surrounds "
     "a little garden at it's side. The Duke's private residence can be "
     "seen to the east, making the houses around here seem like little "
     "ant hills.");
  SetListen( ([
     "default" : "A nice breeze stirs the tree leaves.",
     ]) );
  SetSmell( ([
     "default" : "The air smells clean and crisp.",
     ]) );
  SetItems( ([
     ({"tree","trees"}) : "A few tall leafy trees provide just the right "
       "amount of shade for this area. They look like they've been here "
       "for many many years, and have small carvings from children on "
       "their trunks.",
     ({"house"}) : "This small house is old and color that was once on it "
       "is now faded and dim. You can tell that the owners try to keep "
       "it up but it's obviously more work than can be managed. A small "
       "dirt path leads up to the door, around to the tiny flower garden "
       "at the side.",
     ({"road"}) : "This stone paved road leads in from the Duke's Road "
       "to the east.",
     ({"fence"}) : "A small wooden fence that was probably white-washed "
       "at one time is now just as dull as the house, surrounds the "
       "tiny flower garden.",
     ({"flower","flowers","garden"}) : "A tiny garden of flowers rests "
       "to the side of the house, adding bright color to the somewhat "
       "dull house. A few weeds grow in with the flowers, as if the garden "
       "hasn't been tended for a while.",
     ]) );
  SetItemAdjectives( ([
     "house" : ({"small","dull","old"}),
     "road" : ({"stone","paved"}),
     "fence" : ({"wood","dull"}),
     "garden" : ({"tiny"}),
     "tree" : ({"tall","leafy","old"}),
     ]) );
  SetEnters( ([
     "house" : AVERATH_CITY "house2",
     ]) );
    SetDoor("house", AVERATH_OBJ + "door2");
}
