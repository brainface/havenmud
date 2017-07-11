#include <lib.h>
inherit LIB_ITEM;
inherit LIB_ENTER;

string Owner, Town;

string GetOwner() { return Owner; }

string SetOwner(string x) { 
  object ob;
  SetLong("This is an estate belonging to " + x + ", a wealthy local.");
  if (Town) {
    SetEnter("/domains/estates/virtual/main_estate/" + Town + "/" + x + "");
    if (ob = load_object("/domains/estates/virtual/main_estate/" + Town + "/" + x)) 
      ob->SetEstateExit(base_name(environment()));
  }
  return Owner = x; 
}

string SetTown(string x)  { return Town = x; }

string GetTown() { return Town; }

static void create() {
  item::create();
  enter::create();
  SetKeyName("estate");
  SetInvis(1);
  SetShort("an estate");
  SetLong("This is an estate belonging to a wealthy local.");
  SetNoClean(1);
  SetPreventGet("You can't lift an estate, hero.");
}

string GetAffectLong() {
  if (Owner)
    return "An estate belonging to " + Owner + " is here.";
  return "";
}
