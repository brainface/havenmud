#include <lib.h>
#include <domains.h>
#include <save.h>
inherit LIB_ROOM;
inherit LIB_PERSIST;

string ELong;  
string EShort;  
string Owner = 0;

string SetOwner(string);
void LoadEstate();

static void create(string town, string owner) {
  ::create();
  AddSave( ({ "ELong", "EShort", "Owner" }) );
  ELong  = "This is an empty, unfurnished keep. It is quite bare.";
  EShort = "inside an Estate";
  SetClimate("indoors");
  SetAmbientLight(35);
  SetTown(town);
  SetOwner(owner);
  LoadEstate();
  SetNoClean(1);
}

void SaveEstate() {
	// mahkefel2017--this was causing it to never save. I'm not sure what it 
	// is intended to do, it's a duuk question.
	// it's been failing since the lib update though.
	// 
	// "The driver sets the O_CLONE flag for those objects created by new()
	// it will return false when called on objects that are blueprint copy
	// (loaded by call_other or load_object()
	//
	//if (!clonep()) return;
	if (Owner == "" || Owner == 0) return;
	if (GetTown() == "Wilderness") return;
	if (file_size(SAVE_ESTATES + "/" + GetTown() + "/" ) != -2) {
		mkdir(SAVE_ESTATES + "/" + GetTown() + "/" );
	}
	SetItems( ([ ]) );
	save_object(SAVE_ESTATES + "/" + GetTown() + "/" + Owner + "_upper");
}

void LoadEstate() {
  if (Owner == "" || !Owner) { return; }
  if (GetTown() == "Wilderness") { return; }
  if (!file_exists(SAVE_ESTATES + "/" + GetTown() + "/" + Owner + "_upper" + ".o")) { return; }
  restore_object(SAVE_ESTATES + "/" + GetTown() + "/" + Owner + "_upper" ".o");
  if (ELong)  SetLong(ELong);
  if (EShort) SetShort(EShort);
  AddExit("south", "/domains/estates/virtual/main_estate/" + GetTown() + "/" + Owner);
  SetDoor("south", "/domains/estates/virtual/door/" + GetTown() + "/" + Owner);
  AddInventory("/domains/estates/virtual/boxes/" + GetTown() + "/" + Owner, 1);
}

string GetOwner() { return Owner; }

string SetOwner(string x) {
  Owner = x;
  LoadEstate();
  SaveEstate();
  return Owner;
}

string SetEstateLong(string x) { 
  ELong = x; 
  SaveEstate();
  LoadEstate();
  return ELong;  
}

string GetEstateLong() { return ELong; }

string SetEstateShort(string s) {
  EShort = s; 
  SaveEstate();
  LoadEstate();
  return EShort;  
}

string GetEstateShort() { return EShort; }

int is_estate() { return 1; }
