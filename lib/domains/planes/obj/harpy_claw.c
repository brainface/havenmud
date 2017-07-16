/*                       
* mahkefel     
* decent melee weapon for planes
*/                       
#include <lib.h>         
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;        

static void create() {
  item::create();     
  SetKeyName("steel talons");
  SetShort("steel talons");  
  SetLong(                     
    "This is a set of five curved steel spikes of various sizes. "
    "Leather straps thread through the spikes and would tie around "
    "the wearer's fingers. Rust colored stains along the metal attest "
    "to their effectiveness."
  );

  SetId( ({"talon","talons"}) );
  SetAdjectives(({"steel"}));
  SetClass(30);
  SetDamagePoints(2000);
  SetDamageType(PIERCE);
  SetHands(1);
  SetMass(20);
  SetMaterial("metal");
  SetRepairDifficulty(25);
  SetValue(500);
  SetVendorType(VT_WEAPON);
  SetWeaponType("melee");
}

// copy of taketori's dagger.
int eventStrike(object who) {
  int hit = random(12);
  int amt = random(10);
  if ( !random(12) ) {
    send_messages( ({"rake"}), "$agent_name%^RED%^ $agent_verb%^RESET%^ "
      "$agent_possessive steel talon's across $target_name, cutting "
      "five bloody channels into $target_possessive flesh!",
      this_player(), who, environment(who) );
    who->AddBleeding(2);
    return (item::eventStrike(who) + amt);
  }
  return (item::eventStrike(who));
}

