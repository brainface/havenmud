#include <lib.h>  
#include <vendor_types.h>
#include <domains.h>     
#include <std.h>
#include "../nat_store.h"

inherit LIB_VENDOR;

void makeChest();

static void create() {
  vendor::create();   
  SetKeyName("constanza");
  SetId( ({ "constanza", "armourer" }) );
  SetShort("Constanza, Armourer of the Havenwood");
  SetAdjectives( ({ "armourer","of the" }) );      
  SetLong(                                         
    "Constanza, a merchant of rather larcenous reputation from Parva, has taken "
    "up trade with Talamar his secluded shop. "                                  
    "Her armours are well in demand by those that don't want to draw too much "  
    "attention to themselves, nor drown at sea under the weight of plate mail."  
  );                                                                             
  SetRace("half-elf");
  SetGender("female");
  SetBaseLanguage("Enlan");
  SetLocalCurrency("imperials");
  SetTown("Parva");
  SetMorality(-100);
  SetClass("merchant");
  SetClass("rogue");
  SetLevel(30);
  AddCurrency("imperials", random(500)+500);
  SetStorageRoom(NAT_STORE_ROOM "rl_store");
  SetVendorType(VT_ARMOUR);
  SetInventory( ([
    NAT_STORE_OBJ "prop_awl" : "wield awl",
    NAT_STORE_OBJ "rl_pants" : "wear pants",
    NAT_STORE_OBJ "rl_hat" : "wear hat",
    NAT_STORE_OBJ "rl_cuirass" : "wear cuirass",
  ]) );
  SetAction( 5, ({
    "!emote wrinkles up her nose.",
    "!emote carefully rivets a steel plate to a leather hide.",
    "!emote violently stabs a series of regular holes in an unfinished "
      "cuirass.",
    "!say You really should sweep more in here.",
    "!say Would it hurt if we had one less deer head hanging up?",
    "!say Buy our armour!",
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

