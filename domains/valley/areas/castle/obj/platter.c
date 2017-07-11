#include <lib.h>
#include <vendor_types.h>
inherit LIB_STORAGE;
#include "castle.h"

static void create() {
   storage::create();
   SetKeyName("metal platter");
   SetShort("a metal platter");
   SetId( ({ "platter","metal" }) );
   SetAdjectives( ({ "metal" }) );
   SetLong("The metal platter has slightly curved edges to prevent "
           "things from falling off.");
   SetMass(4);
   SetValue(3);
   SetVendorType(VT_TREASURE);
   SetCanClose(0);
   SetMaxCarry(90);
   SetMaterial( ({ "metal" }) );
   SetDamagePoints(50);
}
