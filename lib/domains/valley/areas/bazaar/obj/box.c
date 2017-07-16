//
// A wooden jewelry box
// Created by Athalie
//
#include <lib.h>
#include "../bazaar.h"
#include <vendor_types.h>
inherit LIB_STORAGE;

static void create() {
  storage::create();
   SetKeyName("jewelry box");
   SetId( ({ "box" }) );
   SetAdjectives( ({ "jewelry", "wooden" }) );
   SetShort("a wooden jewelry box");
   SetLong("This decorative wooden box has several small glass beads "
     "glued along the edges of the top. A picture has been carved into "
     "the surface of the box, and there is an inscription along the "
     "front.");
   SetMass(10);
   SetRead("The inscription reads: friendship is forever");
   SetValue(50);
   SetCanClose(1);
   SetClosed(1);
   SetMaxCarry(150);
   SetVendorType(VT_TREASURE);
}
