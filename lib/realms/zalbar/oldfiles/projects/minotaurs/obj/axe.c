
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

int AttemptWield();

static void create() {
	item::create();
	SetKeyName("axe");
	SetId( ({"axe"}) );
	SetAdjectives( ({"large","double","edge","double-edge"}) );
	SetShort("a large double-edge axe");
	SetLong("This large double-edge axe is a massive weapon for a normal "
	        "sized man but it was crafted by minotaurs to be used by "
	        "minotaurs. The long wood handle is reinforced with leather "
	        "straps for the wielders hands. The sides of large double "
	        "blades is stratched up but the blades' edges are sharpen "
	        "to perfection.");
	SetClass(40);
	SetDamagePoints(2000);
	SetValue(2000);
	SetMass(300);
	SetHands(2);
	SetMaterial( ({ "metal", "wood" }) );
	SetRepairSkills( ([
		"weapon smithing" : 30,
		"metal working"   : 30,
		"wood working"    : 30,
		]) );
	SetRepairDifficulty(32);
	SetWeaponType("hack");
	SetDamageType(SLASH);
	SetVendorType(VT_WEAPON);
	SetWield( (:AttemptWield:) );
}

int AttemptWield() {
  if (this_player()->GetStatLevel("strength") < 100 ) {
    send_messages("wield", "$agent_name  are not strong enough to $agent_verb this axe.",
        this_player(),0,0);
   return 0;
   }
  return 1;
}

