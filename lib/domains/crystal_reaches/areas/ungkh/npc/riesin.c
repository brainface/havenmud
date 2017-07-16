//Selket@Haven
//2006
#include <lib.h>
#include <daemons.h>
#include "../ungkh.h"
#include <vendor_types.h>
inherit LIB_VENDOR;

static void create() {
  ::create();
  SetKeyName("riesin");
  SetId( ({ "riesin", "shopkeep" }) );
  SetShort("Riesin, the shopkeep");
  SetLong("Riesin supplies the various people of Ungkh with "
         "herbs and various things, and they let her because "
         "it keeps her from causing trouble with her enormous "
         "form.");
  SetMorality(-400);
  SetStorageRoom(U_ROOM "shop_storage");
  SetRace("giant");
  SetClass("merchant");
  SetTown("Ungkh");
  SetLevel(85);
  SetGender("female");
  SetMorality(-100);
  SetVendorType(VT_ALL);
  SetBaseLanguage("Uruk");
  SetLocalCurrency("skins");
  SetStorageRoom(U_ROOM "shop_storage");
  SetMaxSingleItem(20);
  SetMaxItems(300);
  SetAction(5, ({
    "!say Buy or go away, fleshbag.",
    "!emote sizes you up.",
    "!spit",
    "!emote stares at your pockets.",
    }) );
 }

int eventDie(object killer) {
  object orc_inv;
  object orc_inv_2;
  if(!random(500)) {
     orc_inv = new(DIR_INVASIONS + "/jidoor_orc/oij_inv");
    INVASION_D->eventRegisterInvasion(orc_inv, killer);
     orc_inv_2 = new(DIR_INVASIONS + "/jidoor_orc/oij_2_inv");
    INVASION_D->eventRegisterInvasion(orc_inv_2, killer);
  }
  return ::eventDie(killer);
}
