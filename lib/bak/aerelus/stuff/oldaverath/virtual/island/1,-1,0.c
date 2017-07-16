#include <lib.h>
#include <domains.h>
inherit AVERATH_LIB;

varargs static void create(int x, int y) {
  ::create(1,-1);
  SetTown("Averath");
  SetShort("a small residential area");
  SetLong("Just east of the Duke's Road, this small area holds a tidy "
     "looking house on the northeast corner of the paved path. Small trees "
     "provide a tiny bit of shade in the front yard, and beautiful blooming "
     "flowers line the walkway to the door. Off to the west, the spires "
     "of the Kylin Church can be seen. There is a sewer grate here.");
  SetListen( ([
     "default" : "Birds chirp happily around you.",
     ]) );
  SetSmell( ([
     "default" : "The light fragrance of flowers stir in the breeze.",
     ]) );
  SetItems( ([
     ({ "grate", "sewer" }) : "The sewer grate leads down into the sewers.",
     ({"house"}) : "Medium sized, this white-washed house is quite tidy "
       "and well kept. Small windows on the front of the house give a "
       "little glimpse of the inside, through delicate curtains.",
     ({"path"}) : "This stone paved path leads in from River Road to the "
       "west.",
     ({"door"}) : "The door seems to be propped open always to let the "
       "air in.",
     ({"tree","trees"}) : "Small and leafy these few trees are scattered "
       "about in front of the house, providing a small amount of shade.",
     ({"yard","flowers"}) : "Beautiful mutli-colored flowers line the "
       "small walkway up to the door of the house, the whole yard is "
       "very well maintained.",
     ]) );
  SetItemAdjectives( ([
     "path" : ({"paved","stone"}),
     "house" : ({"tidy","white-washed"}),
     "tree" : ({"small","leafy"}),
    "grate" : ({ "sewer" }),
     ]) );
  SetEnters( ([
     "house" : AVERATH_CITY "house3",
     "grate" : AVERATH_UNDERGROUND "1,-1,-1",
     ]) );
}
