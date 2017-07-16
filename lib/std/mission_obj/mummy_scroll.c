/* Old papyrus scroll
 * Teaches mummify
 * mahkefel jan 2011
 */
#include <lib.h>
inherit LIB_SCROLL;

static void create() {
  scroll::create();
  SetShort("A tattered scroll");
  SetLong("This papyrus scroll is tattered and crumbling with age. "
    "Faded arcane heiroglyphs describing some dark ritual run "
    "along its length.");
  SetAdjectives(({"tattered","papyrus"}));
  SetSpell("mummify");
}

