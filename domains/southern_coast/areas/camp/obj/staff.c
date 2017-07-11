#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
int MageTest();

static void create() {
  item::create();
  SetKeyName("black staff");
  SetRepairDifficulty(12);
  SetRepairSkills( ([
    "weapon smithing" : 1,
    "wood working" : 1,
    ]) );
  SetMaterial( ({ "wood" }) );
  SetShort("a long, black staff");
  SetId( ({ "staff", "black staff", "long staff", "long black staff" }) );
  SetLong("This is a long, dark staff of fine wood.  Its surface is \n"
          "unmarred by knots or faults.");
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetClass(14);
  SetVendorType(VT_WEAPON|VT_MAGIC);
  SetRadiantLight(4);
  SetHands(2);
  SetProperty("magic",
       "This magical staff detects evokers and glows for them.");
  SetValue(1200);
  SetDamagePoints(1600);
  SetWield( (: MageTest :) );
 }

  int MageTest() {
   if (this_player()->ClassMember("enchanter") || 
       this_player()->ClassMember("necromancer") ||
       this_player()->ClassMember("diviner") ||
       this_player()->ClassMember("evoker") ) {
        message("my_action",
           "The sleek staff feels warm to the touch.  Oddly, it "
          "%^YELLOW%^glows %^RESET%^slightly.",
            this_player() );
           message("other_action",
             this_player()->GetCapName() + "'s staff starts to glow.",
              environment(this_player()), this_player() );
            SetRadiantLight(7);
             return 1;
          } else {
          message("my_action",
             "The staff makes a sharp hissing noise as you attempt "
             "to wield it.",
             this_player() );
           message("other_action",
             this_player()->GetCapName() + " is burned by the black staff.",
             environment(this_player()), this_player() );
           this_player()->eventReceiveDamage(this_object(), HEAT,
               random(20), 0, this_player()->GetWieldingLimbs() );
            return 0;
            }
        }

  int eventUnequip(object who) {
      SetRadiantLight(0);
       message("my_action",
          "The staff dims.",
         environment(this_object()) );
       message("other_action",
         environment(this_object())->GetCapName()+"'s staff dims.",
          environment(environment(this_object())),
          environment(this_object()) ); 
         ::eventUnequip(who);
      }
