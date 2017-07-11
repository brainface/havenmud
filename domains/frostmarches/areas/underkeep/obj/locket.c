//
// a silver locket
// created by Ranquest@Haven
//
#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
 inherit LIB_ARMOUR;
 static void create() {
  ::create();
  SetShort("an ornate silver locket");
  SetLong("This is an ornate silver locket, probably a lover's gift"
    " to one of the sentries stationed here. Written on the side is the"
    " legend: \n 'To Freddie, with all my love - Emily'");
  SetKeyName("locket");
  SetId( ({"locket"}) );
  SetAdjectives( ({"silver","ornate"}) );
  SetProperty("history",
    "This device was wrought by one of the castle's silversmiths on"
    " commission by Emily of Tarsus. She gave this to a young guardsman"
    " called Freddie as a token of her love, for they were forbidden to"
    " marry by her father, King Radchek's Master of Ceremonies."); 
  SetMass(10);
  SetWarmth(0);
  SetDamagePoints(20);
  SetVendorType(VT_TREASURE);
  SetArmourType(A_AMULET);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
  SetValue(500);
  SetRepairSkills( ([
                    "metal working" : 4,
                  ]) );
  SetMaterial("metal");
  SetRepairDifficulty(10);
}


/* Approved by Duuktsaryth on Sun Nov 22 18:27:50 1998. */

