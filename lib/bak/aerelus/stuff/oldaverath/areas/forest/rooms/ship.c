// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetClimate("indoors");
   SetAmbientLight(25);
   SetShort("inside a shipwreck");
   SetLong("A jagged hole opens to the beach outside the shipwreck, "
           "large enough for tall, obese human to stroll through "
           "without ducking or scraping the sides.  Broken, rotting "
           "crates fill the hold of the ship, displaying once-fine "
           "cloth disintegrating into shreds.  A stairway leads "
           "to a hatch in the ceiling.");
   SetItems( ([
                ({ "jagged hole","hole","beach" }) :
                   "The beach is visible outside the rough hole in "
                   "the side of the ship, which guarentees that "
                   "this vessel is never sailing again.",
                ({ "shipwreck","wreck","ship","boat","hold" }) :
                   (: GetLong() :),
                ({ "broken rotting crates","crates","crate" }) :
                   "Stained with years of tides, the crates "
                   "slowly rot in the hold of the shipwreck.  "
                   "Most contain shreds of cloth.",
                ({ "shreds of once-fine cloth","cloth","shreds",
                   "shred" }) :
                   "Bright colors have faded into dingy pastels "
                   "on the shreds of cloth.  Damp with water "
                   "and splattered with sand, the aging cloth "
                   "has no value.",
                ({ "stairway", }) :
                   "Most of the stairway has fallen apart, and the remainder is "
                   "unstable and rotting.",
                ({ "hatch","ceiling","hinges","hinge" }) :
                   "The metal hinges on the hatch have rusted shut.",
           ]) );
   SetItemAdjectives( ([
                         "crates" : ({ "broken","rotting" }),
                         "hole" : ({ "jagged" }),
                         "cloth" : ({ "once-fine","shreds of","aging" }),
                         "hinge" : ({ "metal" }),
                    ]) );
   SetSmell( ([
                "default" : "The salty scent of the ocean is prevalent here.",
           ]) );
   SetListen( ([
                 "default" : "Waves crash against the hull of the ship.",
            ]) );
   SetInventory( ([
                    FOREST_NPC + "oldrobber" : 1,
                    FOREST_NPC + "youngrobber" : 1,
                    FOREST_NPC + "sailorghost" : 3,
               ]) );
   SetExits( ([
                "out" : AVERATH_ISLAND + "9,-6,0",
           ]) );
   SetSearch( ([
                 "crates" : "You discover a few barnacles on the crates, but "
                            "nothing of interest.",
                 "cloth" : "Some of the cloth disintegrates as you touch it.",
            ]) );
}
