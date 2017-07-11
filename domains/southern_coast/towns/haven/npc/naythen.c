#include <lib.h>
#include <vendor_types.h>
#include "haven.h"
inherit LIB_OLD_VENDOR;

static void create() {
  ::create();
  SetKeyName("naythen");
  SetId( ({ "naythen" }) );
  SetShort("Naythen the smith");
  SetRace("elf");
  SetGender("male");
  SetClass("fighter");
  SetSkill("bargaining",2,0);
  SetSkill("melee combat",1,2);
  SetLevel(12);
  SetMorality(250);
  SetVendorType(VT_WEAPON);
  SetLocalCurrency("imperials");
  SetLong("Naythen is a huge bear of an elf.  His large frame comes \n"
          "from countless days spent working in the forge that sits \n"
          "dominating the center of his shop.");
  SetStorageRoom(H_ROOM + "storage_rooms/str_sm");
  }
