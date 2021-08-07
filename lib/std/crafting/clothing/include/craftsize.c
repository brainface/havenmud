#include <lib.h>


string CraftSize;
string SetCraftSize(string size) {return CraftSize = size; }
string GetCraftSize() {return CraftSize;}

string array GetSave() {
  return ({ "CraftSize" });
}
