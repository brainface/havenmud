#include <lib.h>
inherit LIB_ITEM;
#include <vendor_types.h>
 
static void create() {
   item::create();
   SetKeyName("tuft of fur");
   SetId( ({ "large tuft of fur","fur","tuft of fur","tuft","large tuft" }) );
   SetShort("a large tuft of fur");
   SetLong("A large tuft of fur from a cat.");
   SetMass(2);
   SetValue(125);
   SetVendorType(VT_FUR);
   SetMaterial("fur");
}