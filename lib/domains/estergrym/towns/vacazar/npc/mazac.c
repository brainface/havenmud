// Coded by Zeratul
// 3-22-2000

#include <lib.h>
#include <vendor_types.h>
#include "../vacazar.h"
inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("mazac");
  SetId( ({"mazac","smith"}) );
  SetShort("Mazac the smith");
  SetLong(
     "Mazac is a large and strong skaven. His large frame comes from "
     "countless days spent working in the forge that sits in the corner "
     "of the smithy. His face is covered with a black ash, giving a short "
     "smirk to those around him. "
  );
  SetRace("skaven");
  SetGender("male");
  SetClass("merchant");
  SetLevel(8);
  SetVendorType(VT_WEAPON|VT_ARMOUR);
  SetLocalCurrency("vacari");
  SetStorageRoom(V_ROOM + "storage/str_smithy");
  }
