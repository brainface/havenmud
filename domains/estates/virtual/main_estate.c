#include <lib.h>
#include <domains.h>
#include <save.h>
inherit LIB_ROOM;
inherit LIB_PERSIST;

string ELong;  
string EShort; 
string EOut;   
string Owner = 0;

string SetOwner(string);
void LoadEstate();

static void create(string town, string owner) {
  ::create();
  AddSave( ({ "EOut", "ELong", "EShort", "Owner" }) );
  ELong  = "This is an empty, unfurnished keep. It is quite bare.";
  EShort = "inside an Estate";
  EOut   = "/domains/staff/room/setup";
  SetClimate("indoors");
  SetAmbientLight(35);
  SetTown(town);
  SetOwner(owner);
  LoadEstate();
  SetNoClean(1);
}

void SaveEstate() {
	/*if (!clonep()) {
		debug("!clonep");
		return;
	}*/
	if (Owner == "" || Owner == 0) {
		return;
	}
	if (GetTown() == "Wilderness") {
		return;
	}
	if (file_size(SAVE_ESTATES + "/" + GetTown() + "/" ) != -2) {
		mkdir(SAVE_ESTATES + "/" + GetTown() + "/" );
	}
    SetItems( ([ ]) );
	save_object(SAVE_ESTATES + "/" + GetTown() + "/" + Owner + "_main");
}

void LoadEstate() {
  if (Owner == "" || !Owner) { return; }
  if (GetTown() == "Wilderness") { return; }
  if (!file_exists(SAVE_ESTATES + "/" + GetTown() + "/" + Owner + "_main" + ".o")) { return; }
  restore_object(SAVE_ESTATES + "/" + GetTown() + "/" + Owner + "_main" + ".o");
  if (ELong)  SetLong(ELong);
  if (EShort) SetShort(EShort);
  if (EOut)   AddExit("out", EOut);
  AddExit("north", "/domains/estates/virtual/upper_estate/" + GetTown() + "/" + Owner);
  SetDoor("north", "/domains/estates/virtual/door/" + GetTown() + "/" + Owner);
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

string SetEstateExit(string x) {
  EOut = x; 
  SaveEstate();
  LoadEstate();
  return EOut;  
}

int is_estate() { return 1; }
