//
// key to the obsidian door
// created by Ranquest@Haven
//
// 7-14-2004
// Added inherit LIB_KEY
// -Nauzo

#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_KEY;

static void create() {
    item::create();
    key::create();
    SetKeyName("key");
    SetKeyID("obsidian_key");
    SetId( ({"key","obsidian_key"}) );
    SetAdjectives( ({"obsidian","smooth","silky","shiny"}) );
    SetShort("an obsidian key");
    SetLong("This key has been carved from obsidian. Its surface is shiny"
      " and silky smooth. The figure of a crown has been etched lightly"
      " into the handle.");
    SetMass(5);
    SetValue(15);
    SetDestroyOnSell(1);
    SetDamagePoints(30);
    SetMaterial("natural");
    SetVendorType(VT_TREASURE);
    SetDisableChance(90);
}

/** Approved by Laoise at Wed Jul 14 23:29:57 2004. **/