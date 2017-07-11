#include <lib.h>       
#include <vendor_types.h>
#include <domains.h>     
#include "../nat_store.h"

inherit LIB_VENDOR;
void makeChest();

static void create() {
  vendor::create();
  SetKeyName("talamar");
  SetId( ({ "talamar", "taxidermist" }) );
  SetShort("talamar the Taxidermist");
  SetAdjectives( ({ "leather" }) );
  SetLong(
    "Talamar is a hulking brute of an elf, standing head and shoulders over his "
    "cousins. He's known around the havenwood for making animal skins into "
    "useful things like armour and shields, as well as less useful things like "
    "mounted heads. His armour is known to be extremely protective, if somewhat "
    "feral-looking."
  );
  SetRace("wild-elf");
  SetGender("male");
  SetBaseLanguage("Eltherian");
  SetLocalCurrency("imperials");
  SetTown("Havenwood");
  SetMorality(100);
  SetClass("merchant");
  SetLevel(30);
  AddCurrency("imperials", random(500)+500);
  SetStorageRoom(NAT_STORE_ROOM "store");
  SetVendorType(VT_ARMOUR);
  SetInventory( ([
    NAT_STORE_OBJ "prop_broom" : "wield broom",
    NAT_STORE_OBJ "nat_leggings" : "wear leggings",
    NAT_STORE_OBJ "nat_shirt" : "wear shirt",
  ]) );
  SetAction( 5, ({
    "!emote sweeps ineffectually with his broom.",
    "!emote plucks some hair from a half-cleaned skin.",
    "!emote whistles merrily.",
    "!say You get used to the smell after a while. Mostly.",
    "!say I killed most of the animals you see mounted here.",
    "!say The bear hanging from the north wall nearly did me in.",
  }) );
  call_out( (: makeChest :), 0);
}


// take over one existing, unowned lootchest
//   in my room.
void makeChest() {
  object chest;
  // make a chest
  //chest = new(STD_OBJ "lootchest");

  // if I'm somewhere
  if ( !environment(this_object()) ) return;

  foreach( object thing in all_inventory(environment(this_object())) ) {
    if ( member_array("loot_chest", thing->GetId() ) != -1) {
      if(!thing->GetOwner()) {
        thing->SetOwner(this_object());
        return;
      }
    }
  }
}
