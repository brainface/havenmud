#include <lib.h>
inherit LIB_PERSIST;

string CraftDye;
string SetDye(string dye) {return CraftDye = dye; }
string GetDye() {return CraftDye;}

static void create() {

  AddSave( ({ CraftDye }) );
}
