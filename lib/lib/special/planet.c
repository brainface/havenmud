/* A planet */
#include <lib.h>
#include <daemons.h>
#include <vehicle.h>
inherit LIB_DUMMY;

string Appearance;
string LandingZone;
string Location;
string Name;

string SetAppearance(string x) { 
	SetLong(x);
	return Appearance = x; 
}

string GetAppearance() { return Appearance; }

string SetLandingZone(string file) { 
	SetEnter(file);
	return LandingZone = file; 
}

string GetLandingZone() { return LandingZone; }

string SetLocation(string x) { 
	if (strsrch(base_name(this_object()), "/std/planets/") > -1)
	  PLANETS_D->AddPlanet(x, base_name(this_object()));
	return Location = x; 
}
string GetLocation() { return Location; }

string SetName(string x) { 
	SetKeyName(x);
	SetId(lower_case(x), "planet");
	SetShort(x);
	return Name = x; 
}

string GetName() { return Name; }

string GetAffectLong(object ob) {
	return "There is " + Appearance + " here.";
}

mixed direct_enter_obj() {
	if (!LandingZone) return "You cannot land there right now.";
	if (!vehiclep(this_player())) return "You planning on flying down?";
	if (environment(this_player())->GetVehicleSize() > VS_SHUTTLE) {
		return "That ship is too large to enter the atmosphere.";
	}
	all_inventory(this_player())->AddExploredWorld(GetKeyName());
	return 1;
}

mixed direct_pilot_on_str() {
	return 1;
}

mixed direct_pilot_into_str() {
	return 1;
}

mixed eventEnter(object who, string what) {
  mapping LandingData = GetEnterData();
  if (!vehiclep(who)) {
  	who->eventPrint("You cannot land without a ship!");
  	return 1;
  	}
  if( LandingData["pre"] && !evaluate(LandingData["pre"], what) ) {
	  return 1;
    }
    who->eventMoveLiving(LandingData["room"], "$N lands on " + GetAppearance() + ".");
    all_inventory(who)->AddExploredWorld(GetName());
  if( LandingData["post"] ) {
	  evaluate(LandingData["post"], what);
  }
  return 1;
}