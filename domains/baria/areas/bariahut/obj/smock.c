//Alex@Haven
//2006
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create(){
  armour::create();
  SetKeyName( "smock" );
  SetShort( "a ripped smock" );
  SetId( ({ "smock" }) );
  SetAdjectives( ({ "ripped", "old" }) );
  SetArmourClass(ARMOUR_CLOTH);
  SetMaterials( ({ "textile" }) );
  SetLong(
    "This smock serves as a comforting garb "
    "for the elderly. The long sleeves hang as loosely as "
    "the shin-length hem. It appears neither warm nor "
    "protective against any weapon, and is covered in "
    "orangey colored fruit stains.");
  SetMass(20);
  SetValue(30);
  SetDamagePoints(500);
  SetWarmth(15);
  SetArmourType(A_BODY_ARMOUR);
  SetRepairDifficulty(5);
  SetSmell( "It smells of stale sweat and alcohol." );
}
/* see notes on other files.  smell/id/adjectives/keyname */
