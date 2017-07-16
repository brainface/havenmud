// Wedding present for Luna :)

#include <lib.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
	::create();
	SetKeyName("gloves");
	SetShort("a pair of gleaming white gloves");
	SetId( ({ "gloves" }) );
	SetAdjectives( ({ "gleaming", "white", }) );
	SetLong(
	  "These six fingered gloves gleam with some kind of magical field. "
	  "On the inside of one of them, sewn in red, is a small message."
	  );
	SetValue(400);
	SetMass(2);
	SetMaterial( ({ "leather" }) );
	SetWarmth(5);
	SetItems( ([
	  "message" : "The message is sewn in red stitching.",
	   ]) );
	SetRead( ([
	  "message" : "The message reads 'For Luna, on your day of great happiness. From the Banewulfs of Haven.'",
	   ]) );
	SetArmourType(A_GLOVE);
	SetProperty("multiples", 1);
	SetArmourClass(ARMOUR_LEATHER);
	SetVendorType(VT_ARMOUR);
	SetSize(SIZE_MEDIUM);
	SetFingers(6);
}