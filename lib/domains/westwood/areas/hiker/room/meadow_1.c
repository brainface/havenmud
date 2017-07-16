#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("near some blueberry bushes");
   
   SetLong("The ground is dry and firm, with blueberry bushes growing "
           "everywhere on it.  They meld into the West Wood to the north "
           "and west, and to the east and south, a beautiful meadow "
           "exists.  There also seems to be some sort of trail to the "
           "east somewhere.  Here, however, the main feature is the "
           "bushes loaded down with delicious blueberries.");
   SetItems( ([
                ({ "west wood","wood","woods","tree","trees" }) :
                   "The West Wood stands tall with its trees to the "
                   "north and west, blueberry bushes in front.",
                ({ "narrow trail","trail" }) :
                   "The the east, there seems to be a trail that heads "
                   "in a north-south sort of direction.",
                ({ "beautiful meadow","meadow" }) :
                   "A meadow picks up to the east and south, growing "
                   "all sorts of beauty to admire and revel in.",
                ({ "dry ground","firm ground","ground" }) :
                   "The ground is hard and firm, and occasionally dotted "
                   "with blue stains from the blueberries falling.",
                ({ "blueberry bushes","blueberry bush","bush","bushes" }) :
                   "The bushes are thick and everywhere, almost like "
                   "a wall to the north and south.  They continue growing "
                   "off to the south, too, but less profusely.  It "
                   "seems like there is a little hole leading through the "
                   "bushes, however.",
                ({ "little hole","hole" }) :
                   "There is a hole leading through the blueberry bushes "
                   "to the west.  It could probably be entered by "
                   "someone.",
                ({ "delicious blueberries","delicious blueberry",
                   "blueberries","blue berries","blue berry","blueberry",
                   "delicious berries","delicious berry","berries","berry",
                   "delicious blue berry","delicious blue berries" }) :
                   "The berries are huge and very blue and very, very "
                   "tasty.  They cover the blueberry bushes.",
                ({ "blue stains","stains","stain" }) :
                   "The ground has some blueberry stains on it.  "
                   "Some blueberries must have been squashed, leaving "
                   "blue all over the ground.",
           ]) );
   SetItemAdjectives( ([
                         "stain" : ({ "blue","blueberry","berry" }),
                         "blueberry" : ({ "tasty","huge","blue" }),
                    ]) );
   SetListen( ([
                 "default" : "Rustling noises come form the west.",
            ]) );
   SetExits( ([
                "east"  : H_ROOM + "trail_09",
                "south" : H_ROOM + "meadow_2",
           ]) );
   SetEnters( ([
                 "hole" : H_ROOM + "stagroom",
            ]) );
   SetInventory( ([
                    H_NPC + "picker" : 2,
                    H_NPC + "pickboy" : 1,
                    H_NPC + "pickgirl" : random(2),
                    H_OBJ + "blueberries" : random(3),
                    H_OBJ + "blueleaf" : 3 + random(8),
               ]) );
}
