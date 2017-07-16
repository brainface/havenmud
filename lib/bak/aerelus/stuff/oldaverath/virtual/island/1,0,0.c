#include <lib.h>
#include <domains.h>
inherit AVERATH_LIB;

varargs static void create(int x, int y) {
  ::create(1,0);
  SetTown("Averath");
  SetShort("river Road");
  SetLong("This is the eastern part of Averath, and one of the busiest "
     "sections of town as it houses two of the largest buildings. The "
     "building on the north side appears to be the town's bank, while the "
     "one to the south is most likely the Post Office. The paved road leads "
     "back west to the Crossroads, and east out of town.");
  SetListen( ([
     "default" : "The sounds of commerce hum quietly in the air.",
     ]) );
  SetSmell( ([
     "default" : "The hearty smells of fresh baked food waft in from west.",
     ]) );
  SetItems( ([
     "road" : "River Road is paved with large stones, and continues to "
       "the west back to the center of town and east out of town.",
     ({"stone","stones"}) : "These large stones have been worn smooth over "
       "the years from the trampling of citizens and travellers alike.",
     ({"building","bank"}) : "This stone building takes up much of this "
       "side of the road. It looks like a fairly secure building, with "
       "men in guard uniforms on either side of the entrance. It is "
       "beautifully maintained with neatly trimmed bushes lining the front.",
     ({"building","post office"}) : "Meticulously well kept, this very "
       "official looking building has the words 'Averath Post Office' "
       "carved into the stone above the front doors.",
     ]) );
  SetItemAdjectives( ([
     "stone" : ({"large","smooth"}),
     ]) );
  SetEnters( ([
               "bank" : AVERATH_CITY + "bank",
               "post office" : AVERATH_CITY + "post",
     ]) );
   SetInventory( ([
                    AVERATH_NPC + "equipper" : 1,
               ]) );
}
