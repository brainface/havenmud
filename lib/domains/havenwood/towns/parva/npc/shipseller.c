#include <lib.h>
#include <domains.h>
#include <vehicle.h>
#include "../parva.h"
inherit LIB_SHIPSELLER;

static void create() {
  ::create();
  SetKeyName("barbosa");
  SetShort("Commodore Barbosa the Shipwright of Parva");
  SetId( ({ "barbosa", "commodore", "shipwright" }) );
  SetAdjectives( ({ "commodore" }) );
  SetLong(
    "Commodore Barbosa is the closest thing Parva has to a valuable merchant. "
    "His thriving business in ship sales and repair keeps his profitability "
    "in line with his costs for weapons, sails, and navigation tools."
  );
  SetRace("human");
  SetGender("male");
  SetLocalCurrency("oros");
  SetWharf(PARVA_ROOM + "/docks1");
  SetClass("rogue");
  SetClass("sailor");
  SetMorality(-250);
  SetLevel(25);
  SetLimit(1);
  SetLargestShip(VS_CRUISER);
  SetDriveModifier(0.6);
  SetWeaponModifier(0.6);
  SetRepairModifier(1.2);
  SetSalvageModifier(1.6);
  SetSensorModifier(0.6);
  SetShipModifier(1.2);
}
