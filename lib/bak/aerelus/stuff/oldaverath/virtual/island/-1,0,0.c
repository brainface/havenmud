#include <lib.h>
#include <domains.h>
inherit AVERATH_LIB;

varargs static void create(int x, int y) {
  ::create(-1,0);
  SetTown("Averath");
  SetShort("river Road");
  SetLong("Large stones pave River Road to the east and west, leading "
     "to the city center and out of town respectively. A large wooden "
     "building to the side of the road looks rather prominent. A sign "
     "hangs above its awning. The road is well travelled and seems to "
     "invite people from all over to stay awhile. Bustling of the activities "
     "at the crossroads can be seen to the east.");
  SetItems( ([
     "road" : "River Road is paved with large stones, and continues to "
       "the east and westward out of town.",
     ({"stone","stones"}) : "These large stones have been worn smooth over "
       "the years from the trampling of citizens and travellers alike.",
     "building" : "This large building seems to dominate this part of "
       "town, inviting travellers inside.",
     "sign" : "The sign reads, 'Registrar's Office' in bold white lettering.",
     ]) );
  SetItemAdjectives( ([
     "stone" : ({"large","smooth"}),
     "building" : ({"large","wooden","prominent"}),
     ]) );
  SetEnters( ([
               "building" : AVERATH_CITY + "cityreg",
          ]) );
  SetListen( ([
     "default" : "Sounds of city life permeate the air.",
     ]) );
  SetSmell( ([
     "default" : "The hearty smells of fresh baked food waft in from the east.",
     ]) );
}
