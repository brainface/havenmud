#include <lib.h>
inherit LIB_MAYOR;

static void create() {
  ::create();
  SetKeyName("nizzt");
  SetRace("gnome");
  SetGender("male");
  SetShort("Nizzt, Lord High Mucky-Muck of the Underland");
  SetId( ({ "gnome", "nizzt", "muck" }) );
  SetAdjectives( ({ "lord", "high", "mucky" }) );
  SetLong(
    "Nizzt is a big fish in a small pond. He takes his job very seriously, "
    "which is very well because few others in the Underland seem to. In theory, "
    "he is the final arbiter of all legal things here in the Underland. "
    "In reality, he processes paperwork for the gnomes."
    );
  SetClass("merchant");
  SetLevel(5);
  SetCurrency("rupies", 500);
  SetTown("Underland");
}
