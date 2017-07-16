#include <lib.h>
inherit LIB_ROOM;
#include "sdm.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(25);
   SetShort("hay loft");
   SetLong("Lots and lots of dry hay is filling the hay loft, and "
           "the ceiling overhead cuts out most of the light.  There "
           "is an open hole in the east wall that over looks some "
           "open country.  A ladder heads down to the floor of the "
           "barn.  A small nest-like hole in the hay has been formed "
           "in the northeast corner of the hay loft.");
   SetItems( ([
                ({ "ceiling overhead","ceiling" }) :
                   "The ceiling blocks the sky, but one can still look "
                   "out at the world through the opening in the "
                   "east wall.",
                ({ "east wall","wall" }) :
                   "The east wall has a large rectangular opening in it.",
                ({ "floor of the barn","floor","barn","hay loft floor",
                   "sky","world","light","ruined sea","sea","barn floor"
                   "shipwrecked men","shipwrecked sailors",
                   "shipwrecked sailor","sailor","men" }) :
                   "Try as one might, it is impossible to see from this "
                   "angle.",
                ({ "worn wooden ladder","wooden ladder","worn ladder" }):
                   "The ladder is propped up against the hay loft, "
                   "leading down to the barn floor.  It is slowly "
                   "wearing out, and doesn't seem safe for the larger "
                   "of beings to try to use.",
                ({ "small nest like hole","small nest-like hole",
                   "small hole","hole","nest-like hole","nest like hole",
                   "northeast corner","corner" }) :
                   "The hay in this little hole has been carefully "
                   "arranged to be more comfortably than in the rest of "
                   "hay loft, but has also been affected so that it is "
                   "more hidden.  Some stray cat hair is loose is the "
                   "nest.",
                ({ "stray cat hair","stray hair","cat hair","hair" }) :
                   "The cat hairs loose in the small, nest-like hole "
                   "are small.",
                ({ "hay loft","loft" }) : (: GetLong :),
                ({ "dry hay","hay","heaps","heap","pile","piles" }) :
                   "The hay is piled in heaps in the hay loft, "
                   "the stuff sinking it as anything touches it.  "
                   "a little hole much like that of a nest is in the "
                   "northeast of all this hay.",
                ({ "large rectangular opening","large opening",
                   "open hole","hole","east hole","opening"
                   "rectangular opening","east opening" }) :
                   "The hole is a large rectangular opening in the "
                   "east wall.  It looks out onto some open country "
                   "of tall grass.  It's a long ways down from here, "
                   "it might be a good idea to keep from falling out.",
                ({ "open country","country","out" }) :
                   "Out the open hole in the east wall and towards the "
                   "world, it is possible to see some open country "
                   "that is not full of trees, but rather of tall "
                   "grasses and dainty--yet hardy--wildflowers.",
                ({ "tall grasses","tall grass","grass","grasses" }) :
                   "The grasses bend and sway in the wind, hiding "
                   "some of the smaller flowers in it's thickness.",
                ({ "dainty yet hardy wildflowers","dainty wildflowers",
                   "dainty wildflower","dainy flower","dainty flower",
                   "hardy flower","hardy flowers","flower","flowers",
                   "wildflowers","wildflower" }) :
                   "Out of the opening in the west wall, wildflowers "
                   "decorate the open country.  Yellows and blues are "
                   "among the most frequent of colors.  The smaller "
                   "ones bareley peek out of the grass.  They look "
                   "like a shipwrecked man floating in the middle "
                   "of the Ruined Sea:  without hope of ever making "
                   "it out alive.",
                ({ "smaller flowers","smaller flower","small flowers",
                   "small flower","smaller wildflowers","wildflowers",
                   "smaller wildflower","wildflower","flower","flowers",
                   "small wildflower","small wildflowers" }) :
                   "Hidden by the tall grasses out in the open country "
                   "seen through the rectangular opening are small "
                   "wildflowers, smaller than most all of the rest, "
                   "peeking out of the grass and trying to stay out "
                   "in the light.  They seem much like shipwrecked "
                   "sailors in the Ruined Sea, struggling to stay above "
                   "the water or grasses.",
                ({ "blue and yellow wildflowers","blues","yellows",
                   "blue","yellow","blue wildflower","blue wildflowers",
                   "yellow wildflowers","yellow wildflower","yellow flower",
                   "yellow flowers","blue flowers","blue flower",
                   "wildflower","wildflowers","flower","flowers" }) :
                   "Thse are the most prominent of all the colors of "
                   "flowers out in the open country that is visible through "
                   "the rectangular opening.",
           ]) );
   SetExits( ([
                "down" : SDM_ROOM + "/barn",
           ]) );
   SetObviousExits("down");
   SetInventory( ([
                    SDM_NPC + "/kitten" : 6,
                    SDM_NPC + "/cat" : 1,
               ]) );
}