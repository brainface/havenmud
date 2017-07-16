#include <lib.h>
#include <vendor_types.h>
#include "../ice.h" 
inherit LIB_POLE;

static void create() {
   pole::create();
   SetKeyName("pole");
   SetShort("a good fishing pole");
   SetStrength(200);
   SetId( ({ "pole" }) );
   SetAdjectives( ({ "good","fishing" }) );
   SetLong(
	"This fishing pole is a distinct improvement upon "
	"bare hands and simple fishing poles.  It is a little "
	"more sturdy and could deffinitely attract some fish."
	);
   SetClass(2);
   SetValue(40);
   SetMass(25);
   SetVendorType(VT_FISHING);
   SetChance(25);
   SetDamagePoints(50);
   SetMaterial( ({ "wood" }) );
}

/** Approved by Laoise at Fri Jul  9 20:22:32 2004. **/
