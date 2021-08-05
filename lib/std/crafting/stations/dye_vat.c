/* Mahkefel 2021
 * Crafting table thingy for dying things
 * 
 */
#include <lib.h>

inherit LIB_STORAGE;

string Color = "black";

string SetColor(string color) {
  return Color = color;
}

string GetColor() {
  return Color;
}

static void create() {
  storage::create();
  SetShort("a vat of dye");
  SetKeyName("vat");
  SetId( ({"vat" }) );
  SetAdjectives( ({ "vat", "of", "dye" }) );
  SetLong(
    "A big cauldron full of various conflicting hues of "
    "viscous liquids stands here. You can 'mix' it to a "
    "specific color or 'dip' thread and yarn in it."
  );
  SetMass(5000);

  SetMaxCarry(5000); // meh put a lot in there.
  SetPreventPut("You can't 'put' anything in the vat, "
    "but you can 'dip' thread or yarn or 'mix' a different "
    "color");   
  SetPreventGet("The vat won't go anywhere with hue.");
  SetDamagePoints(5000);
  SetCanClose(0);
  SetClosed(0);
  SetCanLock(0);
  SetLocked(0);
}

int indirect_dip_obj_in_obj() {
  return 1;
}

int direct_mix_obj_to_str() {
  return 1;
}

// override inventory
mixed CanPutInto(object who, object item) {
  who->eventPrint("Alchemy is not yet implemented. Simply <mix> vat to <color>.");
}

// override internal desc to show a fake pool of dye
string GetInternalDesc() {
  return "\nThe vat is full of a viscous " + GetColor() + " fluid.";
}
