/* Davantalus@haven 20060224
     A purse of holding for luna's wedding
*/

#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_STORAGE;

static void create() {
	::create();
	SetShort("a small white purse");
	SetKeyName("purse");
	SetId( ({ "purse" }) );
	SetAdjectives( ({ "small, white" }) );
	SetLong(
	  "This small purse was created by a skilled tailor for the wedding "
	  "of Luna An'Duheart to Atrus. It was later enchanted by Luna to hold "
	  "all of her worldly possessions so that she didn't look silly during "
	  "the ceremony. The purse is so beautifully crafted and enchanted that "
	  "it slightly glows."
	  );
	SetMass(100);
	SetCanClose(1);
	SetClosed(0);
	SetMaxCarry(15000);
	SetPreventGet(0);
	SetCanLock(0);
	SetOpacity(100);
  //SetSize(SIZE_MEDIUM);
  //SetArmourType(A_BELT);
  //SetArmourClass(ARMOUR_CLOTH);
  //SetProtectionBonus(MAGIC, 25);
  SetMaterial( ({ "textile" }) );
}
 
