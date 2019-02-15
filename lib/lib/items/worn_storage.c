/* mahkefel 2017:
 * attempting to remake worn storage
 * that don't crash
 */

#include <lib.h>

inherit LIB_ARMOUR;
inherit LIB_HOLDER;

// just dummy functions to keep old code working, this version
// ain't doing open/close. (For now at least.)
SetCanClose(int x) {return 0;}
GetCanClose() {return 0;}
SetClosed(int x) {return 0;}
GetClosed() {return 0;}

void create() {
  armour::create();
  holder::create();
  SetOpacity(0);
  SetPreventPut("You can't put this in there.");
}

// going to be simple for now with this.
varargs string GetLong(string str) {
  return armour::GetLong();
}

// I think this tells it to save objects in bag inventory?
int SetSaveRecurse(int x) {
  armour::SetSaveRecurse(x);
}

// AddSave is gross, piggybacking armour's AddSave
static mixed array AddSave(mixed array vars) {
    return armour::AddSave(vars);
}

// GetSave is also gross, ditto
string array GetSave() {
    return armour::GetSave();
}

