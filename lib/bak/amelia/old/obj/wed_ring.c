/*    /obj/wed_ring.c
 *    from Nightmare LPMud
 *    created by Descartes of Borg 951211
 */
 
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
 
inherit LIB_ARMOUR;
 
private string Spouse;
 
mixed eventMove(mixed dest);
string SetSpouse(string str);
string GetSpouse();
string RealLong();
 
static void create() {
    armour::create();
    AddSave( ({ "Spouse" }) );
    SetKeyName("wedding ring");
    SetId( ({ "ring", "wedding ring" }) );
    SetAdjectives( ({ "golden", "gold" }) );
    SetShort("a wedding ring of gold");
    SetLong( (:RealLong:) );
    SetVendorType(VT_ARMOUR | VT_MAGIC);
    SetMass(10);
    SetValue(0);
    SetPreventDrop("You may not drop your wedding ring!");
    SetRetainOnDeath(1);
    SetDamagePoints(1000000);
    SetProtection(BLUNT, 3);
    SetProtection(BLADE, 3);
    SetProtection(KNIFE, 3);
    SetArmourType(A_RING);
}
 
mixed eventMove(mixed dest) {
    mixed tmp;
 
    if( !environment() ) {
tmp = armour::eventMove(dest);
//if( tmp == 1 ) environment()->eventForce("wear wedding ring");
return tmp;
    }
    else return 0;
}
 
string SetSpouse(string str) {
    if( Spouse ) return Spouse;
    else return Spouse = str;
}
 
string GetSpouse() { return Spouse; }
 
string RealLong() {
    return ("This beautiful golden band was given to you by \n" +
     GetSpouse() + " to capture your eternal love. \n"
      "Use <sp> and <esp> to communicate.");
}
 
void init() {
  ::init();
  add_action("sp", "sp");
  add_action("esp", "esp");
  SetSpouse(environment()->GetSpouse());
  if (find_living(lower_case(GetSpouse()))) {
     environment()->eventPrint("%^BLUE%^BOLD%^Your spouse is logged on.%^RESET%^");
  } else {
     environment()->eventPrint("%^BLUE%^BOLD%^Your spouse is not logged on.%^RESET%^");
  }
  if (find_living(lower_case(GetSpouse()))) {
    find_living(lower_case(GetSpouse()))->eventPrint("%^BLUE%^BOLD%^" 
                                    "Your spouse has "
                                         "rejoined this reality.%^RESET%^");
    }
  }

int sp(string blah) {
  object me = environment();
  object sps = find_living(lower_case(GetSpouse()));
  if (!sps) {
    message("fail",
       "Your spouse is not logged on.",
         me);
      return 1;
     }
  if (!blah) { message("fail", "Tell your spouse what?", me);
    return 1;
    }
  message("broadcast",
   capitalize(me->GetKeyName()) +
        " " + "%^BOLD%^BLUE%^<spouse> %^RESET%^" + blah,
    ({ me, sps }) );
   return 1;
  }

int esp(string blah) {
  object sps = find_living(lower_case(GetSpouse()));
  object me = environment();

  if (!sps) {
      message("fail",
          "Your spouse is not logged on.",
         me);
       return 1;
      }
  if (!blah) { message("fail", "Tell your spouse what?", me);
     return 1;
    }
  message("broadcast",
  "%^BOLD%^BLUE%^<spouse> %^RESET%^" +(capitalize(me->GetKeyName()))+" "+blah,
    ({ me, sps }) );
  return 1;
  }

