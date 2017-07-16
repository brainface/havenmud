#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("angel wand");
   SetShort("an angelic wand");
   SetId( ({ "angel","wand" }) );
   SetAdjectives( ({ "angelic","angel" }) );
   SetLong("Even though it is shaped like a beautiful angel, this "
           "wand appears cheap and worthless.  It seems like it "
           "could break any second, making one reminiscent of most "
           "of Haven's angels.");
   SetMass(1);
   SetValue(0);
   SetVendorType(VT_TREASURE);
   SetMaterial("glass");
}
