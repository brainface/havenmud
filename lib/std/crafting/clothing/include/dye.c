#include <lib.h>
inherit LIB_PERSIST;

string* Colors = ({
  "black",
  "red",
  "green",
  "yellow",
  "blue",
  "purple",
  "cyan",
  "white",
  "brown",
  "indigo",
});

string CraftDye;

string SetDye(string dye) {return CraftDye = dye; }

string GetDye() {
  if (!CraftDye) {
    SetDye("brown");
  }
  return CraftDye;
}

string* GetColors() {
  return Colors;
}

int GetLegalColor(string color) {
  if (member_array(color, Colors) != -1) {
    return 1;
  }
  return 0;
}

static void create() {
  AddSave( ({ CraftDye }) );
}
