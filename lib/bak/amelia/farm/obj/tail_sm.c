#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("small tail");
   SetShort("a small curly pig tail");
   SetId( ({ "small curly pig tail","small tail","curly tail",
             "pig tail","tail","small curly tail","small pig tail",
             "curly pig tail" }) );
   SetAdjectives( ({ "small","curly","pig" }) );
   SetLong("The pig tail curls and bongs attractively, much like " 
           "a baby's toy.");
   SetMass(1);
   SetValue(90);
   SetVendorType(VT_TREASURE);
}