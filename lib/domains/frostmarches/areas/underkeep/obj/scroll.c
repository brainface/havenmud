//
// a scroll
// created by Ranquest@Haven
//
#include <vendor_types.h>
#include <lib.h>
 inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("scroll");
  SetShort("a tattered scroll");
  SetId("scroll");
    SetAdjectives("tattered");
  SetLong("The scroll is tattered and yellowing with age. The ink has faded "
    "almost into illegibility.");
  SetMass(5);
  SetRead("Thys being a trew ande honest account offe the falle of "
    "King Radchek. In his eightiethe yeare. The King, withered ande "
    "frail, haf decided to ende his reign with alle thee trappinges "
    "off powere and majestie intact, decreed that he, ande alle his "
    "retinue, be buried under the earth by a grate feat of magick, "
    "that we may continue to serve him fathfullie throwoute "
    "alle eternetie. Thif was compulsory, ande I, ande otheres, "
    "were considerabley annoyed, yet without recourse but to heed his "
    "decree.");
  SetDamagePoints(5);
  SetVendorType(VT_TREASURE);
    SetMaterial("textile");
    SetValue(20);
}
