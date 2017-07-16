//
// a small ticket
// Created by Athalie
//
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
   SetKeyName("small ticket");
   SetId( ({ "ticket" }) );
   SetAdjectives( ({ "small" }) );
   SetShort("a small ticket");
   SetLong("This is a small paper ticket that can be used only in the bazaar. "
     "It is a pale green color, with some black writing that you might be "
     "able to read.");
   SetRead("It reads: ADMIT ONE");
   SetMass(3);
   SetValue(5);
}
