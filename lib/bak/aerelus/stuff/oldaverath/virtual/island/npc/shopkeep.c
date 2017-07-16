/*    /domains/Ylsrim/npc/shiela.c
 *    From the Dead Souls V Object Library
 *    An example vendor
 *    Created by Descartes of Borg 960302
 */

#include <lib.h>
#include <vendor_types.h>
#include <domains.h>

inherit LIB_VENDOR;

static void create() {
    vendor::create();
    SetKeyName("shiela");
  SetId( ({ "shiela", "shopkeep" }) );
    SetShort("Shiela, the local shopkeep");
  SetLong("Shiela is the owner of the trading post here in town. "
          "She will gladly trade most any items for ducats.");
    SetLevel(15);
  SetClass("merchant");
    SetRace( "human");
    SetGender("female");
    SetMorality(40);
    AddCurrency("ducats", random(200));
    // Define the place where he stores stuff to sell
    SetStorageRoom(AVERATH_CITY "storeroom");
    // How good a vendor is he? Should be 100+
    SetSkill("bargaining", 110);
    // He should stay in his shop
    SetProperty("no bump", 1);
    // He accepts electrum
    SetLocalCurrency("ducats");
    // He sells armours
    SetVendorType(VT_ALL);
}
