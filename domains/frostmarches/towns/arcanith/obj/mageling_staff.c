/*  a mageling staff
 *  filename: mageling_staff.c
 *  idea: A staff that crackles when wielded by a mage
 *  By Sardonas@Haven (a.k.a Robert Kehrer)
 *  Coded: 11/10/1998
 */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

int WieldMe();

static void create() {
  item::create();
  SetKeyName("golden staff");
  SetId( ({ "staff" }) );
  SetShort("a golden staff");
  SetAdjectives( ({ "sparking", "smooth", "mageling's", "golden" }) );
  SetLong("This staff appears to be ancient, but still strong and "
          "sturdy.  This staff is made of a wood, that has a beautiful "
          "swirling grain to it.  The staff has a rich golden finish, "
          "and looks very smooth.  Small runes are etched into the "
          "golden surface; the runes sparkle with a mysterious silver "
          "twinkle.");
  SetProperty( "history", "This staff is one of the first creations made "
                          "by an aspiring arch-mage.  This is one of the "
                          "first creations that mages create when "
                          "learning to imbue items with magical energy.  "
                          "This particular staff was created by the "
                          "mageling Tival, he used the wood of the Aster "
                          "to create this staff.");
  SetProperty( "magic", "This staff sparks, flares and crackles when "
                        "wielded by a mage.  It is slightly better "
                        "than the average staff, and does electrical "
                        "damage.");
  SetMass(200);
  SetValue(400);
  SetVendorType(VT_WEAPON | VT_TREASURE | VT_MAGIC);
  SetDamagePoints(800);
  SetWeaponType("pole");
  SetDamageType(BLUNT||SHOCK);
  SetClass(13);
  SetMaterial( ({ "wood" }) );
  SetWield((: WieldMe :));
}

int WieldMe() {

  if(this_player()->GetClass()!="evoker"&&
     this_player()->GetClass()!="enchanter"&&
     this_player()->GetClass()!="diviner"&&
     this_player()->GetClass()!="necromancer") {
    message("system", "You wield the smooth mageling's "
                      "staff.", this_player());
    return 1;
    } 
  else {
    message("system", "As you hold the staff in your hands, it begins "
                      "to %^MAGENTA%^crackle%^RESET%^ and "
                      "%^MAGENTA%^spark%^RESET%^ as miniature "
                      "%^BLUE%^%^BOLD%^bolts of energy%^RESET%^ run up "
                      "and down its length.", this_player());
    return 1;
    }
}
