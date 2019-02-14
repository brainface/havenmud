#include <lib.h>
#include <vehicle.h>
inherit LIB_SHIP;

static void create() {
  ::create();
  SetKeyName("black night");
  SetShort("a rotting and decayed dreadnaught");
  SetId( ({ "dreadnaught", "black night", "ship" }) );
  SetAdjectives( ({ "rotting", "decayed" }) );
  SetLong("This is a nearly destroyed gigantic dreadnaught. The wood is rotting "
          "and the sails are nothing but tattered remains, it is a wonder they "
          "still catch wind. The ship is taking on water yet still manages to "
          "float. It gives of an unholy aura.");
  SetDamagePoints(800000);
  SetVehicleSize(VS_DREADNAUGHT);
  SetDriveSystem(VM_DEEP);
  SetSensorSuite(VSE_WIDE);
  SetCrystals(40000);
  SetWeaponSystem(VW_DEVASTATING);
  SetShieldSystem(VSH_LARGE);
  SetPrizeBonus(16);
  SetBridgeDescription("This rotting ship, known as %^BOLD%^%^BLACK%^Black Night"
    "%^RESET%^%^ORANGE%^, barely stays afloat, with water "
    "continuously splashing aboard.  The large center mast is covered by moss "
    "and is falling apart, pieces of wood are splintering off from it. The sails "
    "are tattered rags, it is amazing that this ship even moves. Large black "
    "steel catapults and ballista line the deck on either side. Towards the rear lies the "
    "wheel and the quarters of the captain. The deck itself is covered in black "
    "bile which seems to drip from the center mast. Cages hang from ropes, these "
    "cages are made from bones and trapped inside of them are half rotted corpses.");
}
