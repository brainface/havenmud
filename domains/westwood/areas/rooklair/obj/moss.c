#include <lib.h>
#include "../rook.h"

inherit LIB_ITEM;
 
static void create() {
   item::create();
   SetKeyName("moss");
   SetId( ({ "moss" }) );
   SetShort("a small piece of moss");
   SetRadiantLight(15);
   SetLong("This is a small piece of moss that seems to contain "
     "a small amount of phosphorous.  It glows slightly.");
   SetMass(1);
   SetValue(0);
   SetMaterial("natural");
}
