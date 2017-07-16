#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

int GetStaff();
int CheckStaff(string stat);

static void create() {
  item::create();
  SetKeyName("staff");
  SetId( ({"staff","seer staff"}) );
  SetShort("a long black staff");
  SetLong(
	  "This long black staff has been reinforced with a small "
	  "red leather bands. The bands are wound tight around "
	  "the thin long wooden staff giving it greater resistance "
	  "to take damage. Etched on the staff are some kind of "
	  "runes."
	  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1800);
  SetClass(25);
  SetValue(2500);
  SetMass(150);
  SetWeaponType("pole");
  SetDamageType(BLUNT|COLD);
  SetMaterial( ({"wood", "leather"}) );
  SetRepairSkills( ([
     "wood working"    : 8,
     "leather working" : 2,
     "weapon smithing" : 3,
     ]) );
  SetProperty(
	 "magic","This staff has been embedded with the power of "
	 "a shadow beast. Its presence gives off an aura of cold. "
	 "The runes on the staff keeps the shadow beast bound to "
	 "the seer staff."
	 );  
  SetWield( (:GetStaff:) );
  SetRepairDifficulty(45);
  SetHands(2);
}


int GetStaff() {
    if (this_player()->GetMorality() > -500) {
		this_player()->eventReceiveDamage(this_object(), COLD, random(500),
	    0, this_player()->GetWieldingLimbs() );
		send_messages("are", "$agent_name $agent_verb seared by a cold flash from "
        "the staff.", this_player(), 0, environment(this_player()) );
		return 0;
   }
	else {
		send_messages("wield", "$agent_name $agent_verb a seer staff.",
        this_player(), 0, environment(this_player()) );
		this_player()->AddStatBonus("wisdom", (: CheckStaff :) );
		this_player()->AddStatBonus("intelligence", (: CheckStaff :) );
		return 1;
	}
}



int CheckStaff(string stat) {
    if( !GetWorn() ) {
        previous_object()->RemoveStatBonus("wisdom", this_object());
        previous_object()->RemoveStatBonus("intelligence", this_object());
        return 0;
    }
    else return 25;
}
