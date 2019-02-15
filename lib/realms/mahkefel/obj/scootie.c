#include <lib.h>
#include <vehicle.h>
inherit LIB_SHIP;

static void create() {
  ::create();
  SetKeyName("scootie");
  SetShort("a really badass scootie");
  SetId( ({ "scootie" }) );
  SetAdjectives( ({ "really", "badass" }) );
  SetLong("You see before you the most badass possible moped ever imagined "
    "by all of humankind. Its wheels are that really thick offroad tread "
    "and the body is a bright red color. Flames, literal flames, none "
    "of this painted bullshit crawl up the sides and neon lights on the "
    "undercarriage rotate through a variety of hues. The engine is some "
    "contraption full of gears and sprockets that matches in badassery only "
    "what it produces in inefficiency and smoke. In violation of all good "
    "sense, in addition a rotor spins just above the drivers head.");
  SetDamagePoints(800000);
  SetVehicleSize(VS_YACHT);
  SetDriveSystem(VM_DEEP);
  SetSensorSuite(VSE_WIDE);
  SetCrystals(40000);
  SetWeaponSystem(VW_HUGE);
  SetShieldSystem(VSH_MEDIUM);
  SetPrizeBonus(16);
  SetBridgeDescription(
    "Genuine really comfortable something or nother lines the seat of this "
    "scooty, and really grippy stuff is wrapped around the handlebars. A "
    "jagged crosshair is painted through the windshield in red, though you're "
    "pretty sure there's no weapons attached, as if someone were afraid to arm "
    "this thing. "
    "Various dials, gauges, and meters are arrayed in front of you backlight "
    "with a dissorienting array of lights. You're pretty sure at least one is "
    "a barometer. A high-resolution gps display also seems to be indicating "
    "the location of various other people in your vicinity. perhaps you could "
    "\"scoot to\" them? Or \"scoot home\" when you're done with jerks."
  );
  SetSmell("It smells like goddamned victory.");
  SetListen("You can barely hear some guy crooning about whiskey over the whirring of the propeller");
}

void init() {
  ::init();
  add_action("scoot", "scoot");
  }

int scoot(string args) {
  object jerkface;
  object jerkstore;

  if (!args) {
    message("system", "Perhaps you should try to <scoot to jerkface> next time.",
    this_player() );
    return 1;
    }
  args = replace_string(args,"to ","");
  if (args == "home") {
    jerkstore = get_object("/realms/alessandra/workroom");
  } else {
    jerkface = find_player(args);
    if (!jerkface) {
      eventPrint("There's no jerkface by that name your scootie can find!");
      return 0;
    }
    jerkstore = environment(jerkface);
    if (!jerkstore) {
      eventPrint("That jerkface is in some terrible place you don't want to go!");
      return 0;
    }
  }
  environment()->eventPrint("put put put put VROOM WHRRRR");
  eventPrint("put put put put VROOM WHRRRR");
  jerkstore->eventPrint("put put put put VROOM WHRRRR");
  eventMove(jerkstore);
  return 1;
}

string GetShort() {
  object rider;
  string rider_desc;
  foreach(object liv in all_inventory()) { if (living(liv)) rider_desc = liv->GetKeyName(); }
  if (rider_desc) {
    rider_desc = capitalize(rider_desc);
    return ::GetShort() + " (ridden by " + rider_desc + ")";
  }
  return ::GetShort();
}

