#include <lib.h>
inherit LIB_ITEM;
#include <vendor_types.h>
 
static void create() {
   item::create();
   SetKeyName("tuft of fur");
   SetId( ({ "small tuft of fur","fur","tuft of fur","tuft","small tuft" }) );
   SetShort("a small tuft of fur");
   SetLong("A small tuft of fur from a cat.");
   SetMass(1);
   SetValue(24);
   SetVendorType(VT_FUR);
   SetMaterial("fur");
}