#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
int DoWield();
static void create() {
  item::create();
  SetKeyName("nodachi");
  SetId( ({ "sword", "nodachi" }) );
  SetAdjectives( ({ "black-handled", "black" }) );
  SetShort("a black-handled nodachi");
  SetLong(
    "This is an extremely well crafted blade that"
    " looks like an oversized katana. It is a two"
    " handed weapon that has a handle that is"
    " about a foot and a half in length while"
    " the blade is nearly three feet long."
  );
  SetClass(24);
  SetDamagePoints(4000);
  SetValue(1500);
  SetWeaponType("slash");
  SetDamageType(SLASH);  
  SetMass(175);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
     "metal working" : 8,
     "weapon smithing" : 8,
  ]) );
  SetRepairDifficulty(20);
  SetVendorType(VT_WEAPON);
  SetHands(2);
  SetWield( (: DoWield :) );
}

int DoWield() {
  if( this_player()->GetSkillLevel("slash combat") < 99 ) {
     message("nowield", "You are not skilled enough to wield this"
                " blade.", environment());
     return 0;
     }
    send_messages("wield",
      "$agent_name $agent_verb $target_name.",
      this_player(), this_object(), environment(this_player()) );
      return 1;
      }         
