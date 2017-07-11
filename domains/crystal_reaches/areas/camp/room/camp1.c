	
#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetShort("a gypsy camp");
     SetDomain("Crystal Reaches");
     SetDayLong("Like a rainbow breaking through "
           "storm clouds, the gypsy camp pierces the "
           "stark grayness of the swamp.  Very "
           "few of the wagons are painted the same color."
           "  A red wagon and an "
           "orange wagon stand out from the bleak "
           "swamp.  A small fire for cooking burns "
           "warmly.  A few empty chairs are set up "
           "around the fire.  ");
    SetNightLong("The light from the fire flickers "
           "causing the camp to appear as if it "
           "were a pile of sparkling gems held up to a "
           "light.  The firelight bounces off a red"
           " wagon and an orange wagon.  "
           "A few empty chairs are set up around the "
           "fire.");
    SetItems( ([
             ("camp") : (: GetLong :),
             ({ "patch", "ground"}) :
                   "The dark gray ground is dry and firm. ",
             ({ "swamp", "swampy land", "water", "land", 
                    "mud"}):
                 "The swamp is mainly gray water thick "
                 "with mud.  Some areas are fairly solid "
                 "allowing for relatively safe travel.  Many "
                 "trees thrive in the moisture of the swamp."
                 "  Even on the clearest of days the swamp "
                 "seems to be overcast.  ",
         ({ "red wagon", "wagon"}):
                "The wagon is painted a bold red with "
                "pale pink trim.  The window has small "
                "shutters also in pink.  A pink door at the "
                "back provides the only "
                "means for entrance.  A shelf-like bench at "
                "front provides a place for the driver to sit. ",
        ({"pale pink trim", "pink trim", "trim"}): "The "
                "pale pink trim runs along the edges of "
                "the wagon.  ",
        ({"window"}): "The window allows people to "
               "look out of the wagon. ",
        ({"shutters", "shutter"}) : 
            "The pink shutters are open.", 
        ({"door"}) : "The door is "
            "propped open.",
        ({"bench"}) : "The bench is where the driver "
           "sits. ",
        ({"chairs", "chair"}) : "The chairs are very "
                "simple in design yet comfortable.   Years "
                "of exposure to the elements have worn the "
                "chairs.  ",
         ({"orange wagon", "wagon"}) : "The dull "
               "orange wagon has bright orange edging.  "
               "The window is unadorned.   There is a door"
               " at the back.  The bench for the driver is "
               "worn.",
         ({"bright orange edging", "orange edging",
              "edging"}):  "The bright orange edging "
              "goes around the edges of the wagon. ",
         ({"fire", "campfire"}): "The fire is small and "
             "warm.",
        ("firelight") : "The firelight flickers like fireflies "
               "dancing in the wind.  "
             ]) );
    SetItemAdjectives( ([
                    "camp" : ({"gypsy"}),
                    "swamp" : ({"stark", "gray"}),
                    "patch" : ({"large", "dry"}),
                    "fire" : ({"small", "warm"}),
                    "chairs" : ({"empty"}),
                    "shutters" : ({"pink"}),
                    "water" : ({"gray"}),
                    "mud" : ({"thick", "gray", "shiny"}),
                    "bench" : ({"shelf-like", "warn"}),
                    "window" : ({"unadorned"}),
                    "door" : ({"pink"})
                    ]) );
    SetSmell( ([
                "default" : "Various cooking fires fill the "
                                  "air with tantalizing scents."
              ]) );
    SetListen( ([
                "default" :  "The bustle of chores and work"
                                   " blends with the sounds of a "
                                   "tambourine and singing."
             ]) );
    SetClimate("temperate");
    SetInventory( ([ C_OBJ + "fire1" : 1,
                            C_NPC + "dog1" : 1]) );
    SetExits( ([
                       "west" : C_ROOM + "camp2",
                       "north" : C_ROOM + "camp4",
                       "northwest" : C_ROOM + "camp5"
                  ]) );
    SetEnters( ([
             "red wagon" : C_ROOM + "wagon1",
             "orange wagon" : C_ROOM + "wagon2",
                              ]) );
}
