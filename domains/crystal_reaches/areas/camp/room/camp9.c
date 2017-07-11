
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy camp");
     SetDomain("Crystal Reaches");
     SetDayLong("A light blue wagon sits by itself "
           "the far corner of the camp.  The ground "
           "around the wagon is very neat.  Even the "
           "logs of the cook fire are neatly laid out.  "
           "An old rocking chair is outside the "
           "wagon. ");
    SetNightLong("The flickering light reveals a "
           "single light blue wagon.  The cook fire and "
           "ground around the wagon are very neat, as if "
           "keeping the area clean was all someone had "
           "to do each day.  An old rocking chair is "
           "outside the wagon.");
    SetItems( ([
             ({"camp", "corner"}) : (: GetLong :),
             ({ "patch", "ground"}) :
                   "The dark gray ground is dry, firm and "
                   "impeccably clean. ",
             ({ "swamp", "swampy land", "land", "mud"}):
                 "The swamp is mainly gray water thick "
                 "with mud.  Some areas are fairly solid "
                 "allowing for relatively safe travel.  Many "
                 "trees thrive in the moisture of the swamp."
                 "  Even on the clearest of days the swamp "
                 "seems to be overcast.  ",
         ({"wagon"}):
                "The wagon is painted a light blue with "
                "pale green trim.  The window has dainty "
                "blue drapes.  A blue door at the "
                "back provides the only "
                "means for entrance.  A shelf-like bench at "
                "front provides a place for the driver to sit. ",
        ({"trim"}) : "The pale green trim is freshly "
               "painted. ",
        ({"drapes", "drape"}) :
              "The dainty blue drapes are hung "
              "perfectly.  ",
        ({"door"}) : "The blue door is carefully propped "
              "open. ",
        ({"bench"}) : "The bench looks like it has been "
              "recently replaced. ",
        ("firelight") : "The firelight flickers like fireflies "
               "dancing in the wind.  ",
        ("chair") : "The old, worn rocking chair is made "
               "of pine. ",
        ({"logs", "fire", "log"}) :
               "The logs of the small, warm "
              "cook fire are stacked neatly. "
             ]) );
    SetItemAdjectives( ([
                    "camp" : ({"gypsy"}),
                    "patch" : ({"large", "dry"}),
                    "wagon" : ({"blue", "light", "light blue"}),
                    "corner" : ({"far"}),
                    "fire" : ({"cook", "small"}),
                    "chair" : ({"rocking"}),
                     "drapes" : ({"dainty", "blue"}),
                    "trim" : ({"pale", "green"}),
                    "door" : ({"blue"}),
                    "bench" : ({"shelf-like"})               
                    ]) );
    SetSmell( ([
                "default" : "Various cooking fires fill the "
                                  "air with tantalizing scents."
              ]) );
    SetListen( ([
                "default" :  "The bustle of chores and work "
                                   "is not as noticable."
             ]) );
    SetClimate("temperate");
    SetInventory( ([ C_OBJ + "fire1" : 1,
                               C_NPC + "old_man" : 1]) );
    SetExits( ([
                       "east" : C_ROOM + "camp8",
                       "south" : C_ROOM + "camp6",
                       "southeast" : C_ROOM + "camp5"
                  ]) );
    SetEnters( ([
             "wagon" : C_ROOM + "wagon17",
                   ]) );
}
