//
// An old journal
// Created by Zaxan@Haven
// 23rd of November, 1997
//

#include <lib.h>
#include <vendor_types.h>
#include "path.h"

inherit LIB_ITEM;

static void create() {
	item::create();
	SetKeyName("journal");
	SetId( ({ "journal" }) );
	SetAdjectives( ({ "old", "dusty" }) );
	SetShort("an old journal");
	SetLong("This old journal is the complete log of previous "
		"explorations through the mountains. It is covered with "
		"dust and cobwebs.");
	SetDestroyOnSell(1);
	SetMass(10);
	SetValue(0);
	SetVendorType(VT_TREASURE);
	SetRead("%^CYAN%^BOLD%^Quintaday, Fourthmonth, Year 14%^RESET%^\n\n"
		"We have started our journey through the Frost Marches. "
		"We're looking for the city of Keryth, where our sick "
		"father rests. All seems good. We are in pretty nice "
		"terrain and the storms aren't very bad.\n\n"
		"%^CYAN%^BOLD%^Primday, Fifthmonth, Year 14%^RESET%^\n\n"
		"Been working so hard, haven't had much time to write in "
		"the journal. We haven't found the city yet...to be honest, "
		"we're not quite sure where we are. Storms are getting "
		"worse and our supplies are running low. However, I think "
		"we will find the city before much longer...how much larger "
		"could the mountain be, right?\n\n"
		"%^CYAN%^BOLD%^Segiaday, Sixthmonth, Year 14%^RESET%^\n\n"
		"Ok...now things are looking bad. We've stopped in large "
		"valley in the mountain to look for some food because we "
		"have completely run out of supplies. I'm starting to grow "
		"weak and it hurts just to write...this may be my final "
		"entry. We feel we have failed our father, and ourselves.\n\n"
		"%^CYAN%^BOLD%^Serpentday, Sixthmonth, Year 14%^RESET%^\n\n"
		"We can't find food, all looks bad...it's cold and "
		"miserable. Most have died of starvation and boredom, but "
		"many were killed from bears and wolves as well. "
		"I want to go home. I just can't...\n\n\n"
		"%^YELLOW%^BOLD%^The journal ends here.%^RESET%^");
}
