// Title: Durgoroth Town
// File: blade.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: A nosferatu blade
//
// Revision History: 
//

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
	item::create();
	SetKeyName("blade");
	SetId( ({"sword","weapon","blade", "katana"}) );
	SetAdjectives( ({"graceful","black"}) );
	SetShort("a graceful black blade");
	SetLong("A long, deadly looking, gracefully curved and razor "
					"sharp blade of exquisite craftsmanship. The blade is "
					"made of a strange jet black metal, while the hilt is "
					"formed by a wrapping of gold wire.");
	SetClass(20);
	SetDamagePoints(1800);
	SetValue(1800);
	SetMass(150);
	SetMaterial( ({ "metal" }) );
	SetRepairSkills( ([
		"weapon smithing" : 14,
		"metal working" : 14,
		]) );
	SetRepairDifficulty(32);
	SetWeaponType("slash");
	SetDamageType(SLASH);
	SetVendorType(VT_WEAPON);
	SetProperty("magic", "This sword seems to be imbued with "
							"magical energies of evil and the netherworld. It will "
							"undoubtedly yield some unusual effects when used by one "
							"of evil alignment in combat.");
}

int eventStrike( object target ) {
	if( environment(this_object())->GetMorality() <= -250 ) {
		if(!random(5)) {
			this_player()->SetMorality(this_player()->GetMorality() - 5);
			if(!random(3)) {
				message("slice", "%^BOLD%^MAGENTA%^The blade "
					"seems to suck all light from the room before "
					"striking "+target->GetCapName()+" with tremendous "
					"force.", environment(target),target);
				message("slice", "%^BOLD%^MAGENTA%^The blade "
					"seems to suck all light from the room before "
					"striking you with tremendous "
					"force.", target);
				return item::eventStrike(target) + (10 + random(11));
				}
			else if(!random(2)) {
				message("slice", "%^BOLD%^BLUE%^The blade "
					"slices deeply into "+target->GetCapName()+", "
					"nearly cleaving "+objective(target)+" in two.",
					environment(target),target);
				message("slice", "%^BOLD%^BLUE%^The blade "
					"slices deeply into you, nearly cleaving you in two.",
					target);
				return item::eventStrike(target) + (5 + random(11));
				}
			else {
				message("slice", "%^BOLD%^CYAN%^A bolt of "
					"energy leaps from the blade of the blade, "
					"drawing a scream of pure agony from "
					+target->GetCapName()+" as it strikes "
					+objective(target)+".", environment(target),target);
				message("slice", "%^BOLD%^CYAN%^A bolt of "
					"energy leaps from the blade of the blade, "
					"drawing a scream of pure agony from you as it "
					"strikes you.", target);
				return item::eventStrike(target) + (5 + random(6));
				}
			}
		}
	return item::eventStrike(target);
	}
