// Kilik
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("inside a well lit forest");
   SetLong("The floor of the forest is covered with soft, fertile, dirt. "
           "Animal tracks of all sizes lead in every direction. "
           "The trees are well spaced but dense enough not to be able to "
           "see too far.  The sky above is blotted out by leaves and branches. "
           "There is a tall stone tower to the west. The beach is not far to "
           "the west.  There is a small hut to the south. The forest thins out "
           "to the north.");
   SetItems( ([
                ({ "tall stone tower","tower", }) :
                   "A rather tall stone tower can be seen off to the west.",
                ({ "floor","well-lit forest","forest" }) : (: GetLong:),
                ({ "leaves","branches","leaf","branch" }) :
                   "The canopy above is spotted with bright green leaves and "
                   "thick strong branches that block out most of the sky.",
                ({ "beach" }) :
                   "The beach is off to the east down a slight slope.",
                ({ "hut","small hut" }) :
                   "A short hut stands to the south.",
                ({ "tracks","animal tracks","animal trail" }) :
                   "Animal tracks of every size and shape lead off in all "
                   "directions. This seems to be part of an animal trail.",
                ({ "dirt","ground" }) :
                   "The ground is rich dark soil, and covered with animal tracks.",
                ({ "tree","trees" }) :
                   "Tall trees surround the forest with darkness.",
           ]) );
   SetItemAdjectives( ([
              "tower" : ({ "tall","stone" }),
              "leaves" : ({ "green" }),
              "branches" : ({ "thick","strong" }),
              "beach" : ({ "sandy" }),
              "dirt" : ({ "rich","fertile" }),
                    ]) );
   SetListen( ([
              "default" : "The wind rustles the leaves and plants.",
           ]) );
   SetSmell( ([
             "default" : "Herbs and fertile soil enrich the air.",
             "soil" : "The soil has the aroma of long dead plants "
             "and animals.",
           ]) );
   SetExits( ([
             "west" : AVERATH_ISLAND + "8,-3,0",
             "east" : AVERATH_ISLAND + "10,-3,0",
             "south" : AVERATH_ISLAND + "9,-4,0",
             "north" : AVERATH_ISLAND + "9,-2,0",
           ]) );
   SetInventory( ([
             FOREST_NPC + "elk" : 1,
             FOREST_NPC + "seagull" : 2,
               ]) );
}
