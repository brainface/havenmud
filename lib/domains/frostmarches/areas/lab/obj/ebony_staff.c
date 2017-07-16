#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../path.h"

inherit LIB_ITEM;

static void create()
{
::create();
  SetKeyName( "staff" );
  SetId( ({ "ebony staff", "staff" }) );
   SetAdjectives( ({ "ebony","wooden","dark","black" }) );
  SetShort( "an ebony staff" );
  SetLong( "The staff is made of dark black wood.  From its cracks and "
           "splinters, it seems to be very old.  Yet its sturdiness seems "
           "to have been unaffected by age.  Barely differentiable from "
           "the numerous cracks, small symbols appear to be written along "
           "the side of the staff.  These symbols do not seem to belong to "
           "any known script." );
  SetHands( 2 );
  SetClass( 17 );
  SetWeaponType( "pole" );
  SetDamageType( BLUNT );
  SetDamagePoints( 1200 );
  SetValue( 140 );
  SetMass( 225);
  SetMaterials( "wood" );
  SetRepairDifficulty( 4 );
  SetRepairSkills( ([ "wood working" : 1 ]) );
}
