/* huge sword
 * Ranquest@Haven
 * 02/13/99
 */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
int wimpy();

static void create() {
        item::create();
        SetWield( (:wimpy:) );
        SetShort("a huge sword");
        SetLong(
          "This huge weapon looks like it could be used"
          " for felling trees. It is so large that only"
          " the strongest of people can wield it.");
        SetId( ({"weapon","sword"}) );
        SetAdjectives("huge");
      SetClass(12);
      SetDamagePoints(1500);
        SetValue(1250);
        SetWeaponType("slash");
        SetDamageType(SLASH);
        SetKeyName("huge sword");
        SetMass(550);
        SetVendorType(VT_WEAPON);
        SetHands(2);
    }
    
int wimpy() {
  object who = this_player();
  if ( who->GetStatLevel("strength") < 80) {
    message("system","This weapon is too heavy for you!",who);
    return 0; }
  message("system","With a grunt, you wield the huge sword",who);
  return 1;
  }
