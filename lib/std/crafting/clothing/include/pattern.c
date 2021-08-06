#include <lib.h>
inherit LIB_PERSIST;

private string CraftPattern;
string SetCraftPattern(string pattern) {return CraftPattern = pattern; }
string GetCraftPattern() {return CraftPattern;}

static void create() {

  AddSave( ({ CraftPattern }) );
}
