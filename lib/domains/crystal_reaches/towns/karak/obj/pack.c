// Karak Recode
// Laoise
// 2007

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_STORAGE;

static void create() 
{
  ::create();
  SetKeyName("backpack");
  SetId( ({ "backpack", "pack" }) );
  SetAdjectives( ({ "large", "canvas", "back" }) );
  SetShort("a large canvas pack");
  SetLong(
    "This pack is made of canvas and is designed to be strapped onto the "
    "back. It is stitched together with dark thread which appears sturdy. "
    "It is of a size which would accommodate several pieces of equipment." 
  );
  SetMass(30);
  SetValue(60);
  SetCanClose(1);
  SetClosed(1);
  SetMaxCarry(1000);
  SetMaterials( ({
  	"leather"
  }) );
  SetRepairDifficulty(40);
}

