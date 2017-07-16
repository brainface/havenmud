#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include "../rook.h"

inherit LIB_STORAGE;

static void create()
{
::create();
SetKeyName("scroll case");
SetId( ({ "scroll case","tube","case" }) );
SetAdjectives( ({ "scroll","tubular" }) );
SetShort("%^WHITE%^an ivory scroll case%^RESET%^");
SetLong("This is an ivory scroll case.  It is engraved with symbols "
  "of dragons coiled about it and end caps that are made of the "
  "purest mithril.");
SetMass(20);
SetValue(1500);
SetCanClose(1);
SetClosed(1);
SetMaxCarry(1);
SetMaterial( ({ "natural","mithril" }) );
SetRepairSkills( ([ "natural working" : 1 ]) );
SetRepairDifficulty(2);
SetVendorType(VT_TREASURE);
SetInventory( ([
  R_OBJ + "scroll" : 1,
]) );
}
