#include <lib.h>
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("the dark void");
   SetLong("Night fills the air as a cold, chilling wind gusts through "
           "this dark void.  Thin lines of energy can be faintly "
           "picked out, streaming towards this central location.  A "
           "barely visable path of energy flees upward, carrying with "
           "it the suggestion that one might be able to get out of this "
           "hell-hole by fleeing that way, too.");
   SetItems( ([
                ({ "dark void","void","darkness","night","air",
                   "hell-hole","hell hole","hole","hell","area",
                   "central location","location","center",
                   "dream-shattering void" }) :
                   (: GetLong :),
                ({ "thin lines of energy","thin lines","lines",
                   "line","thin line","thin line of energy",
                   "lines of energy","line of energy","energy",
                   "thin energy lines","energy lines","energy line",
                   "thin energy line","little blue sparks","sparks",
                   "spark","little sparks","little spark","blue sparks",
                   "blue spark","little blue spark","lightning",
                   "suddenly illuminating forks of lightning",
                   "suddenly illuminating forks","illuminating forks",
                   "suddenly illuminating fork","illuminating fork",
                   "suddenly illuminating fork of lighting","fork",
                   "forks","dazzling electricity","electricity" }) :
                   "The appearance of the thin energy lines ranges "
                   "from little blue sparks to suddenly illuminating "
                   "forks of lightning, but all have generally the same "
                   "feeling of flow and continuity, and all flow here.",
                ({ "barely visible path of energy","barely visible path",
                   "path","energy","path of energy","stringy path",
                   "energy path" }) :
                   "The energy deviates from it's concentration on this "
                   "point in only one way:  This stringy path that "
                   "streams upward towards a faint pinprick of light.",
                ({ "faint pinprick of light","faint pinprick",
                   "pinprick of light","pinprick","light" }) :
                   "The energy path flows towards a pinprick of light "
                   "above this dark void.  The light seems to radiate "
                   "hope and joy and life and goodness, the exact "
                   "opposite of this dream-shattering void.", 
           ]) );
   SetSmell( ([
                "default" : "The darkness reeks of death.",
           ]) );
   SetListen( ([
                 "default" : "Despite the wind, it is dismally "
                    "silent.",
            ]) );
   SetTouch( ([
                "energy" : "The energy leaps into the air, shockingly "
                   "bright and eletric.  It might be possible to "
                   "enter the dazzling electricity, however.",
           ]) );
   SetObviousExits("up");
   SetExits( ([
                "up" : "/domains/heaven/room/olympus",
           ]) );
   SetEnters( ([
                 "energy" : "/domains/heaven/adm/void",
            ]) );
   SetInventory( ([
                    "/realms/amelia/school/angel_npc" : 1,
               ]) );
}
