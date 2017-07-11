#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("weighty tome");
   SetShort("an especially weighty tome");
   SetId( ({ "tome" }) );
   SetAdjectives( ({ "weighty","especially weighty" }) );
   SetLong("A number of diagrams and symbols are written across the "
           "cover of the tome.  It may be possible to read some of "
           "pages inside.");
   SetMass(30);
   SetVendorType(VT_TREASURE);
  SetMaterials( ({ "textile" }) );
   SetValue(5);
   SetRead("The writing in this tome is seemingly of a foreign tongue.");
}
