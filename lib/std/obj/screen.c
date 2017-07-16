#include <lib.h>
inherit LIB_ITEM;
string eventView();

static void create() {
	::create();
	SetKeyName("crystal ball");
        SetMaterial( ({ "natural" }) );
	SetShort("a crystal ball");
	SetInvis(1);
  SetId( ({ "ball", "crystalball" }) );
  SetAdjectives( ({ "crystal" }) );
	SetPreventGet("");
	SetLong((: eventView :));
	SetRadiantLight(20);
}

string eventView() {
	object ship = environment();
	string *tmp = ({ });
	if (!ship) return;
	if (!vehiclep(ship)) return "This is a crystal ball, which is not installed.";
	tmp = ship->GetCrew();
	foreach(string s in tmp) {
		tmp -= ({ s });
		tmp += ({ capitalize(s) });
	}
	return 
          "\n%^BOLD%^BLUE%^The crystal ball reads:%^RESET%^" +
	  "\nShip Class: " + ship->GetVehicleSizeString() + 
	  ship->GetItemCondition() + "\n" +
	  "Ship Stores State: " + ship->GetCrystals() + "\n" +
	  ship->GetDriveStatus()  + "\n" +
	  ship->GetWeaponStatus() + "\n" +
	  ship->GetShieldStatus() + "\n" +
	  ship->GetSensorStatus() + "\n" +
          "Owned by: " + capitalize(ship->GetOwner() || "No-one") + "\n" +
          "Captained by: " + capitalize(ship->GetCaptain() || "No-one") + "\n"  +
          "Crew: " + conjunction(tmp, "and") + "\n" +
	 (ship->GetHasMoved() 
	      ? "The ship is preparing to move." 
	      : "The ship is ready to move.") + "%^RESET%^";
}

string GetAffectLong() { return "\nThere is a glowing crystal ball here."; }

string GetItemCondition() { return ""; }

int eventMove(mixed dest) {
  int x = ::eventMove(dest);
  
  if (!environment()) {
    call_out( (: eventDestruct :), 1);
    return 1;
  }
  if (!vehiclep(environment())) {
    call_out( (: eventDestruct :), 1);
    return 1;
  }
  return x;
}
