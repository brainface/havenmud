/* Knife for the Skaven
   Brotherhood of Shadows.
   - Melchezidek Oct 2009
*/

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

string ReadRead();

static void create() {
	::create();
	SetKeyName("dagger");
	SetShort("a crimson dagger");
	SetId("dagger");
	SetAdjectives("crimson");
	SetLong("This is a long and thick bladed dagger. The metal"
	        " was forged with a hint of iron and other elements"
	        " to create the appearance of a deep crimson metal."
	        " The silver handle is laced with black leather to"
	        " provide a sure and comfortable grip. Black runes"
	        " run the length of the medial ridge.");
	SetValue(500);
	SetClass(28);
	SetDamagePoints(1350);
	SetMaterials( ({ "metal" }) );
	SetRepairSkills( ([
	 "metal working" : 35,
	 "weapon smithing" : 35,
	 ]) );
	SetRepairDifficulty(35);
	SetVendorType(VT_WEAPON);
	SetWeaponType("knife");
	SetDamageType(PIERCE|SLASH|MAGIC);
	SetRead( (: ReadRead :) );
}

string ReadRead() {
	object who = this_player();
	if((who->GetLanguageLevel("Skavish") > 100) &&
	    who->GetLevel() > 75) {
	    	who->eventPrint("%^BLACK%^%^BOLD%^The Brotherhood of Shadows%^RESET%^");
	    	return;
	    }
	who->eventPrint("%^BLACK%^%^BOLD%^Umbra ab Fraternitas%^RESET%^");
	return;
}
