#include <lib.h>
#include <vendor_types.h>
#include "../rook.h"

inherit LIB_ITEM;
 
static void create() {
  item::create();
  SetKeyName("grail");
  SetId( ({ "grail" }) );
  SetShort("a decorative grail");
  SetLong("This grail is very ornate looking.  It is "
    "made of mithril and covered in precious stones.  "
    "Writing is inscribed into the base of it but it "
    "written in an ancient and obscure language.");
  SetAdjectives( ({"decorative","ornate"}) );
  SetMass(25);
  SetValue(5000);
  SetMaterial("mithril");
  SetVendorType(VT_TREASURE);
}
