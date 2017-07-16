#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("large tail");
   SetShort("a large curly pig tail");
   SetId( ({ "large curly pig tail","large tail","curly tail",
             "pig tail","tail","larg curly tail","large pig tail",
             "curly pig tail" }) );
   SetAdjectives( ({ "large","curly","pig" }) );
   SetLong("The pig tail curls and bongs attractively, much like " 
           "a baby's toy.");
   SetMass(2);
   SetValue(200);
   SetVendorType(VT_TREASURE);
}