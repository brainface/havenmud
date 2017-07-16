/*    /realms/haun/areas/mines/obj/pouch.c
 *    created on 12/20/98
 *    by Haun
 */
#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_STORAGE;

static void create() 
{
    storage::create();
    SetKeyName("pouch");
    SetId( ({ "pouch" }) );
    SetAdjectives( ({ "gray","canvas" }) );
    SetShort("a gray canvas pouch");
    SetLong("This rather small, gray canvas pouch is tied off at the top by a "
      "short piece of string.");
  SetMass(2);
  SetValue(10);
  SetCanClose(1);
  SetClosed(1);
  SetMaxCarry(45);
  SetVendorType(VT_CLOTHING);
  }