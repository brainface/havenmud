#include <lib.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("trash");
   SetShort("a piece of trash");
   SetId( ({ "trash" }) );
   SetAdjectives( ({ "piece of" }) );
   SetLong("This little piece of trash came from the bottum of "
           "the ocean.  Little bits of green and brown slimy "
           "stuff clings onto it and it has decomposed into an "
           "unrecognizable thing.");
   SetMass(70);
   SetValue(0);
   SetMaterial( ({ "natural" }) );
   SetProperty("history","This object was tossed overboard or "
               "dropped while on the docks on in a boat near "
               "Parva.");
}
