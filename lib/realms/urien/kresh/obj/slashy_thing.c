/*  A slash weapon */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("shortsword");
  SetShort("a curved shortsword");
  SetId( ({ "sword", "shortsword" }) );
  SetAdjectives( ({ "curved", "short" }) );
  SetClass(12);
  SetMass(60);
  SetValue(30);
  SetWeaponType("slash");
SetVendorType(VT_WEAPON);
  SetDamageType(SLASH);
  SetLong("This shortsword is curved into a viscious slashing weapon "
         "fit for deadly close in melee combat.");
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
        "metal working" : 1,
        "weapon smithing" : 1,
     ]) );
  SetDamagePoints(1600);
  }
