#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_LISTEN;
#include "../hiker.h"
 
static void create() {
   meal::create();
   SetInvis(1);
   SetKeyName("pure water");
   SetId( ({ "water","stream","river" }) );
   SetAdjectives( ({ "fast","wide","shallow","pure","clean","clear",
                     "rushing" }) );
   SetShort("a pure stream");
   SetMealType(MEAL_DRINK);
   SetLong("The stream is wide and shallow here, as opposed to being "
           "skinny and deep.  It goes about six or seven feet from "
           "bank to bank, the water brushing noisily up against the "
           "edges and eroding them further.  A log dips into the water, "
           "balance carefully against the bridge which seems too "
           "far up to make it onto directly from the water.");
   SetPreventGet("You cannot take a stream!");
   SetEmptyItem(H_ROOM + "water");
   SetStrength(25);
   SetMealMessages("You drink from the stream.  The water tastes "
                   "fresh and clean.",
                   "$N drinks from the stream.");
   SetSmell("The water pushes all scents and odors around here "
            "downstream, giving the area a scentless smell.");
   SetPortions(-1);
   SetListen("As streams tend to do, this one makes lots of noise "
             "as it heads downstreams.");
} 


mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}

string GetListen(string str) {
   return listen::GetListen(str);
}
